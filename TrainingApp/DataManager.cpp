#include "DataManager.h"

#include <QFile>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>

#include "SingleChoiceQuestion.h"
#include "MultipleChoiceQuestion.h"

/**
 * @brief Wczytuje materiały szkoleniowe z pliku JSON
 */
std::vector<TrainingMaterial> DataManager::loadTrainingMaterials(const std::string& filePath) const
{
    std::vector<TrainingMaterial> materials;

    QFile file(QString::fromStdString(filePath));

    if (!file.open(QIODevice::ReadOnly))
    {
        return materials;
    }

    QByteArray fileData = file.readAll();
    file.close();

    QJsonDocument jsonDocument = QJsonDocument::fromJson(fileData);

    if(!jsonDocument.isArray())
    {
        return materials;
    }

    QJsonArray materialsArray = jsonDocument.array();

    for (qsizetype i = 0; i < materialsArray.size(); i++)
    {
        QJsonValue value = materialsArray.at(i);

        if (!value.isObject())
        {
            continue;
        }

        QJsonObject object = value.toObject();

        std::string materialId = object["materialId"].toString().toStdString();
        std::string title = object["title"].toString().toStdString();
        std::string content = object["content"].toString().toStdString();

        std::vector<std::string> tags;
        QJsonArray tagsArray = object["tags"].toArray();

        for (qsizetype i = 0; i < tagsArray.size(); i++)
        {
            QJsonValue tagValue = tagsArray.at(i);
            tags.push_back(tagValue.toString().toStdString());
        }

        materials.push_back(TrainingMaterial(materialId, title, content, tags));
    }

    return materials;
}


/**
 * @brief Wczytuje strukturę kursu z pliku JSON
 */
std::vector<Chapter> DataManager::loadCourse(const std::string& filePath) const
{
    std::vector<Chapter> chapters;

    QFile file(QString::fromStdString(filePath));

    if (!file.open(QIODevice::ReadOnly))
    {
        return chapters;
    }

    QByteArray fileData = file.readAll();
    file.close();

    QJsonDocument jsonDocument = QJsonDocument::fromJson(fileData);

    if(!jsonDocument.isArray())
    {
        return chapters;
    }

    QJsonArray chaptersArray = jsonDocument.array();

    for (qsizetype i = 0; i < chaptersArray.size(); i++)
    {
        QJsonObject chapterObject = chaptersArray.at(i).toObject();

        int numberATA = chapterObject["numberATA"].toInt();
        std::string chapterName = chapterObject["name"].toString().toStdString();

        Chapter chapter(numberATA, chapterName);

        QJsonArray topicsArray = chapterObject["topics"].toArray();

        for (qsizetype j = 0; j < topicsArray.size(); j++)
        {
            QJsonObject topicObject = topicsArray.at(j).toObject();

            std::string topicName = topicObject["name"].toString().toStdString();
            std::string plannedCompletionDate = topicObject["plannedCompletionDate"].toString().toStdString();

            Topic topic(topicName, plannedCompletionDate);

            QJsonArray subTopicsArray = topicObject["subTopics"].toArray();

            for (qsizetype k = 0; k < subTopicsArray.size(); k++)
            {
                QJsonObject subTopicObject = subTopicsArray.at(k).toObject();

                std::string subTopicName = subTopicObject["name"].toString().toStdString();

                QJsonObject noteObject = subTopicObject["note"].toObject();
                std::string noteContent = noteObject["content"].toString().toStdString();
                std::string noteRelatedMaterialId = noteObject["relatedMaterialId"].toString().toStdString();

                Note note(noteContent,noteRelatedMaterialId);

                SubTopic subTopic(subTopicName, note);

                QJsonArray materialsArray = subTopicObject["materials"].toArray();

                for (qsizetype l = 0; l < materialsArray.size(); l++)
                {
                    QJsonObject materialObject = materialsArray.at(l).toObject();

                    std::string materialId = materialObject["materialId"].toString().toStdString();
                    std::string title = materialObject["title"].toString().toStdString();
                    std::string content = materialObject["content"].toString().toStdString();

                    std::vector<std::string> tags;
                    QJsonArray tagsArray = materialObject["tags"].toArray();

                    for (qsizetype m = 0; m < tagsArray.size(); m++)
                    {
                        QJsonValue tagValue = tagsArray.at(m);
                        tags.push_back(tagValue.toString().toStdString());
                    }

                    TrainingMaterial material(materialId, title, content, tags);

                    subTopic.addMaterial(material);
                }

                QJsonArray questionsArray = subTopicObject["questions"].toArray();

                for (qsizetype m = 0; m < questionsArray.size(); m++)
                {
                    QJsonObject questionObject = questionsArray.at(m).toObject();

                    std::string questionType = questionObject["type"].toString().toStdString();
                    std::string questionText = questionObject["text"].toString().toStdString();

                    std::vector<AnswerOption> options;
                    QJsonArray optionsArray = questionObject["options"].toArray();

                    for (qsizetype n = 0; n < optionsArray.size(); n++)
                    {
                        QJsonObject optionObject = optionsArray.at(n).toObject();

                        std::string optionText = optionObject["text"].toString().toStdString();
                        bool isCorrect = optionObject["isCorrect"].toBool();

                        AnswerOption option (optionText,isCorrect);
                        options.push_back(option);
                    }

                    if (questionType == "single")
                    {
                        subTopic.addQuestion(new SingleChoiceQuestion(questionText, options));
                    }
                    else if (questionType == "multiple")
                    {
                        subTopic.addQuestion(new MultipleChoiceQuestion(questionText, options));
                    }
                }
                topic.addSubTopic(subTopic);
            }
            chapter.addTopic(topic);
        }
        chapters.push_back(chapter);
    }

    return chapters;
}
