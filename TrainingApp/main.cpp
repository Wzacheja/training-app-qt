#include "mainwindow.h"
#include <QApplication>

#include "MultipleChoiceQuestion.h"
#include "SingleChoiceQuestion.h"

#include <iostream>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    // Test klas pytań

    // Test SingleChoiceQuestion
    std::vector<AnswerOption> singleOptions = {
        AnswerOption("EMB 190-100", false),
        AnswerOption("ERJ 190-100", true),
        AnswerOption("EMB 170-300", false)
    };

    SingleChoiceQuestion q1("Which shortcut is correct for Embraer 190?", singleOptions);

    std::cout << "SINGLE CHOICE QUESTION TEST\n\n";
    std::cout << "Question: " << q1.getText() << "\n";

    for(size_t i=0; i < q1.getOptions().size(); i++)
    {
        std::cout << i << " - " << q1.getOptions()[i].getText() << "\n";
    }

    // std::vector<int> a1 = {1}; //poprawna
     std::vector<int> a1 = {0}; //niepoprawna

    if (q1.checkAnswer(a1))
    {
        std::cout << "   Correct answer\n";
    }
    else
    {
        std::cout << "---Wrong answer\n";
    }

    std::cout << "\n\n";

    // Test MultipleChoiceQuestion
    std::vector<AnswerOption> multipleOptions = {
        AnswerOption("Aileron", true),
        AnswerOption("Rudder", true),
        AnswerOption("Flaps", false),
        AnswerOption("Horizontal Stabilizer", false),
        AnswerOption("Elevator", true)
    };

    MultipleChoiceQuestion q2("Which of listed surfaces are classified as Primary Flight Controls?", multipleOptions);

    std::cout << "MULTIPLE CHOICE QUESTION TEST\n\n";
    std::cout << "Question: " << q2.getText() << "\n";

    for(size_t i=0; i < q2.getOptions().size(); i++)
    {
        std::cout << i << " - " << q2.getOptions()[i].getText() << "\n";
    }

     std::vector<int> a2 = {0,1,4}; //poprawne
    // std::vector<int> a2 = {0,1}; //niepoprawne

    if (q2.checkAnswer(a2))
    {
        std::cout << "   Correct answers\n";
    }
    else
    {
        std::cout << "---Wrong answers \n";
    }

    std::cout << "\n\n";


    w.show();
    return a.exec();
}
