#include "mainwindow.h"
#include <QApplication>


/*
#include "MultipleChoiceQuestion.h"
#include "SingleChoiceQuestion.h"
*/


#include "Chapter.h"
#include "Topic.h"
#include "SubTopic.h"
#include "TrainingMaterial.h"
#include "Note.h"


#include <iostream>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    /*
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
    */

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

    w.show();
    return a.exec();
}
