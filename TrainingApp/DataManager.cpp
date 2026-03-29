#include "DataManager.h"

#include <QFile>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>


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
