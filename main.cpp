#include <iostream>
#include <vector>
#include <string>
#include <cctype>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <sstream>

using namespace std;

bool sensitiveStrings(const string &text1,
                      const string &text2)
{

  int j = 0;

  for (int i = 0; i < text1.length(); i++)
  {
    if (isspace(text1[i]))
    {
      continue;
    }

    while (j < text2.length() && isspace(text2[j]))
    {
      j++;
    }

    if (j >= text2.length())
    {
      return false;
    }

    if (tolower(text1[i]) != tolower(text2[j]))
    {
      return false;
    }

    j++;
  }

  while (j < text2.length() && isspace(text2[j]))
  {
    j++;
  }

  return j == text2.length();
}

void geographyQuiz(vector<pair<string, string>> &quiz)
{
  quiz.clear();

  ifstream file("QuizQuestions/geography.txt");

  if (!file) {
    cout << "Error opening the file!\n";
    return;
  }

  string questions;
  string answers;

  while(getline(file, questions, '|') &&
        getline(file, answers)) {
          quiz.push_back({questions, answers});
        }

  file.close();
}

void historyQuiz(vector<pair<string, string>> &quiz)
{
  quiz.clear();

  ifstream file("QuizQuestions/history.txt");

  if (!file) {
    cout << "Error opening the file!\n";
    return;
  }

  string questions;
  string answers;

  while(getline(file, questions, '|') &&
        getline(file, answers)) {
          quiz.push_back({questions, answers});
        }

  file.close();
}

void programmingQuiz(vector<pair<string, string>> &quiz)
{
  quiz.clear();


   ifstream file("QuizQuestions/programming.txt");

  if (!file) {
    cout << "Error opening the file!\n";
    return;
  }

  string questions;
  string answers;

  while(getline(file, questions, '|') &&
        getline(file, answers)) {
          quiz.push_back({questions, answers});
        }

  file.close();
}

void generalQuiz(vector<pair<string, string>> &quiz)
{
  
  quiz.clear();

  ifstream file("QuizQuestions/general.txt");

  if (!file) {
    cout << "Error opening the file!\n";
    return;
  }
  
  string question;
  string answer;

  while(getline(file, question, '|') &&
        getline(file, answer))
        {
          quiz.push_back({question, answer});
        }

  file.close();
}

int showMenu()
{

  int choice = 0;

  cout << "======WELCOME TO QUIZ!======" << endl;

  cout << "1. Geography\n";
  cout << "2. History\n";
  cout << "3. Programming\n";
  cout << "4. General Quiz\n";
  cout << "5. Exit\n";
  cout << "Choose a category!\n";
  cin >> choice;
  cin.ignore();

  return choice;
}

void getChoice(int choice, vector<pair<string, string>> &quiz)
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
    cout << "Exiting...\n";
    break;

  default:
    cout << "Invalid choice! Try to enter a number instead.\n";
    break;
  }
}

void shuffleQuestions(vector<pair<string, string>>& quiz)
{

  for (int k = 0; k < quiz.size(); k++)
  {
    int r = rand() % quiz.size();
    swap(quiz[k], quiz[r]);
  }
}

void loadQuiz(vector<pair<string, string>>& quiz,  int& score)
{

  shuffleQuestions(quiz);

  for (size_t i = 0; i < quiz.size(); i++)
  {

    cout << quiz[i].first << "\nAnswer: ";
    string userAnswer;
    getline(cin, userAnswer);

    if (sensitiveStrings(userAnswer, quiz[i].second))
    {
      score++;
      cout << "Correct answer!" << endl;
      cout << "Score: " << score << "/" << quiz.size() << flush;
    }

    else
    {
      cout << "Incorrect answer!" << endl;
      cout << "Score: " << score << "/" << quiz.size() << flush;
    }

    cout << endl;
  }
}

void finalScorePrint(vector<pair<string, string>>& quiz, int& score)
{
  cout << "Final Score: " << score << "/" << quiz.size() << endl;
}

void previousScores() {

  ifstream file("playerScores/scores.txt");
  int previousScore;
  while (file >> previousScore) {
    cout << "Previous Score: " << previousScore << endl;
  }

  file.close();
}

void loadScores(string playerName, int score, int total) {

  vector<string> allLines;
  bool playerFound = false;

  ifstream inFile("playerScores/scores.txt");
  string name;
  int oldScore, oldTotal;

  while(getline(inFile, name, ',')) {
    inFile >> oldScore;
    inFile.ignore();
    inFile >> oldTotal;
    inFile.ignore();

    if(name == playerName) {
      playerFound = true;
      oldScore = oldScore + score;
      oldTotal = oldTotal + total;
    }

    stringstream ss;
    ss << name << "," << oldScore << "," << oldTotal;
    allLines.push_back(ss.str());
  }
  inFile.close();

  if(!playerFound) {
    stringstream ss;
    ss << playerName << "," << score << "," << total;
    allLines.push_back(ss.str());
  }

  ofstream outFile("playerScores/scores.txt");
  for(int i = 0; i < allLines.size(); i++) {
    outFile << allLines[i] << endl;
  }
  outFile.close();
}

int main()
{



  srand(time(0));

  vector<pair<string, string>> quiz;

  int choice = 0;

  string playerName;
  cout << "Enter your name :";
  getline(cin, playerName);
  cout << "Welcome, " << playerName << "!\n\n";


  while (choice != 5)
  {

    choice = showMenu();

    if (choice == 5)
    {
      break;
    }

    getChoice(choice, quiz);

    if (quiz.empty()) {
      continue;
    }

    int score = 0;
    loadQuiz(quiz, score);

    loadScores(playerName, score, quiz.size());

    cout << "\n";

  }

  return 0;
}