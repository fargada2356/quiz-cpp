#include <iostream>
#include <vector>
#include <string>
#include <cctype>

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

  if (text1.length() != text2.length())
  {
    return false;
  }

  for (size_t i = 0; i < text1.length(); i++)
  {
    if (tolower(text1[i]) != tolower(text2[i]))
    {
      return false;
    }
  }

  return true;
}

void geographyQuiz(vector<string> &questions,
                   vector<string> &answers)
{

  questions.clear();
  answers.clear();

  questions.push_back("What is the capital of Germany?");
  answers.push_back("Berlin");

  questions.push_back("Which is the longest river in the world?");
  answers.push_back("Nile");

  questions.push_back("Which continent is the Sahara Desert located on?");
  answers.push_back("Africa");

  questions.push_back("What is the largest country by area?");
  answers.push_back("Russia");

  questions.push_back("Which ocean lies between Africa and Australia?");
  answers.push_back("Indian Ocean");
}

void historyQuiz(vector<string> &questions,
                 vector<string> &answers)
{

  questions.clear();
  answers.clear();

  questions.push_back("Who was the first President of the United States?");
  answers.push_back("George Washington");

  questions.push_back("In which year did World War I begin?");
  answers.push_back("1914");

  questions.push_back("Which empire was ruled by Julius Caesar?");
  answers.push_back("Roman Empire");

  questions.push_back("What wall fell in 1989 symbolizing the end of the Cold War?");
  answers.push_back("Berlin Wall");

  questions.push_back("Who was the leader of Nazi Germany during World War II?");
  answers.push_back("Adolf Hitler");
}

void programmingQuiz(vector<string> &questions,
                     vector<string> &answers)
{
  questions.clear();
  answers.clear();

  questions.push_back("What does CPU stand for?");
  answers.push_back("Central Processing Unit");

  questions.push_back("Which keyword is used to define a constant in C++?");
  answers.push_back("const");

  questions.push_back("What data structure works on FIFO principle?");
  answers.push_back("Queue");

  questions.push_back("Which operator is used for comparison in C++?");
  answers.push_back("==");

  questions.push_back("What symbol is used for single line comments in C++?");
  answers.push_back("//");
}

void generalQuiz(vector<string> &questions,
                 vector<string> &answers)
{

  questions.clear();
  answers.clear();

  questions.push_back("What is the capital of Canada?");
  answers.push_back("Ottawa");

  questions.push_back("Which planet is known as the Red Planet?");
  answers.push_back("Mars");

  questions.push_back("What is the largest ocean on Earth?");
  answers.push_back("Pacific");

  questions.push_back("In which year did World War II end?");
  answers.push_back("1945");

  questions.push_back("Which country is famous for inventing pizza?");
  answers.push_back("Italy");
}

int main()
{

  vector<string> questions;
  vector<string> answers;

  int score = 0;
  int choice = 0;

  while (choice != 4)
  {

    cout << "======WELCOME TO QUIZ!======" << endl;

    cout << "1. Geography\n";
    cout << "2. History\n";
    cout << "3. Programming\n";
    cout << "4. General Quiz\n";
    cout << "5. Exit\n";
    cout << "Choose a category!\n";
    cin >> choice;
    cin.ignore();

    switch (choice)
    {
    case 1:
      geographyQuiz(questions, answers);
      break;

    case 2:
      historyQuiz(questions, answers);
      break;

    case 3:
      programmingQuiz(questions, answers);
      break;

    case 4:
      generalQuiz(questions, answers);
      break;

    case 5:
     {
      bool exitMenu = false;
      exitMenu = true;
      break;
     }

    default:
      cout << "Invalid choice! Try different option.\n";
      continue;
    }

    for (int i = 0; i < questions.size() - 1; i++)
    {

      cout << questions[i] << "\n> ";
      string userAnswer;
      getline(cin, userAnswer);

      if (sensitiveStrings(userAnswer, answers[i]))
      {
        score++;
        cout << "Correct answer!" << endl;
        cout << "Final score: " << score << "/" << questions.size() << flush;
      }
      else
      {
        cout << "Incorrect answer!" << endl;
        cout << "Final score: " << score << "/" << questions.size() << flush;
      }

      cout << endl;
    }
  }
  return 0;
}