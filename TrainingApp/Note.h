#ifndef NOTE_H
#define NOTE_H

#include <string>


/**
 * @class Note
 * @brief Reprezentuje notatkę napisaną przez użytkownika
 *
 * Klasa przechowuje treść notatki oraz identyfikator materiału
 * do którego jest przypisana, aby można było wrócić do notatki.
 */
class Note
{
private:
    std::string content;
    std::string materialId;

public:
    /**
     * @brief Konstruktor klasy Note
     * @param content Treść notatki
     * @param materialId ID materiału
     */
    Note(const std::string& content, const std::string& materialId);


    /**
     * @brief Ustawia treść notatki
     * @param content Nowa treść notatki
     */
    void setContent(const std::string& content);


    /**
     * @brief Zwraca treść notatki
     * @return Treść notatki
     */
    std::string getContent() const;


    /**
     * @brief Zwraca ID materiału
     * @return ID materiału
     */
    std::string getMaterialId() const;
};

#endif // NOTE_H
