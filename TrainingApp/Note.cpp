#include "Note.h"

/**
 * @brief Konstruktor inicjalizujący notatkę
 */
Note::Note(const std::string& content, const std::string& materialId)
    : content(content), materialId(materialId)
{

}

/**
 * @brief Ustawia treść notatki
 */
void Note::setContent(const std::string& content)
{
    this->content = content;
}

/**
 * @brief Zwraca treść notatki
 */
std::string Note::getContent() const
{
    return content;
}

/**
 * @brief Zwraca ID materiału
 */
std::string Note::getMaterialId() const
{
    return materialId;
}
