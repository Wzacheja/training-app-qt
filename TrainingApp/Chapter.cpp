#include "Chapter.h"

/**
 * @brief Konstruktor inicjalizujący rozdział
 */
Chapter::Chapter(int numberATA, const std::string& name) : numberATA(numberATA), name(name)
{

}


/**
 * @brief Zwraca numer ATA rozdziału
 */
int Chapter::getNumberATA() const
{
    return numberATA;
}


/**
 * @brief Zwraca nazwę rozdziału
 */
std::string Chapter::getName() const
{
    return name;
}


/**
 * @brief Zwraca listę tematów w rozdziale
 */
std::vector<Topic> Chapter::getTopics() const
{
    return topics;
}


/**
 * @brief Dodaje temat do rozdziału
 */
void Chapter::addTopic(const Topic& topic)
{
    topics.push_back(topic);
}
