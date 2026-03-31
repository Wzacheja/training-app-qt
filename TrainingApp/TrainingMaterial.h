#ifndef TRAININGMATERIAL_H
#define TRAININGMATERIAL_H

#include <string>
#include <vector>


/**
 * @class TrainingMaterial
 * @brief Reprezentuje pojedynczy materiał szkoleniowy.
 *
 * Klasa przechowuje identyfikator, tytuł, treść i tagi materiału szkoleniowego.
 */
class TrainingMaterial
{
private:
    std::string materialId;
    std::string title;
    std::string content;
    std::vector<std::string> tags;


    /**
     * @brief Normalizuje tekst - wycina białe znaki z początku i końca tekstu,
     * oraz zmienia wszystkie litery na WIELKIE.
     * @param text Tekst do znormalizowania
     * @return Znormalizowany teskt
     */
    std::string normalize(const std::string& text) const;

public:
    /**
     * @brief Konstruktor klasy TrainingMaterial
     * @param materialId Identyfikator materiału
     * @param title Tytuł materiału
     * @param content Treść materiału
     * @param tags Lista tagów przypisanych do materiału
     */
    TrainingMaterial(const std::string& materialId,
                     const std::string& title,
                     const std::string& content,
                     const std::vector<std::string>& tags);


    /**
     * @brief Zwraca identyfikator materiału
     * @return ID materiału
     */
    std::string getMaterialId() const;


    /**
     * @brief Zwraca tytuł materiału
     * @return Tytuł materiału
     */
    std::string getTitle() const;


    /**
     * @brief Zwraca treść materiału
     * @return Treść materiału
     */
    std::string getContent() const;


    /**
     * @brief Zwraca listę tagów
     * @return Lista tagów
     */
    std::vector<std::string> getTags() const;


    /**
     * @brief Sprawdza, czy materiał posiada podany tag
     * @param tag Szukany tag
     * @return true jeśli tag istnieje, false jeśli nie
     */
    bool hasTag(const std::string& tag) const;


    /**
     * @brief Dodaje tag do materiału
     * @param tag Tag do dodania
     */
    void addTag(const std::string& tag);
};

#endif // TRAININGMATERIAL_H
