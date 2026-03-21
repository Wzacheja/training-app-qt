#ifndef MULTIPLECHOICEQUESTION_H
#define MULTIPLECHOICEQUESTION_H

#include "Question.h"

/**
 * @class MultipleChoiceQuestion
 * @brief Reprezentuje pytanie wielokrotnego wyboru.
 *
 * Dziedziczy po klasie Question i umożliwia sprawdzenie
 * kilku odpowiedzi wskazanych przez użytkownika
 */
class MultipleChoiceQuestion : public Question
{
public:
    /**
     * @brief Konstruktor klasy MultipleChoiceQuestion
     * @param text Treść pytania
     * @param options Lista dostępnych opcji odpowiedzi
     */
    MultipleChoiceQuestion(const std::string& text,
                           const std::vector<AnswerOption>& options);

    /**
     * @brief Sprawdza poprawność wybranych odpowiedzi
     * @param userAnswers Wektor indeksów odpowiedzi wybranych przez użytkownika
     * @return true jeśli poprawna, false jeśli nie
     */
    bool checkAnswer(const std::vector<int>& userAnswers) const override;
};

#endif // MULTIPLECHOICEQUESTION_H
