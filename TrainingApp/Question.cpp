#include "Question.h"

/**
 * @brief Konstruktor inicjalizujący pytanie
 */
Question::Question(const std::string& text) : text(text) {}

/**
 * @brief Zwraca treść pytania
 */
std::string Question::getText() const
{
    return text;
}

/**
 * @brief Zwraca listę dostępnych odpowiedzi
 */
std::vector<AnswerOption> Question::getOptions() const
{
    return options;
}
