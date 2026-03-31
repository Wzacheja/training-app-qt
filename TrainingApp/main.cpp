#include "mainwindow.h"
#include <QApplication>

#include "AppController.h"
#include "SearchService.h"
#include "TrainingMaterial.h"

/*
#include "Progress.h"
#include "TrainingMaterial.h"
#include "DataManager.h"
#include "QuizSession.h"
#include "Chapter.h"
#include "Topic.h"
#include "SubTopic.h"
#include "TrainingMaterial.h"
#include "Note.h"
#include "MultipleChoiceQuestion.h"
#include "SingleChoiceQuestion.h"
*/


#include <iostream>
#include <iomanip>


/*
void runQuizFromSubTopic(const SubTopic& subTopic)
{
    // Quiz session
    QuizSession qSession;

    for (Question* q : subTopic.getQuestions())
    {
        qSession.addQuestion(q);
    }

    std::cout << "\n   QUIZ SESSION\n\n";
    std::cout << "Number of questions: " << qSession.getQuestionCount() << "\n";

    int index = 0;

    for (Question* q : subTopic.getQuestions())
    {
        std::cout << "\nQuestion: " << q->getText();

        const std::vector<AnswerOption> options = q->getOptions();

        for (size_t i = 0; i < options.size(); i++)
        {
            std::cout << "\n\t" << i << " - " << options[i].getText();
        }

        std::vector<int> userAnswer = {0}; //poprawna
        //std::vector<int> userAnswer = {1}; //niepoprawna

        qSession.answerQuestion(index,userAnswer);
        index++;
    }

    qSession.calculateScore();

    std::cout << "\nScore: " << qSession.getScore() << "/" << qSession.getQuestionCount() <<
        "\t" << qSession.getPercentageScore() << "%\n";
}
*/


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    std::cout << std::fixed << std::setprecision(2);


    // Test kontrolera aplikacji i wyszukiwarki

    AppController controler;

    controler.loadCourse("data/course_struct+questions.json");
    controler.loadProgress("user_data/progress.json");

    std::vector<Chapter> course = controler.getCourse();

    // Test wywołania QuizSession z poziomu AppControlera
    if (!course.empty())
    {
        const SubTopic& subTop = course[0].getTopics()[0].getSubTopics()[0];

        controler.startQuiz(subTop);
        controler.answerCurrentQuestion(0, {0});
        controler.finishQuiz();
        controler.markSubTopicCompleted(subTop.getName());

        if (controler.saveProgress("user_data/progress.json"))
        {
            std::cout << "\n\nCOURSE PROGRESS SAVED";
        }
    }

    // Test wyszukiwarki - wywołany z poziomu AppControllera

    std::vector<std::string> allTags = controler.getAllTags();

    if (allTags.empty())
    {
        std::cout << "\n\nNo tags were included in course";
    }
    else
    {
        std::cout << "\n\nAvailable tags in course:";
        for (std::string& tag : allTags)
        {
            std::cout << "\n\t" << tag;
        }
        std::cout << "\n\n";
    }

    std::string tagToFind = "     FCND "; // tag do znalezienia

    std::vector<TrainingMaterial> search = controler.searchByTag(tagToFind);

    std::cout << "\n\nTag to find: " << tagToFind
              << "\nSearch results:";
    for (const TrainingMaterial& material : search)
    {
        std::cout << "\n\t" << material.getMaterialId() << " - " << material.getTitle();
    }

    std::cout << "\n\n";

/*
    // Test odczytu i zapisu progressu

    Progress prog;

    // Odczyt

    prog.loadFromFile("user_data/progress.json");

    std::cout << "\nLoaded progress:";
    std::cout << "\n\tCompleted topics: ";
    for (const std::string& topic : prog.getCompletedSubTopics())
    {
        std::cout << "\n\t\t" << topic;
    }

    std::cout << "\n\tTests results: ";
    for (const double result : prog.getTestResults())
    {
        std::cout << "\n\t\t" << result;
    }

    std::cout << "\n\tIncorrect questions IDs: ";
    for (const std::string& qId : prog.getIncorrectQuestionIDs())
    {
        std::cout << "\n\t\t" << qId;
    }

    // Zmiana progresu

    prog.markSubTopicCompleted("Added SubTopic to Prog");
    prog.addTestResult(33.33);
    prog.addIncorrectQuestion("Q99");

    // Zapis

    if(prog.saveToFile("user_data/progress.json"))
    {
        std::cout << "\n\nProgress saved";
    }

    std::cout << "\n\n";
*/
/*
    // Test wczytywania struktury kursu

    DataManager dataManager;
    std::vector<Chapter> loadedCourse =
        dataManager.loadCourse("data/course_struct+questions.json");

    std::cout << "Loaded chapters: " << loadedCourse.size();

    for (const Chapter& chapter : loadedCourse)
    {
        std::cout << "\n\nChapter ATA: " << chapter.getNumberATA() << " - " << chapter.getName();

        for (const Topic& topic : chapter.getTopics())
        {
            std::cout << "\n\tTopic: " << topic.getName()
                      << " (deadline: " << topic.getPlannedCompletionDate() << ")";

            for (const SubTopic& subTopic : topic.getSubTopics())
            {
                std::cout << "\n\t\tSubTopic: " << subTopic.getName();

                for (const TrainingMaterial& material : subTopic.getMaterials())
                {
                    std::cout << "\n\t\t\tTraining material ID: " << material.getMaterialId()
                              << "\n\t\t\tTitle: " << material.getTitle()
                              << "\n\t\t\tContent: " << material.getContent()
                              << "\n\t\t\tTags: ";

                    for (const std::string& tag : material.getTags())
                    {
                        std::cout << tag << ", ";
                    }
                    std::cout << "\n";
                }

                std::cout << "\n\t\tNote: " << subTopic.getNote().getContent() << "\n";

                std::cout << "\n\t\tQuestions: ";

                if (subTopic.getQuestions().empty())
                {
                    std::cout << "\n\t\t\tNo questions available";
                }
                else
                {
                    for (const Question* question : subTopic.getQuestions())
                    {
                        std::cout << "\n\t\t\tQuestion: " << question->getText();

                        const std::vector<AnswerOption> options = question->getOptions();

                        for (size_t i = 0; i < options.size(); i++)
                        {
                            std::cout << "\n\t\t\t\t" << i << " - " << options[i].getText();
                        }

                        for (size_t j = 0; j < options.size(); j++)
                        {
                            if (options[j].getIsCorrect())
                            {
                                std::cout << "\n\t\t\tCorrect: " << j << " - " << options[j].getText();
                            }
                        }
                        std::cout <<"\n";
                    }
                    std::cout <<"\n";
                }
                std::cout <<"\n";
            }
            std::cout << "\n";
        }
        std::cout << "\n";
    }

    std::cout << "\n\n";

    if (!loadedCourse.empty())
    {
        const SubTopic& sub = loadedCourse[0].getTopics()[0].getSubTopics()[0];

        runQuizFromSubTopic(sub);
    }
*/
/*
    // Test wczytywania materiału szkoleniowego

    DataManager dataManager;
    std::vector<TrainingMaterial> loadedMaterials =
        dataManager.loadTrainingMaterials("data/material_example.json");

    std::cout << "Loaded materials: " << loadedMaterials.size() << "\n\n";

    for (const TrainingMaterial& material : loadedMaterials)
    {
        std::cout << " material ID: " << material.getMaterialId();
        std::cout << "\n title: " << material.getTitle();
        std::cout << "\n content: " << material.getContent();

        std::cout << "\n tags: ";
        for (const std::string& tag : material.getTags())
        {
            std::cout << tag << ", ";
        }

        std::cout << "\n\n";
    }
*/
/*
    // Test sesji quizu i progressu

    // SingleChoiceQuestion
    std::vector<AnswerOption> singleOptions = {
        AnswerOption("EMB 190-100", false),
        AnswerOption("ERJ 190-100", true),
        AnswerOption("EMB 170-300", false)
    };

    SingleChoiceQuestion q1("Which shortcut is correct for Embraer 190?", singleOptions);

    std::cout << "\nQuestion: " << q1.getText() << "\n";

    for(size_t i=0; i < q1.getOptions().size(); i++)
    {
        std::cout << i << " - " << q1.getOptions()[i].getText() << "\n";
    }


    // MultipleChoiceQuestion
    std::vector<AnswerOption> multipleOptions = {
        AnswerOption("Aileron", true),
        AnswerOption("Rudder", true),
        AnswerOption("Flaps", false),
        AnswerOption("Horizontal Stabilizer", false),
        AnswerOption("Elevator", true)
    };

    MultipleChoiceQuestion q2("Which of listed surfaces are classified as Primary Flight Controls?", multipleOptions);

    std::cout << "\nQuestion: " << q2.getText() << "\n";

    for(size_t i=0; i < q2.getOptions().size(); i++)
    {
        std::cout << i << " - " << q2.getOptions()[i].getText() << "\n";
    }

    // SingleChoiceQuestion v2 - do testu wyświetlania wyniku w %
    std::vector<AnswerOption> singleOptions2 = {
        AnswerOption("4 points", false),
        AnswerOption("5 points", false),
        AnswerOption("3 points", true)
    };

    SingleChoiceQuestion q12("How many jacking points for complete aircraft jacking Embraer 190 have?", singleOptions2);

    std::cout << "\nQuestion: " << q12.getText() << "\n";

    for(size_t i=0; i < q12.getOptions().size(); i++)
    {
        std::cout << i << " - " << q12.getOptions()[i].getText() << "\n";
    }


    // Quiz session
    QuizSession qSession;
    qSession.addQuestion(&q1);
    qSession.addQuestion(&q2);
    qSession.addQuestion(&q12);

    //std::vector<int> a1 = {1}; //poprawna
    std::vector<int> a1 = {0}; //niepoprawna

    std::vector<int> a2 = {0,1,4}; //poprawne
    //std::vector<int> a2 = {0,1}; //niepoprawne

    std::vector<int> a12 = {2}; //poprawna
    //std::vector<int> a12 = {0}; //niepoprawna

    qSession.answerQuestion(0,a1);
    qSession.answerQuestion(1,a2);
    qSession.answerQuestion(2,a12);

    qSession.calculateScore();

    std::cout << "\n   QUIZ SESSION\n\n";
    std::cout << "Number of questions: " << qSession.getQuestionCount() << "\n";
    std::cout << "Score: " << qSession.getScore() << "/" << qSession.getQuestionCount() <<
        "   " << qSession.getPercentageScore() << "%\n";


    // Progress
    Progress prog;

    prog.addTestResult(qSession.getPercentageScore());

    prog.markSubTopicCompleted("Airplane General");
    //prog.markSubTopicCompleted("Hydraulics");

    // ręczne sprawdzenie błędnych pytań
    if (!q1.checkAnswer(a1))
    {
        prog.addIncorrectQuestion("Q1");
    }

    if (!q2.checkAnswer(a2))
    {
        prog.addIncorrectQuestion("Q2");
    }

    if (!q12.checkAnswer(a12))
    {
        prog.addIncorrectQuestion("Q3");
    }


    if (prog.getCompletedSubTopics().size() == 0)
    {
        std::cout << "\nNo completed material available\n";
    }
    else
    {
        std::cout << "\n   PROGRESS\n\n" << "Completed SubTopics:\n";
        for (const std::string& subTopic : prog.getCompletedSubTopics())
        {
            std::cout << subTopic << "\n";
        }
    }


    if (prog.getTestResults().size() == 0)
    {
        std::cout << "\nNo quiz results available\n";
    }
    else
    {
        std::cout << "\nQuiz results: \n";
        for (const double& res : prog.getTestResults())
        {
            std::cout << res << "%\n";
        }
    }


    if (prog.getIncorrectQuestionIDs().size() == 0)
    {
        std::cout << "\nNo incorrect questions available\n";
    }
    else
    {
        std::cout << "\nIncorrect questions ID's: \n";
        for (const std::string& questID : prog.getIncorrectQuestionIDs())
        {
            std::cout << questID << "\n";
        }
    }
*/
/*
    // Test struktury kursu

    std::cout << "COURSE STRUCTURE TEST\n\n";

    TrainingMaterial mat1 ("M1", "Component location", "All components are localized ... ",
                              {"ACMP", "W-T-F fairing", "LG NO DISPATCH"});

    TrainingMaterial mat2 ("M2", "Component location", "All components are localized ... ",
                          {});


    Note note1("Pump is mounted in cartridge", "M1");
    Note note2("Pump is used for APU start", "M2");


    SubTopic sub1("AC Pump", note1);
    sub1.addMaterial(mat1);

    SubTopic sub2("DC Pump", note2);
    sub2.addMaterial(mat2);


    Topic top1("Components", "01/05/2026 10:00 UTC");
    top1.addSubTopic(sub1);
    top1.addSubTopic(sub2);

    Chapter chap1(29, "HYDRAULIC POWER");
    chap1.addTopic(top1);

    // Wyświetlenie w konsoli

    std::cout << "Chapter ATA " << chap1.getNumberATA() << " - " << chap1.getName() << "\n\n";

    for (const Topic& t : chap1.getTopics())
    {
        std::cout << "-Topic: " << t.getName() << " - deadline: " << t.getPlannedCompletionDate() << "\n\n";

        for (const SubTopic& s : t.getSubTopics())
        {
            std::cout << "--Sub-Topic: " << s.getName() << "\n";

            for (const TrainingMaterial& m : s.getMaterials())
            {
                std::cout << "---Material title: " << m.getTitle() << "\n";
                std::cout << "----Material content: " << m.getContent() << "\n";

            }

            std::cout << "---Note: " << s.getNote().getContent() << "\n\n";
        }
    }
*/

    w.show();
    return a.exec();
}
