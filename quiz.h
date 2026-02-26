#ifndef QUIZ_H
#define QUIZ_H

#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <cstdlib>

class Question {
private:
    std::string text;
    std::vector<std::string> options;
    char correctAnswer;
    std::string correctText;  
    
public:
    Question(std::string q, std::vector<std::string> opts, char correct) {
        text = q;
        correctAnswer = correct;
        
        if (correct == 'A') correctText = opts[0];
        else if (correct == 'B') correctText = opts[1];
        else if (correct == 'C') correctText = opts[2];
        else if (correct == 'D') correctText = opts[3];
        
        for (size_t i = 0; i < opts.size(); i++) {
            size_t r = rand() % opts.size();
            std::swap(opts[i], opts[r]);
        }
        
        options = opts;
    }
    
    void print() const {
        std::cout << "\n" << text << std::endl;
        std::cout << "A) " << options[0] << std::endl;
        std::cout << "B) " << options[1] << std::endl;
        std::cout << "C) " << options[2] << std::endl;
        std::cout << "D) " << options[3] << std::endl;
    }
    
    bool checkAnswer(char choice) const {
        if (choice == 'A') return options[0] == correctText;
        if (choice == 'B') return options[1] == correctText;
        if (choice == 'C') return options[2] == correctText;
        if (choice == 'D') return options[3] == correctText;
        return false;
    }
    
    std::string getText() const {
        return text;
    }
    
    std::string getCorrectOptionText() const {
        return correctText;
    }
};

void randomMixQuiz(std::vector<Question>& quiz);

#endif