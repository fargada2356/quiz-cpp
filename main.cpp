#include <iostream>
#include <vector>
#include <string>
#include <cctype>
#include <cstdlib>
#include <ctime>

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

  return true;
}

void geographyQuiz(vector<pair<string, string>>& quiz)
{
  quiz.clear();

  quiz.push_back({"What is the capital of Germany?", "Berlin"});
  quiz.push_back({"Which is the longest river in the world?", "Nile"});
  quiz.push_back({"Which continent is the Sahara Desert located on?", "Africa"});
  quiz.push_back({"What is the largest country by area?", "Russia"});
  quiz.push_back({"Which ocean lies between Africa and Australia?", "Indian Ocean"});
  
}

void historyQuiz(vector<pair<string, string>>& quiz)
{
  quiz.clear();

  quiz.push_back({"Who was the first President of the United States?", "George Washington"});
  quiz.push_back({"In which year did World War I begin?", "1914"});
  quiz.push_back({"Which empire was ruled by Julius Caesar?", "Roman Empire"});
  quiz.push_back({"What wall fell in 1989 symbolizing the end of the Cold War?", "Berlin Wall"});
  quiz.push_back({"Who was the leader of Nazi Germany during World War II?", "Adolf Hitler"});
}

void programmingQuiz(vector<pair<string, string>>& quiz)
{
  quiz.clear();

  quiz.push_back({"What does CPU stand for?", "Central Processing Unit"});
  quiz.push_back({"Which keyword is used to define a constant in C++?", "const"});
  quiz.push_back({"What data structure works on FIFO principle?", "Queue"});
  quiz.push_back({"Which operator is used for comparison in C++?", "=="});
  quiz.push_back({"What symbol is used for single line comments in C++?", "//"});
}

void generalQuiz(vector<pair<string, string>>& quiz)
{
  quiz.clear();

  quiz.push_back({"What is the capital of Canada?", "Ottawa"});
  quiz.push_back({"Which planet is known as the Red Planet?", "Mars"});
  quiz.push_back({"What is the largest ocean on Earth?", "Pacific"});
  quiz.push_back({"In which year did World War II end?", "1945"});
  quiz.push_back({"Which country is famous for inventing pizza?", "Italy"});
}


int main()
{

  srand(time(0));

  vector<pair<string, string>> quiz;

  int score = 0;
  int choice = 0;


  while (choice != 5)
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
     {
      break; 
     }

    default:
      cout << "Invalid choice! Try different option.\n";
      continue;
    }

    for (int k = 0; k < quiz.size(); k++) {
      int r = rand() % quiz.size();
      swap(quiz[k], quiz[r]);
    }

    for (int i = 0; i < quiz.size(); i++)
    {

      cout << quiz[i].first << "\n> ";
      string userAnswer;
      getline(cin, userAnswer);

      if (sensitiveStrings(userAnswer, quiz[i].second))
      {
        score++;
        cout << "Correct answer!" << endl;
        cout << "Final score: " << score << "/" << quiz.size() << flush;
      }
      else
      {
        cout << "Incorrect answer!" << endl;
        cout << "Final score: " << score << "/" << quiz.size() << flush;
      }

      cout << endl;
    }
  }
  return 0;
}