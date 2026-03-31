#include "SearchService.h"


/**
 * @brief Statyczna funkcja do normalizacji - jak ta TrainingMaterial
 * @param text Tekst do znormalizowania
 * @return Znormalizowany tekst
 */
static std::string normalize(const std::string& text)
{
    std::size_t start = 0;

    while (start < text.size() && std::isspace(static_cast<unsigned char>(text[start])))
    {
        start++;
    }

    if(start == text.size())
    {
        return "";
    }

    std::size_t end = text.size()-1;

    while (end > start && std::isspace(static_cast<unsigned char>(text[end])))
    {
        end--;
    }

    std::string normalizedText = text.substr(start,end-start+1);

    for(char& ch : normalizedText)
    {
        ch = static_cast<char>(std::toupper(static_cast<unsigned char>(ch)));
    }

    return normalizedText;
}


/**
 * @brief Wyszukuje materiały szkoleniowe zawierające podany tag
 */
std::vector<TrainingMaterial> SearchService::searchByTag(const std::vector<Chapter>& course,
                                          const std::string& tag) const
{
    std::vector<TrainingMaterial> searchResults;

    for (const Chapter& chapter : course)
    {
        for (const Topic& topic : chapter.getTopics())
        {
            for (const SubTopic& subtopic : topic.getSubTopics())
            {
                for (const TrainingMaterial& material : subtopic.getMaterials())
                {
                    if (material.hasTag(tag))
                    {
                        searchResults.push_back(material);
                    }
                }
            }
        }
    }

    return searchResults;
}


/**
 * @brief Zwraca listę wszystkich tagów występujących w kursie
 */
std::vector<std::string> SearchService::getAllTags(const std::vector<Chapter>& course) const
{
    std::vector<std::string> allTags;

    for (const Chapter& chapter : course)
    {
        for (const Topic& topic : chapter.getTopics())
        {
            for (const SubTopic& subtopic : topic.getSubTopics())
            {
                for (const TrainingMaterial& material : subtopic.getMaterials())
                {
                    for (const std::string& materialTag : material.getTags())
                    {
                        bool alreadyExists = false;

                        for (const std::string& savedTag : allTags)
                        {
                            if (normalize(savedTag) == normalize(materialTag))
                            {
                                alreadyExists = true;
                                break;
                            }
                        }

                        if (!alreadyExists)
                        {
                            allTags.push_back(materialTag);
                        }
                    }
                }
            }
        }
    }

    return allTags;
}
