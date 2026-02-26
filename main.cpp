#include <iostream>
#include <vector>
#include <string>
#include <cctype>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <sstream>
#include <algorithm>
#include "quiz.h"

bool sensitiveStrings(const std::string &text1,
                      const std::string &text2)
{
  int j = 0;

  for (int i = 0; i < (int)text1.length(); i++)
  {
    if (std::isspace(text1[i]))
    {
      continue;
    }

    while (j < (int)text2.length() && std::isspace(text2[j]))
    {
      j++;
    }

    if (j >= (int)text2.length())
    {
      return false;
    }

    if (std::tolower(text1[i]) != std::tolower(text2[j]))
    {
      return false;
    }

    j++;
  }

  while (j < (int)text2.length() && std::isspace(text2[j]))
  {
    j++;
  }

  return j == (int)text2.length();
}

void geographyQuiz(std::vector<Question>& quiz)
{
  quiz.clear();

  std::ifstream file("QuizQuestions/geography.txt");

  if (!file)
  {
    std::cout << "Error opening the file!\n";
    return;
  }

  std::string question, optionA, optionB, optionC, optionD;
  char correctAnswer;

  while (std::getline(file, question, '|') &&
         std::getline(file, optionA, '|') &&
         std::getline(file, optionB, '|') &&
         std::getline(file, optionC, '|') &&
         std::getline(file, optionD, '|'))
  {
    file >> correctAnswer;
    file.ignore();

    Question q(question, {optionA, optionB, optionC, optionD}, correctAnswer);
    quiz.push_back(q);
  }

  file.close();
}

void historyQuiz(std::vector<Question>& quiz)
{
  quiz.clear();

  std::ifstream file("QuizQuestions/history.txt");

  if (!file)
  {
    std::cout << "Error opening the file!\n";
    return;
  }

  std::string question, optionA, optionB, optionC, optionD;
  char correctAnswer;

  while (std::getline(file, question, '|') &&
         std::getline(file, optionA, '|') &&
         std::getline(file, optionB, '|') &&
         std::getline(file, optionC, '|') &&
         std::getline(file, optionD, '|'))
  {
    file >> correctAnswer;
    file.ignore();

    Question q(question, {optionA, optionB, optionC, optionD}, correctAnswer);
    quiz.push_back(q);
  }

  file.close();
}

void programmingQuiz(std::vector<Question>& quiz)
{
  quiz.clear();

  std::ifstream file("QuizQuestions/programming.txt");

  if (!file)
  {
    std::cout << "Error opening the file!\n";
    return;
  }

  std::string question, optionA, optionB, optionC, optionD;
  char correctAnswer;

  while (std::getline(file, question, '|') &&
         std::getline(file, optionA, '|') &&
         std::getline(file, optionB, '|') &&
         std::getline(file, optionC, '|') &&
         std::getline(file, optionD, '|'))
  {
    file >> correctAnswer;
    file.ignore();

    Question q(question, {optionA, optionB, optionC, optionD}, correctAnswer);
    quiz.push_back(q);
  }

  file.close();
}

void generalQuiz(std::vector<Question>& quiz)
{
  quiz.clear();

  std::ifstream file("QuizQuestions/general.txt");

  if (!file)
  {
    std::cout << "Error opening the file!\n";
    return;
  }

  std::string question, optionA, optionB, optionC, optionD;
  char correctAnswer;

  while (std::getline(file, question, '|') &&
         std::getline(file, optionA, '|') &&
         std::getline(file, optionB, '|') &&
         std::getline(file, optionC, '|') &&
         std::getline(file, optionD, '|'))
  {
    file >> correctAnswer;
    file.ignore();

    Question q(question, {optionA, optionB, optionC, optionD}, correctAnswer);
    quiz.push_back(q);
  }

  file.close();
}

int showMenu()
{
  int choice = 0;

  while (true)
  {
    std::cout << "======WELCOME TO QUIZ!======" << std::endl;
    std::cout << "1. Geography\n";
    std::cout << "2. History\n";
    std::cout << "3. Programming\n";
    std::cout << "4. General Quiz\n";
    std::cout << "5. Random Mix of Quizzes\n";
    std::cout << "6. Leaderboard\n";
    std::cout << "7. Exit\n";
    std::cout << "Choose a category!\n";
    std::cin >> choice;

    if (std::cin.fail())
    {
      std::cin.clear();
      std::cin.ignore(10000, '\n');
      std::cout << "Invalid! Enter a number.\n\n";
      continue;
    }

    std::cin.ignore(10000, '\n');

    if (choice < 1 || choice > 7)
    {
      std::cout << "Invalid! Enter 1-7.\n\n";
      continue;
    }

    return choice;
  }
}

void leaderboard(std::vector<std::pair<std::string, int>> &leaderScore)
{
  leaderScore.clear();

  std::ifstream file("playerScores/scores.txt");

  if (!file)
  {
    std::cout << "Error opening scores file!\n";
    return;
  }

  std::string name;
  int oldScore, oldTotal;

  while (std::getline(file, name, ','))
  {
    file >> oldScore;
    file.ignore();
    file >> oldTotal;
    file.ignore();

    leaderScore.push_back({name, oldScore});
  }

  file.close();

  std::sort(leaderScore.begin(), leaderScore.end(),
            [](const std::pair<std::string, int> &a, const std::pair<std::string, int> &b)
            { return a.second > b.second; });

  std::cout << "\n===== TOP 5 LEADERBOARD =====\n";
  int limit;
  if (leaderScore.size() < 5)
  {
    limit = leaderScore.size();
  }
  else
  {
    limit = 5;
  }

  for (int i = 0; i < limit; i++)
  {
    std::cout << (i + 1) << ". " << leaderScore[i].first << " - " << leaderScore[i].second << std::endl;
  }

  std::cout << "=======================\n\n";
}

void getChoice(int choice,
               std::vector<Question>& quiz,
               std::vector<std::pair<std::string, int>> &leaderScore)
{
  switch (choice)
  {
  case 1:
    geographyQuiz(quiz);
    break;

  case 2:
    historyQuiz(quiz);
    break;

  case 3:
    programmingQuiz(quiz);
    break;

  case 4:
    generalQuiz(quiz);
    break;

  case 5:
    randomMixQuiz(quiz);
    break;

  case 6:
    leaderboard(leaderScore);
    break;

  case 7:
    std::cout << "Exiting...\n";
    break;

  default:
    std::cout << "Invalid choice! Try to enter a number instead.\n";
    break;
  }
}

void shuffleQuestions(std::vector<Question> &quiz)
{
  for (int k = 0; k < (int)quiz.size(); k++)
  {
    int r = rand() % quiz.size();
    std::swap(quiz[k], quiz[r]);
  }
}

void loadQuiz(std::vector<Question>& quiz, int &score,
              std::vector<std::pair<std::string, std::string>> &wrongAnswers)
{
  shuffleQuestions(quiz);

  for (Question &q : quiz)
  {
    q.print();

    std::string input;
    char userChoice;

    while (true)
    {
      std::cout << "Your Answer (A/B/C/D): ";
      std::cin >> input;

      if (input.length() != 1)
      {
        std::cout << "Invalid input! Please enter A, B, C, or D.\n";
        continue;
      }

      userChoice = input[0];
      std::cin.ignore(10000, '\n');

      if (userChoice >= 'a' && userChoice <= 'd')
      {
        userChoice = std::toupper(userChoice);
      }

      if (userChoice != 'A' && userChoice != 'B' && userChoice != 'C' && userChoice != 'D')
      {
        std::cout << "Invalid choice! Please enter A, B, C or D.\n";
        continue;
      }

      break;
    }

    if (q.checkAnswer(userChoice))
    {
      score++;
      std::cout << "Correct!" << std::endl;
      std::cout << std::endl;
    }
    else
    {
      std::string correctText = q.getCorrectOptionText();
      wrongAnswers.push_back({q.getText(), correctText});
      std::cout << "Wrong! answer was " << correctText << "\n";
    }
  }
}

void reviewWrongAnswers(std::vector<std::pair<std::string, std::string>> wrongAnswers)
{
  if (wrongAnswers.empty())
  {
    std::cout << "You got all questions correct! No review needed.\n";
    return;
  }

  std::cout << "===== REVIEW WRONG ANSWERS =====" << std::endl;
  std::cout << "You got " << wrongAnswers.size() << " questions wrong:\n\n";

  int questionNum = 1;

  for (auto x : wrongAnswers)
  {
    std::cout << questionNum << ". ";
    std::cout << "Question: " << x.first << std::endl;
    std::cout << "Correct answer was: " << x.second << std::endl;
    std::cout << std::endl;

    questionNum++;
  }

  std::cout << "================================\n" << std::endl;
}

void finalScorePrint(std::vector<std::pair<std::string, std::string>> &quiz, int &score)
{
  std::cout << "Final Score: " << score << "/" << quiz.size() << std::endl;
}

void showStatistics(int score, int total, std::vector<std::pair<std::string, std::string>> wrongAnswers)
{
  double accuracy = (score * 100.0) / total;

  std::cout << "===== YOUR STATS =====" << std::endl;
  std::cout << "Score: " << score << "/" << total << std::endl;
  std::cout << "Accuracy: " << accuracy << "%\n";

  if (accuracy >= 90)
  {
    std::cout << "Excellent work!\n";
  }
  else if (accuracy >= 80)
  {
    std::cout << "Good!\n";
  }
  else if (accuracy >= 50)
  {
    std::cout << "Well done!\n";
  }
  else if (accuracy >= 30)
  {
    std::cout << "Poor!\n";
  }
  else if (accuracy >= 10)
  {
    std::cout << "Really bad performance..\n";
  }

  std::string answer;

  if (!wrongAnswers.empty())
  {
    std::cout << "Would you like to review wrong answers? (y/n)\n";
    std::cin >> answer;
    std::cin.ignore(10000, '\n');
  }

  if (answer == "y" || answer == "Y" || answer == "yes" || answer == "Yes")
  {
    reviewWrongAnswers(wrongAnswers);
  }

  if (answer == "n" || answer == "N")
  {
    std::cout << "Thank you for playing the quiz!\n";
  }
}

void previousScores()
{
  std::ifstream file("playerScores/scores.txt");
  int previousScore;
  while (file >> previousScore)
  {
    std::cout << "Previous Score: " << previousScore << std::endl;
  }
  file.close();
}

void loadScores(std::string playerName, int score, int total)
{
  std::vector<std::string> allLines;
  bool playerFound = false;

  std::ifstream inFile("playerScores/scores.txt");
  std::string name;
  int oldScore, oldTotal;

  while (std::getline(inFile, name, ','))
  {
    inFile >> oldScore;
    inFile.ignore();
    inFile >> oldTotal;
    inFile.ignore();

    if (name == playerName)
    {
      playerFound = true;
      oldScore = oldScore + score;
      oldTotal = oldTotal + total;
    }

    std::stringstream ss;
    ss << name << "," << oldScore << "," << oldTotal;
    allLines.push_back(ss.str());
  }
  inFile.close();

  if (!playerFound)
  {
    std::stringstream ss;
    ss << playerName << "," << score << "," << total;
    allLines.push_back(ss.str());
  }

  std::ofstream outFile("playerScores/scores.txt");
  for (int i = 0; i < (int)allLines.size(); i++)
  {
    outFile << allLines[i] << std::endl;
  }
  outFile.close();
}

void randomMixQuiz(std::vector<Question>& quiz)
{
  quiz.clear();

  std::vector<Question> allQuestions;
  std::vector<Question> tempQuiz;

  geographyQuiz(tempQuiz);
  allQuestions.insert(allQuestions.end(), tempQuiz.begin(), tempQuiz.end());

  historyQuiz(tempQuiz);
  allQuestions.insert(allQuestions.end(), tempQuiz.begin(), tempQuiz.end());

  programmingQuiz(tempQuiz);
  allQuestions.insert(allQuestions.end(), tempQuiz.begin(), tempQuiz.end());

  generalQuiz(tempQuiz);
  allQuestions.insert(allQuestions.end(), tempQuiz.begin(), tempQuiz.end());

  for (size_t k = 0; k < allQuestions.size(); k++)
  {
    size_t r = rand() % allQuestions.size();
    std::swap(allQuestions[k], allQuestions[r]);
  }

  for (size_t i = 0; i < 15 && i < allQuestions.size(); i++)
  {
    quiz.push_back(allQuestions[i]);
  }
}

int main()
{
  srand(time(0));

  std::vector<Question> quiz;
  int choice = 0;
  std::vector<std::pair<std::string, int>> leaderScore;

  std::string playerName;
  std::cout << "Enter your name : ";
  std::getline(std::cin, playerName);
  std::cout << "Welcome, " << playerName << "!\n\n";

  while (choice != 7)
  {
    choice = showMenu();

    if (choice == 7)
    {
      break;
    }

    getChoice(choice, quiz, leaderScore);

    if (choice == 6 || choice == 7)
    {
      continue;
    }

    if (quiz.empty())
    {
      continue;
    }

    int score = 0;
    std::vector<std::pair<std::string, std::string>> wrongAnswers;
    loadQuiz(quiz, score, wrongAnswers);
    showStatistics(score, quiz.size(), wrongAnswers);

    loadScores(playerName, score, quiz.size());

    std::cout << "\n";
  }

  return 0;
}