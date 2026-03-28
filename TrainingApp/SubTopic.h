#ifndef SUBTOPIC_H
#define SUBTOPIC_H

#include <string>
#include <vector>

#include "TrainingMaterial.h"
#include "Question.h"
#include "Note.h"


/**
 * @class SubTopic
 * @brief Reprezentuje podtemat w rozdziale.
 *
 * Ułatwia nawigację po większych tematach
 * i stanowi bezpośredni kontener na materiały szkoleniowe.
 *
 * Klasa przechowuje nazwę podtematu, listę materiałów szkoleniowych,
 * listę pytań testowych i notatkę użytkownika do danego podtematu.
 */
class SubTopic
{
private:
    std::string name;
    std::vector<TrainingMaterial> materials;
    std::vector<Question*> questions;
    Note note;

public:
    /**
     * @brief Konstruktor klasy SubTopic
     * @param name Nazwa podtematu
     * @param note Notatka przypisana do podtematu
     */
    SubTopic(const std::string& name, const Note& note);


    /**
     * @brief Zwraca nazwę podtematu
     * @return Nazwa podtematu
     */
    std::string getName() const;


    /**
     * @brief Zwraca listę materiałów szkoleniowych
     * @return Wektor materiałów szkoleniowych
     */
    std::vector<TrainingMaterial> getMaterials() const;


    /**
     * @brief Zwraca listę pytań testowych
     * @return Wektor wskaźników na pytania
     */
    std::vector<Question*> getQuestions() const;


    /**
     * @brief Zwraca notatkę przypisaną do podtematu
     * @return Notatka użytkownika
     */
    Note getNote() const;


    /**
     * @brief Dodaje materiał szkoleniowy do podtematu
     * @param material Materiał do dodania
     */
    void addMaterial(const TrainingMaterial& material);


    /**
     * @brief Dodaje pytanie testowe do podtematu
     * @param question Wskaźnik na pytanie
     */
    void addQuestion(Question* question);


    /**
     * @brief Ustawia nową notatkę dla podtematu
     * @param note Nowa notatka
     */
    void setNote(const Note& note);
};

#endif // SUBTOPIC_H
