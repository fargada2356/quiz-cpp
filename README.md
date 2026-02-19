# Quiz Engine (C++)

A C++ console-based quiz application with multiple categories, score tracking, and leaderboard system.

## Features

- 5 Quiz Categories: Geography, History, Programming, General Knowledge, Random Mix
- 60+ Questions: 15 questions per category
- Multiple Choice Format: A/B/C/D answer options
- Randomization: Questions and answer options are shuffled each time
- Statistics: View accuracy percentage and performance feedback after each quiz
- Top 5 Leaderboard: Tracks cumulative scores across sessions
- Review Wrong Answers: Option to review mistakes after each quiz
- Input Validation: Handles invalid inputs gracefully
- Persistent Storage: Player scores saved between sessions

## How It Works

1. Enter your name when prompted
2. Select a quiz category from the menu (1-5)
3. Answer multiple choice questions by typing A, B, C, or D
4. View your statistics (score and accuracy percentage)
5. Optionally review questions you got wrong
6. Your cumulative score is saved to the leaderboard
7. Check the Top 5 Leaderboard to see how you rank

## How to Run
```bash
# Compile
g++ main.cpp -o quiz

# Run
./quiz
```

## Project Structure
```
QuizEngine/
├── main.cpp
├── QuizQuestions/
│   ├── geography.txt
│   ├── history.txt
│   ├── programming.txt
│   └── general.txt
└── playerScores/
    └── scores.txt
```

## Question File Format

Each question follows this format:
```
Question text?|OptionA|OptionB|OptionC|OptionD|CorrectLetter
```

Example:
```
What is the capital of France?|Paris|London|Berlin|Rome|A
```

## Technologies Used

- Language: C++
- Data Structures: STL (vector, pair, string, stringstream)
- Algorithms: Shuffling, sorting
- File I/O: ifstream, ofstream
- Concepts: Functions, loops, conditionals, input validation

## Statistics Tracked

- Score per quiz session
- Accuracy percentage with performance feedback
- Cumulative total score across all quizzes
- Wrong answers for review

## Leaderboard System

- Displays top 5 players by total score
- Automatic sorting from highest to lowest
- Cumulative scoring (all quiz scores added together)
- Persistent storage between program runs

## Future Improvements

- Hints system
- Difficulty levels (Easy/Medium/Hard)
- Timer per question
- Colored terminal output
- GUI version using Qt

## Author

Yordan Stoyanov