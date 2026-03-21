#ifndef ANSWEROPTION_H
#define ANSWEROPTION_H

#include <string>

/**
 * @class AnswerOption
 * @brief Reprezentuje pojedynczą opcje odpoiwedzi w pytaniu.
 *
 * Przechwuje treść odpowiedzi i informację czy jest poprawna.
 */
class AnswerOption
{
private:
    std::string text;
    bool isCorrect;

public:
    /**
     * @brief Konstruktor klasy AnswerOption
     * @param text Treść odpowiedzi
     * @param isCorrect Czy odpowiedź jest poprawna
     */
    AnswerOption(const std::string& text, bool isCorrect);

    /**
     * @brief Zwraca treść odpowiedzi
     * @return Treść odpowiedzi
     */
    std::string getText() const;

    /**
     * @brief Zwraca informację czy odpowiedź jest poprawna
     * @return true jeśli odpowiedź poprawna, false jeśli nie
     */
    bool getIsCorrect() const;
};

#endif // ANSWEROPTION_H
