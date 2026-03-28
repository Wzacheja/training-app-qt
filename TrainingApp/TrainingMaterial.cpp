#include "TrainingMaterial.h"


/**
 * @brief Konstruktor inicjalizujący materiał szkoleniowy
 */
TrainingMaterial::TrainingMaterial(const std::string& materialId,
                                   const std::string& title,
                                   const std::string& content,
                                   const std::vector<std::string>& tags)
    : materialId(materialId), title(title), content(content), tags(tags)
{

}


/**
 * @brief Zwraca ID materiału
 */
std::string TrainingMaterial::getMaterialId() const
{
    return materialId;
}


/**
 * @brief Zwraca tytuł materiału
 */
std::string TrainingMaterial::getTitle() const
{
    return title;
}


/**
 * @brief Zwraca treść materiału
 */
std::string TrainingMaterial::getContent() const
{
    return content;
}


/**
 * @brief Zwraca listę tagów powiązanych z materiałem
 */
std::vector<std::string> TrainingMaterial::getTags() const
{
    return tags;
}


/**
 * @brief Sprawdza czy materiał posiada podany tag
 */
bool TrainingMaterial::hasTag(const std::string& tag) const
{
    for (const std::string& currentTag : tags)
    {
        if (currentTag == tag)
        {
            return true;
        }
    }

    return false;
}


/**
 * @brief Dodaje nowy tag do materiału
 */
void TrainingMaterial::addTag(const std::string& tag)
{
    if (!hasTag(tag))
    {
        tags.push_back(tag);
    }

}
