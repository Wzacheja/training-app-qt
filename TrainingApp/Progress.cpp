#include "Progress.h"

#include <QFile>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QDir>
#include <QFileInfo>


/**
 * @brief Zwraca listę ukończonych podtematów
 */
std::vector<std::string> Progress::getCompletedSubTopics() const
{
    return completedSubTopics;
}


/**
 * @brief Zwraca listę wyników testów
 */
std::vector<double> Progress::getTestResults() const
{
    return testResults;
}


/**
 * @brief Zwraca listę błędnie rozwiązanych pytań
 */
std::vector<std::string> Progress::getIncorrectQuestionIDs() const
{
    return incorrectQuestionIDs;
}


/**
 * @brief Oznacza temat jako ukończony
 */
void Progress::markSubTopicCompleted(const std::string& subTopicName)
{
    completedSubTopics.push_back(subTopicName);
}


/**
 * @brief Dodaje wynik testu
 */
void Progress::addTestResult(double result)
{
    testResults.push_back(result);
}


/**
 * @brief Dodaje identyfikator błędnie rozwiązanego pytania
 */
void Progress::addIncorrectQuestion(const std::string& questionID)
{
    incorrectQuestionIDs.push_back(questionID);
}


/**
 * @brief Wczytuje progress z pliku JSON
 */
bool Progress::loadFromFile(const std::string& filePath)
{
    QFileInfo fileInfo(QString::fromStdString(filePath));
    QDir().mkpath(fileInfo.path());

    QFile file(QString::fromStdString(filePath));

    if (!file.open(QIODevice::ReadOnly))
    {
        return false;
    }

    QByteArray fileData = file.readAll();
    file.close();

    QJsonDocument jsonDoc = QJsonDocument::fromJson(fileData);

    if(!jsonDoc.isObject())
    {
        return false;
    }

    QJsonObject prog = jsonDoc.object();

    completedSubTopics.clear();
    testResults.clear();
    incorrectQuestionIDs.clear();

    QJsonArray completedArray = prog["completedSubTopics"].toArray();
    for (const QJsonValue& complete : completedArray)
    {
        completedSubTopics.push_back(complete.toString().toStdString());
    }

    QJsonArray resultsArray = prog["testResults"].toArray();
    for (const QJsonValue& res : resultsArray)
    {
        testResults.push_back(res.toDouble());
    }

    QJsonArray incorretArray = prog["incorrectQuestions"].toArray();
    for (const QJsonValue& questionId : incorretArray)
    {
        incorrectQuestionIDs.push_back(questionId.toString().toStdString());
    }

    return true;
}


/**
 * @brief Zapisuje progress do pliku JSON
 */
bool Progress::saveToFile(const std::string& filePath)
{
    QFile file(QString::fromStdString(filePath));

    if (!file.open(QIODevice::WriteOnly))
    {
        return false;
    }

    QJsonObject prog;

    QJsonArray completedArray;
    for (const std::string& subTop : completedSubTopics)
    {
        completedArray.append(QString::fromStdString(subTop));
    }
    prog["completedSubTopics"] = completedArray;

    QJsonArray resultsArray;
    for (const double& res : testResults)
    {
        resultsArray.append(res);
    }
    prog["testResults"] = resultsArray;

    QJsonArray incorretArray;
    for (const std::string& qId : incorrectQuestionIDs)
    {
        incorretArray.append(QString::fromStdString(qId));
    }
    prog["incorrectQuestions"] = incorretArray;

    QJsonDocument doc(prog);
    file.write(doc.toJson());

    file.close();

    return true;
}
