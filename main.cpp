#include <iostream>
#include <vector>
#include <string>
#include <cctype>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <sstream>
#include <algorithm>

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

  if (!file)
  {
    cout << "Error opening the file!\n";
    return;
  }

  string question, optionA, optionB, optionC, optionD;
  char correctAnswer;

  while (getline(file, question, '|') &&
         getline(file, optionA, '|') &&
         getline(file, optionB, '|') &&
         getline(file, optionC, '|') &&
         getline(file, optionD, '|'))
  {

    file >> correctAnswer;
    file.ignore();

    string fullQuestion = question + "~" + optionA + "~" + optionB + "~" + optionC + "~" + optionD;

    string answer(1, correctAnswer);

    quiz.push_back({fullQuestion, answer});
  }
  file.close();
}

void historyQuiz(vector<pair<string, string>> &quiz)
{
  quiz.clear();

  ifstream file("QuizQuestions/history.txt");

  if (!file)
  {
    cout << "Error opening the file!\n";
    return;
  }

  string question, optionA, optionB, optionC, optionD;
  char correctAnswer;

  while (getline(file, question, '|') &&
         getline(file, optionA, '|') &&
         getline(file, optionB, '|') &&
         getline(file, optionC, '|') &&
         getline(file, optionD, '|'))
  {

    file >> correctAnswer;
    file.ignore();

    string fullQuestion = question + "~" + optionA + "~" + optionB + "~" + optionC + "~" + optionD;
    string answer(1, correctAnswer);
    quiz.push_back({fullQuestion, answer});

  }

  file.close();
}

void programmingQuiz(vector<pair<string, string>> &quiz)
{
  quiz.clear();

  ifstream file("QuizQuestions/programming.txt");

  if (!file)
  {
    cout << "Error opening the file!\n";
    return;
  }

  string question, optionA, optionB, optionC, optionD;
  char correctAnswer;

  while (getline(file, question, '|') &&
         getline(file, optionA, '|') &&
         getline(file, optionB, '|') &&
         getline(file, optionC, '|') &&
         getline(file, optionD, '|'))
  {

    file >> correctAnswer;
    file.ignore();

    string fullQuestion = question + "~" + optionA + "~" + optionB + "~" + optionC + "~" + optionD;
    string answer(1, correctAnswer);
    quiz.push_back({fullQuestion, answer});

  }
  file.close();



}

void generalQuiz(vector<pair<string, string>> &quiz)
{

  quiz.clear();

  ifstream file("QuizQuestions/general.txt");

  if (!file)
  {
    cout << "Error opening the file!\n";
    return;
  }

  string question, optionA, optionB, optionC, optionD;
  char correctAnswer;

  while (getline(file, question, '|') &&
         getline(file, optionA, '|') &&
         getline(file, optionB, '|') &&
         getline(file, optionC, '|') &&
         getline(file, optionD, '|'))
  {

    file >> correctAnswer;
    file.ignore();

    string fullQuestion = question + "~" + optionA + "~" + optionB + "~" + optionC + "~" + optionD;
    string answer(1, correctAnswer);
    quiz.push_back({fullQuestion, answer});
  }
  file.close();

}

int showMenu()
{
  int choice = 0;

  while(true) {
  cout << "======WELCOME TO QUIZ!======" << endl;
  cout << "1. Geography\n";
  cout << "2. History\n";
  cout << "3. Programming\n";
  cout << "4. General Quiz\n";
  cout << "5. Leaderboard\n";
  cout << "6. Exit\n";
  cout << "Choose a category!\n";
  cin >> choice;

  if(cin.fail()) {
    cin.clear();
    cin.ignore(10000, '\n');
    cout << "Invalid! Enter a number.\n\n";
    continue;
  }

  cin.ignore(10000, '\n');

  if (choice < 1 || choice > 6) {
    cout << "Invalid! Enter 1-6.\n\n";
    continue;
  }

  return choice;
  
}
  
}

void leaderboard(vector<pair<string, int>> &leaderScore)
{

  leaderScore.clear();

  ifstream file("playerScores/scores.txt");

  if (!file)
  {
    cout << "Error opening scores file!\n";
    return;
  }

  string name;
  int oldScore, oldTotal;

  while (getline(file, name, ','))
  {
    file >> oldScore;
    file.ignore();
    file >> oldTotal;
    file.ignore();

    leaderScore.push_back({name, oldScore});
  }

  file.close();

  sort(leaderScore.begin(), leaderScore.end(), [](const pair<string, int> &a, const pair<string, int> &b)
       { return a.second > b.second; });

  cout << "\n===== LEADERBOARD =====\n";
  for (int i = 0; i < leaderScore.size(); i++)
  {
    cout << (i + 1) << ". " << leaderScore[i].first << " - " << leaderScore[i].second << endl;
  }
  cout << "=======================\n\n";
}

void getChoice(int choice,
               vector<pair<string, string>> &quiz,
               vector<pair<string, int>> &leaderScore)
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
    leaderboard(leaderScore);
    break;

  case 6:
    cout << "Exiting...\n";
    break;

  default:
    cout << "Invalid choice! Try to enter a number instead.\n";
    break;
  }
}

void shuffleQuestions(vector<pair<string, string>> &quiz)
{

  for (int k = 0; k < quiz.size(); k++)
  {
    int r = rand() % quiz.size();
    swap(quiz[k], quiz[r]);
  }
}

void loadQuiz(vector<pair<string, string>> &quiz, int &score)
{

  shuffleQuestions(quiz);

  for (size_t i = 0; i < quiz.size(); i++)
  {
    string question, optionA, optionB, optionC, optionD;

    stringstream ss(quiz[i].first);
    getline(ss, question, '~');
    getline(ss, optionA, '~');
    getline(ss, optionB, '~');
    getline(ss, optionC, '~');
    getline(ss, optionD, '~');

    string correctAnswer = quiz[i].second;

    vector<string> options;
    options.push_back(optionA);
    options.push_back(optionB);
    options.push_back(optionC);
    options.push_back(optionD);

    for (int k = 0; k < options.size(); k++)
    {
      int r = rand() % options.size();
      swap(options[k], options[r]);
    }

    cout << "\nQuestion " << (i + 1) << ": " << question << endl;
    cout << "A) " << options[0] << endl;
    cout << "B) " << options[1] << endl;
    cout << "C) " << options[2] << endl;
    cout << "D) " << options[3] << endl;

    cout << "Your Answer (A/B/C/D): ";
    string input;
    cin >> input;

    if(input.length() != 1) {
      cout << "Invalid input! Please enter A, B, C, or D.\n";
      i--;
      continue;
    }

    char userChoice = input[0];

    cin.ignore(10000, '\n');

    if (userChoice >= 'a' && userChoice <= 'd')
    {
      userChoice -= 32;
    }

    if(userChoice != 'A' && userChoice != 'B' && userChoice != 'C' && userChoice != 'D') {
      cout << "Invalid choice! Please enter A, B ,C or D.\n";
      i--;
      continue;
    }

    string correctAnswerText;
    if (correctAnswer == "A")
      correctAnswerText = optionA;
    else if (correctAnswer == "B")
      correctAnswerText = optionB;
    else if (correctAnswer == "C")
      correctAnswerText = optionC;
    else if (correctAnswer == "D")
      correctAnswerText = optionD;

    string userPickedText;
    if (userChoice == 'A')
      userPickedText = options[0];
    else if (userChoice == 'B')
      userPickedText = options[1];
    else if (userChoice == 'C')
      userPickedText = options[2];
    else if (userChoice == 'D')
      userPickedText = options[3];

    if (userPickedText == correctAnswerText) {
      score++;
      cout << "Correct!" << endl;
    }

    else {
      cout << "Wrong! the answer was " << correctAnswerText << endl;
    }
  }

}

void finalScorePrint(vector<pair<string, string>> &quiz, int &score)
{
  cout << "Final Score: " << score << "/" << quiz.size() << endl;
}

void showStatistics (int score, int total) {

  double accuracy = (score * 100.0) / total;

  cout << "===== YOUR STATS =====" << endl;

  cout << "Score: " << score << "/" << total << endl;
  cout << "Accuracy: " << accuracy << "%\n";

  if (accuracy >= 90) {
    cout << "Excellent work!\n";
  }

  else if (accuracy >= 80) {
    cout << "Good!\n";
  }
  
  else if (accuracy >= 50) {
    cout << "Well done!\n";
  }

  else if (accuracy >= 30) {
    cout << "Poor!\n";
  }

  else if (accuracy >= 10) {
    cout << "Really bad performance..\n";
  }

}

void previousScores()
{

  ifstream file("playerScores/scores.txt");
  int previousScore;
  while (file >> previousScore)
  {
    cout << "Previous Score: " << previousScore << endl;
  }

  file.close();
}

void loadScores(string playerName, int score, int total)
{

  vector<string> allLines;
  bool playerFound = false;

  ifstream inFile("playerScores/scores.txt");
  string name;
  int oldScore, oldTotal;

  while (getline(inFile, name, ','))
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

    stringstream ss;
    ss << name << "," << oldScore << "," << oldTotal;
    allLines.push_back(ss.str());
  }
  inFile.close();

  if (!playerFound)
  {
    stringstream ss;
    ss << playerName << "," << score << "," << total;
    allLines.push_back(ss.str());
  }

  ofstream outFile("playerScores/scores.txt");
  for (int i = 0; i < allLines.size(); i++)
  {
    outFile << allLines[i] << endl;
  }
  outFile.close();
}

int main()
{
  srand(time(0));

  vector<pair<string, string>> quiz;
  int choice = 0;
  vector<pair<string, int>> leaderScore;

  string playerName;
  cout << "Enter your name : ";
  getline(cin, playerName);
  cout << "Welcome, " << playerName << "!\n\n";

  while (choice != 6)
  {
    choice = showMenu();

    if (choice == 6)
    {
      break;
    }

    getChoice(choice, quiz, leaderScore);

    if (quiz.empty())
    {
      continue;
    }

    int score = 0;
    loadQuiz(quiz, score);
    showStatistics(score, quiz.size());

    loadScores(playerName, score, quiz.size());

    cout << "\n";
  }

  return 0;
}