#include "SingleChoiceQuestion.h"

/**
 * @brief Konstruktor inicjalizujący treść pytania i listę odpowiedzi
 */
SingleChoiceQuestion::SingleChoiceQuestion(
    const std::string& text,
    const std::vector<AnswerOption>& options) : Question(text)
{
    this->options = options;
}

/**
 * @brief Sprawdza poprawność odpowiedzi
 * @param userAnswers Odpowiedź użytkownika
 * @return true jeśli poprawna, false jeśli nie
 */
bool SingleChoiceQuestion::checkAnswer(const std::vector<int>& userAnswers) const
{
    if (userAnswers.size() != 1)
    {
        return false;
    }

    int userAnswer = userAnswers[0]; // pytanie jest jednokrotengo wyboru, więc nie korzystamy z listy

    if (userAnswer < 0 || userAnswer >= static_cast<int>(options.size()))
    {
        return false;
    }

    return options[userAnswer].getIsCorrect();
}
