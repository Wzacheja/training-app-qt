#ifndef QUIZSESSION_H
#define QUIZSESSION_H

#include <vector>

#include "Question.h"


/**
 * @class QuizSession
 * @brief Reprezentuje pojedynczą sesję testową
 * przechowuje pytania użyte w sesji quizu, odpowiedzi użytkownika
 * i umożliwia obliczenie wyniku końcowego w formacie
 * x/y lub procentowym
 */
class QuizSession
{
private:
    std::vector<Question*> questions;
    std::vector<std::vector<int>> userAnswers;
    int score;

public:
    /**
     * @brief Konstruktor domyślny klasy QuizSession
     */
    QuizSession();


    /**
     * @brief Zwraca listę pytań użytych w sesji quizu
     * @return Wektor wskaźników na pytania
     */
    std::vector<Question*> getQuestions() const;


    /**
     * @brief Zwraca wynik quizu
     * @return Liczba poprawnych odpowiedzi
     */
    int getScore() const;


    /**
     * @brief Zwraca liczbę pytań w sesji quizu
     * @return Liczba pytań
     */
    int getQuestionCount() const;


    /**
     * @brief Dodaje pytanie do sesji quizu
     * @param question Wskaźnik na pytanie
     */
    void addQuestion(Question* question);


    /**
     * @brief Zapisuje odpowiedź użytkownika dla pytania o podanym indeksie
     * @param questionIndex Indeks pytania
     * @param answers Wektor indeksów odpowiedzi użytkownika
     */
    void answerQuestion(int questionIndex, const std::vector<int>& answers);


    /**
     * @brief Oblicza wynik quizu
     */
    void calculateScore();


    /**
     * @brief Zwraca wynik procentowy
     * @return Wynik procentowy w zakresie 0-100%
     */
    double getPercentageScore() const;

};

#endif // QUIZSESSION_H
