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
 * @brief Normalizuje tekst - wycina spacje i entery przed oraz za tekstem,
 * a oprócz tego zmienia wszystkie litery na DUŻE.
*/
std::string TrainingMaterial::normalize(const std::string& text) const
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
        if (normalize(currentTag) == normalize(tag) && normalize(tag) != "")
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
