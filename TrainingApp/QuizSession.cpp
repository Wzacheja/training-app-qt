#include "QuizSession.h"


/**
 * @brief Konstruktor inicjalizujący sesję quizu
 */
QuizSession::QuizSession() : score(0)
{

}


/**
 * @brief Zwraca listę pytań użytych w sesji quizu
 */
std::vector<Question*> QuizSession::getQuestions() const
{
    return questions;
}


/**
 * @brief Zwraca wynik quizu
 */
int QuizSession::getScore() const
{
    return score;
}


/**
 * @brief Zwraca liczbę pytań w sesji quizu
 */
int QuizSession::getQuestionCount() const
{
    return static_cast<int>(questions.size());
}


/**
 * @brief Dodaje pytanie do quizu
 */
void QuizSession::addQuestion(Question* question)
{
    questions.push_back(question);
    userAnswers.push_back({});
}


/**
 * @brief Zapisuje odpowiedź użytkownika dla pytania o podanym indeksie
 */
void QuizSession::answerQuestion(int questionIndex, const std::vector<int>& answers)
{
    if (questionIndex >= 0 && questionIndex < static_cast<int>(userAnswers.size()))
    {
        userAnswers[questionIndex] = answers;
    }
}


/**
 * @brief Oblicza wynik quizu
 */
void QuizSession::calculateScore()
{
    score = 0;

    for (int i = 0; i < static_cast<int>(questions.size()); i++)
    {
        if (questions[i]->checkAnswer(userAnswers[i]))
        {
            score++;
        }
    }
}


double QuizSession::getPercentageScore() const
{
    if (questions.empty())
    {
        return 0.0;
    }

    return (static_cast<double>(score) / static_cast<double>(questions.size())) * 100.0;
}
