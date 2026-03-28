#ifndef TOPIC_H
#define TOPIC_H

#include <string>
#include <vector>

#include "SubTopic.h"


/**
 * @class Topic
 * @brief Reprezentuje temat w rozdziale.
 *
 * Przechowuje nazwę tematu, listę podtematów
 * i planowaną datę ukończenia tematu.
 */
class Topic
{
private:
    std::string name;
    std::vector<SubTopic> subTopics;
    std::string plannedCompletionDate;

public:
    /**
     * @brief Konstruktor klasy Topic
     * @param name Nazwa tematu
     * @param plannedCompletionDate Planowana data ukończenia tematu
     */
    Topic(const std::string& name, const std::string& plannedCompletionDate);


    /**
     * @brief Zwraca nazwę tematu
     * @return Nazwa tematu
     */
    std::string getName() const;


    /**
     * @brief Zwraca listę podtematów
     * @return Wektor podtematów
     */
    std::vector<SubTopic> getSubTopics() const;


    /**
     * @brief Zwraca planowaną datę ukończenia
     * @return Planowana data ukończenia
     */
    std::string getPlannedCompletionDate() const;


    /**
     * @brief Dodaje podtemat do tematu
     * @param subTopic Podtemat do dodania
     */
    void addSubTopic(const SubTopic& subTopic);


    /**
     * @brief Ustawia planowaną datę ukończenia
     * @param date Nowa planowana data ukończenia
     */
    void setPlannedCompletionDate(const std::string& date);
};

#endif // TOPIC_H
