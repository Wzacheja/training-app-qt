#ifndef SINGLECHOICEQUESTION_H
#define SINGLECHOICEQUESTION_H

#include "Question.h"

/**
 * @class SingleChoiceQuestion
 * @brief Reprezentuje pytanie jednokrotnego wyboru.
 *
 * Dziedziczy po klasie Question i umożliwia sprawdzenie
 * jednej odpowiedzi wskazanej przez użytkownika
 */
class SingleChoiceQuestion : public Question
{
public:
    /**
     * @brief Konstruktor klasy SingleChoiceQuestion
     * @param text Treść pytania
     * @param options Lista dostępnych opcji odpowiedzi
     */
    SingleChoiceQuestion(const std::string& text,
                         const std::vector<AnswerOption>& options);

    /**
     * @brief Sprawdza poprawność wybranej odpowiedzi
     * @param userAnswers Wektor odpowiedzi wybranych przez użytkownika
     * @return true jeśli odpowiedź jest poprawna, false jeśli nie
     */
    bool checkAnswer(const std::vector<int>& userAnswers) const override;
};

#endif // SINGLECHOICEQUESTION_H
