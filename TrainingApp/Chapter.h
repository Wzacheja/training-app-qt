#ifndef CHAPTER_H
#define CHAPTER_H

#include <string>
#include <vector>

#include "Topic.h"


/**
 * @class Chapter
 * @brief Reprezentuje rozdział materiału szkoleniowego wg. ATA-100.
 *
 * Klasa porządkuje strukturę szkolenia i przechowuje
 * numer ATA i nazwę rozdziału
 * oraz listę tematów przypisanych do rozdziału.
 */
class Chapter
{
private:
    int numberATA;
    std::string name;
    std::vector<Topic> topics;

public:
    /**
     * @brief Konstruktor klasy Chapter
     * @param numberATA Numer rozdziału ATA
     * @param name Nazwa rozdziału
     */
    Chapter(int numberATA, const std::string& name);


    /**
     * @brief Zwraca numer ATA rozdziału
     * @return Numer ATA
     */
    int getNumberATA() const;


    /**
     * @brief Zwraca nazwę rozdziału
     * @return Nazwa rozdziału
     */
    std::string getName() const;


    /**
     * @brief Zwraca listę tematów w rozdziale
     * @return Wektor tematów
     */
    std::vector<Topic> getTopics() const;


    /**
     * @brief Dodaje temat do rozdziału
     * @param topic Temat do dodania
     */
    void addTopic(const Topic& topic);

};

#endif // CHAPTER_H
