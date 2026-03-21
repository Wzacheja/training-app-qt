#include "MultipleChoiceQuestion.h"

#include <algorithm>

MultipleChoiceQuestion::MultipleChoiceQuestion(const std::string& text,
                                               const std::vector<AnswerOption>& options) : Question(text)
{
    this->options = options;
}

bool MultipleChoiceQuestion::checkAnswer(const std::vector<int>& userAnswers) const
{
    std::vector<int> correctAnswers;

    for(int i=0; i < static_cast<int>(options.size()); i++)
    {
        if (options[i].getIsCorrect())
        {
            correctAnswers.push_back(i);
        }
    }

    std::vector<int> sortedUserAnswers = userAnswers;
    std::sort(sortedUserAnswers.begin(), sortedUserAnswers.end());
    std::sort(correctAnswers.begin(), correctAnswers.end());

    return sortedUserAnswers == correctAnswers;
}
