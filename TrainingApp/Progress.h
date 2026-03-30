#ifndef PROGRESS_H
#define PROGRESS_H

#include <string>
#include <vector>


/**
 * @class Progress
 * @brief Reprezentuje postęp użytkownika i jego wyniki.
 *
 * Klasa przechowuje informację o ukończonych podtematach,
 * wynikach testów i błędnie rozwiązanych pytaniach.
 *
 * Klasa pozwala wczytać postęp z pliku JSON oraz
 * zapisać go do pliku JSON.
 */
class Progress
{
private:
    std::vector<std::string> completedSubTopics;
    std::vector<double> testResults;
    std::vector<std::string> incorrectQuestionIDs;

public:
    /**
     * @brief Konstruktor domyślny klasy Progress
     */
    Progress() = default;


    /**
     * @brief Zwraca listę ukończonych podtematów
     * @return Wektor ukończonych podtematów
     */
    std::vector<std::string> getCompletedSubTopics() const;


    /**
     * @brief Zwraca listę wyników testów
     * @return Wektor wyników testów
     */
    std::vector<double> getTestResults() const;


    /**
     * @brief Zwraca listę błędnie rozwiązanych pytań
     * @return Wektor identyfikatorów błędnych pytań
     */
    std::vector<std::string> getIncorrectQuestionIDs() const;


    /**
     * @brief Oznacza podtemat jako ukończony
     * @param subTopicName Nazwa ukończonego podtematu
     */
    void markSubTopicCompleted(const std::string& subTopicName);


    /**
     * @brief Dodaje wynik testu
     * @param result Wynik testu
     */
    void addTestResult(double result);


    /**
     * @brief Dodaje identyfikator błędnie rozwiązanego pytania
     * @param questionID Identyfikator błędnego pytania
     */
    void addIncorrectQuestion(const std::string& questionID);


    /**
     * @brief Wczytuje progress z pliku JSON
     * @param filePath Ścieżka do pliku JSON
     * @return true jeśli udało się wczytać dane, false jeśli nie
     */
    bool loadFromFile(const std::string& filePath);


    /**
     * @brief Zapisuje progress do pliku JSON
     * @param filePath Ścieżka do pliku JSON
     * @return true jeśli udało się zapisać dane, false jeśli nie
     */
    bool saveToFile(const std::string& filePath);
};

#endif // PROGRESS_H
