#include "SubTopic.h"


/**
 * @brief Konstruktor inicjalizujący podtemat
 */
SubTopic::SubTopic(const std::string& name, const Note& note) : name(name), note(note)
{

}


/**
 * @brief Zwraca nazwę podtematu
 */
std::string SubTopic::getName() const
{
    return name;
}


/**
 * @brief Zwraca listę materiałów szkoleniowych
 */
std::vector<TrainingMaterial> SubTopic::getMaterials() const
{
    return materials;
}


/**
 * @brief Zwraca listę pytań testowych
 */
std::vector<Question*> SubTopic::getQuestions() const
{
    return questions;
}


/**
 * @brief Zwraca notatkę przypisaną do podtematu
 */
Note SubTopic::getNote() const
{
    return note;
}


/**
 * @brief Dodaje materiał szkoleniowy do podtematu
 */
void SubTopic::addMaterial(const TrainingMaterial& material)
{
    materials.push_back(material);
}


/**
 * @brief Dodaje pytanie testowe do podtematu
 */
void SubTopic::addQuestion(Question* question)
{
    questions.push_back(question);
}


/**
 * @brief Ustawia nową notatkę dla podtematu
 */
void SubTopic::setNote(const Note& note)
{
    this->note = note;
}
