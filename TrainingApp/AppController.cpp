#include "AppController.h"


/**
 * @brief Zwraca strukturę kursu
 */
std::vector<Chapter> AppController::getCourse() const
{
    return course;
}


/**
 * @brief Zwraca postęp użytkownika
 */
Progress AppController::getProgress() const
{
    return progress;
}


/**
 * @brief Rozpoczyna sesję quizu dla wskazanego podtematu
 */
void AppController::startQuiz(const SubTopic& subTopic)
{
    quizSession = QuizSession();

    for (Question* question : subTopic.getQuestions())
    {
        quizSession.addQuestion(question);
    }
}


/**
 * @brief Zapisuje odpowiedzi użytkownika na dane pytanie
 */
void AppController::answerCurrentQuestion(int questionIndex, const std::vector<int>& answers)
{
    quizSession.answerQuestion(questionIndex,answers);
}


/**
 * @brief Kończy sesję quizu
 */
void AppController::finishQuiz()
{
    quizSession.calculateScore();
    progress.addTestResult(quizSession.getPercentageScore());
}


/**
 * @brief Oznacza podtemat jako przeczytany
 */
void AppController::markSubTopicCompleted(const std::string& subTopicName)
{
    progress.markSubTopicCompleted(subTopicName);
}


/**
 * @brief Wczytywanie kursu
 */
bool AppController::loadCourse(const std::string& filePath)
{
    course = dataManager.loadCourse(filePath);
    return !course.empty();
}


/**
 * @brief Wczytywanie postępu użytkownika
 */
bool AppController::loadProgress(const std::string& filePath)
{
    return progress.loadFromFile(filePath);
}


/**
 * @brief Zapisywanie postępu użytkownika
 */
bool AppController::saveProgress(const std::string& filePath)
{
    return progress.saveToFile(filePath);
}


/**
 * @brief Wyszukuje materiały szkoleniowe zawierające podany tag
 */
std::vector<TrainingMaterial> AppController::searchByTag(const std::string& tag) const
{
    return searchService.searchByTag(course, tag);
}


/**
 * @brief Zwraca listę wszystkich tagów występujących w kursie
 */
std::vector<std::string> AppController::getAllTags() const
{
    return searchService.getAllTags(course);
}
