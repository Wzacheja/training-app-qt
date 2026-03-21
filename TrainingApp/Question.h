#ifndef QUESTION_H
#define QUESTION_H

#include <string>
#include <vector>
#include "AnswerOption.h"


/**
 * @class Question
 * @brief Abstrakcyjna klasa bazowa dla wszystkich typów pytań.
 *
 * Przechowuje treść pytania, listę możliwych odpowiedzi oraz
 * wspólny interfejs do sprawdzenia poprawności odpowiedzi.
 */
class Question
{
protected:
    std::string text;
    std::vector<AnswerOption> options;

public:
    /**
     * @brief Konstruktor klasy Question
     * @param text Treść pytania
     */
    Question(const std::string& text);

    /**
     * @brief Wirtualny destruktor.
     */
    virtual ~Question() = default;

    /**
     * @brief Zwraca treść pytania
     * @return Treść pytania
     */
    std::string getText() const;

    /**
     * @brief Zwraca listę dostępnych opcji odpowiedzi na pytanie
     * @return Wektor opcji odpowiedzi
     */
    std::vector<AnswerOption> getOptions() const;

    /**
     * @brief Sprawdza poprawność odpowiedzi użytkownika
     * @param userAnswers Wektor indeksów odpowiedzi wybranych przez użytkownika
     * @return true jeśli poprawna, false jeśli nie
     */
    virtual bool checkAnswer(const std::vector<int>& userAnswers) const = 0;
};

#endif // QUESTION_H
