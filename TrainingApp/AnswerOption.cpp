#include "AnswerOption.h"

/**
 * @brief Konstruktor inicjalizujący pola klasy.
 */
AnswerOption::AnswerOption(const std::string& text, bool isCorrect) : text(text), isCorrect(isCorrect){}

/**
 * @brief Zwraca treść odpowiedzi
 */
std::string AnswerOption::getText() const
{
    return text;
}

/**
 * @brief Zwraca informację czy odpowiedź jest poprawna
 */
bool AnswerOption::getIsCorrect() const
{
    return isCorrect;
}
