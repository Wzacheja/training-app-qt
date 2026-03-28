#include "Topic.h"


/**
 * @brief Konstruktor inicjalizujący temat
 */
Topic::Topic(const std::string& name, const std::string& plannedCompletionDate)
    : name(name), plannedCompletionDate(plannedCompletionDate)
{

}


/**
 * @brief Zwraca nazwę tematu
 */
std::string Topic::getName() const
{
    return name;
}


/**
 * @brief Zwraca listę podtematów
 */
std::vector<SubTopic> Topic::getSubTopics() const
{
    return subTopics;
}


/**
 * @brief Zwraca planowaną datę ukończenia
 */
std::string Topic::getPlannedCompletionDate() const
{
    return plannedCompletionDate;
}


/**
 * @brief Dodaje podtemat do tematu
 */
void Topic::addSubTopic(const SubTopic& subTopic)
{
    subTopics.push_back(subTopic);
}


/**
 * @brief Ustawia planowaną datę ukończenia
 */
void Topic::setPlannedCompletionDate(const std::string& date)
{
    plannedCompletionDate = date;
}
