#include "Progress.h"


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

