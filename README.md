# Math Quiz Game

## Introduction
Math Quiz Game is a console-based C++ application designed to generate random math problems based on user-selected difficulty levels and operations. It evaluates user responses and provides instant feedback.

## Features
- Multiple difficulty levels: Easy, Medium, Hard, and Mixed.
- Supported operations: Addition, Subtraction, Multiplication, and Division.
- Option to randomly mix operations for a more challenging experience.
- Keeps track of correct and incorrect answers.
- Displays final scores and pass/fail status.
- Interactive interface with color-coded feedback.
- Ability to replay the game after completion.

## Installation
1. Clone the repository:
   ```bash
   git clone https://github.com/mtmacc/MathQuizGame.git
   ```
2. Navigate to the project directory:
   ```bash
   cd MathQuizGame
   ```
3. Compile the source code:
   ```bash
   g++ MathQuiz.cpp -o MathQuiz
   ```
4. Run the program:
   ```bash
   ./MathQuiz  # On Linux/Mac
   MathQuiz.exe  # On Windows
   ```

## How to Play
1. Enter the number of questions you want to answer.
2. Select a difficulty level: Easy, Medium, Hard, or Mixed.
3. Choose an operation type: Addition, Subtraction, Multiplication, Division, or Mixed.
4. Solve the generated problems.
5. Get immediate feedback on correct/incorrect answers.
6. View your final score, including the number of correct and incorrect answers.
7. Choose to play again or exit the game.

## Example Run
```
How Many Questions do you want to answer? 5
Select Difficulty Level [1] Easy, [2] Medium, [3] Hard, [4] Mixed? 2
Select Operation Type [1] Add, [2] Subtract, [3] Multiply, [4] Divide, [5] Mixed? 5

Question [1/5]
12 + 8 = ?
Answer: 20
Correct :-)

Question [2/5]
45 - 22 = ?
Answer: 23
Incorrect :-(
The correct answer is: 23

Final Result: PASS :-)
```

## Requirements
- C++11 or later
- A C++ compiler (GCC, Clang, MSVC)

## Contribution
Contributions are welcome! Fork the repository, enhance the code, and submit a pull request.

## License
This project is open-source and available under the MIT License.

## Contact
For any inquiries or suggestions, feel free to reach out via GitHub.

