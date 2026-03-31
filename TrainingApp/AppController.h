#ifndef APPCONTROLLER_H
#define APPCONTROLLER_H


#include <string>
#include <vector>


#include "Progress.h"
#include "DataManager.h"
#include "QuizSession.h"
#include "Chapter.h"
#include "SubTopic.h"
#include "SearchService.h"


/**
 * @class AppController
 * @brief Reprezentuje główną klasę sterującą logiką i łącząca ją z GUI.
 *
 * Klasa odpowiada za zarządzanie strukturą kursu,
 * postępem użytkownika oraz bieżącą sesją quizu.
 * Umożliwia także komunikację między logiką aplikacji,
 * a interfejsem użytkownika.
 */
class AppController
{
private:
    DataManager dataManager;
    Progress progress;
    QuizSession quizSession;
    std::vector<Chapter> course;

    SearchService searchService;

public:
    /**
     * @brief Zwraca strukturę kursu
     * @return Wektor rozdziałów
     */
    std::vector<Chapter> getCourse() const;

    /**
     * @brief Zwraca postęp użytkownika
     * @return Obiekt klassy Progress
     */
    Progress getProgress() const;


    /**
     * @brief Rozpoczyna sesję quizu dla wskazanego podtematu
     * @param subTopic Podtemat z którego pobierane są pytania
     */
    void startQuiz(const SubTopic& subTopic);


    /**
     * @brief Zapisuje odpowiedzi użytkownika na dane pytanie
     * @param questionIndex Indeks pytania
     * @param answers Wektor odpowiedzi użytkownika
     */
    void answerCurrentQuestion(int questionIndex, const std::vector<int>& answers);


    /**
     * @brief Kończy sesję quizu - zapisuje wynik i błędnie zaznaczone pytania
     */
    void finishQuiz();


    /**
     * @brief Oznacza podtemat jako przeczytany
     * @param subTopicName Nazwa podtematu
     */
    void markSubTopicCompleted(const std::string& subTopicName);


    /**
     * @brief Wczytywanie kursu
     * @param filePath Ścieżka do pliku JSON
     * @return true jeśli udało się wczytać, false jeśli nie
     */
    bool loadCourse(const std::string& filePath);


    /**
     * @brief Wczytywanie postępu użytkownika
     * @param filePath Ścieżka do pliku JSON
     * @return true jeśli udało się wczytać, false jeśli nie
     */
    bool loadProgress(const std::string& filePath);


    /**
     * @brief Zapisywanie postępu użytkownika
     * @param filePath Ścieżka do pliku JSON
     * @return true jeśli udało się zapisać, false jeśli nie
     */
    bool saveProgress(const std::string& filePath);

    /**
    * @brief Wyszukuje materiały szkoleniowe zawierające podany tag
    * @param tag Szukany tag
    * @return Wektor znalezionych materiałów szkoleniowych
    */
    std::vector<TrainingMaterial> searchByTag(const std::string& tag) const;


    /**
     * @brief Zwraca listę wszystkich tagów występujących w kursie
     * @return Wektor wszystkich tagów
     */
    std::vector<std::string> getAllTags() const;

};

#endif // APPCONTROLLER_H
