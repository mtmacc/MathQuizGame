#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
using namespace std;
enum enQuizzLvl { Easy = 1, Mid, Hard, Mix };
enum enOpType { Add = 1, Sup, Mul, Div, Miix };
char optypeAsStr(enOpType operation)
{
    char str[] = { '+','-','*','/' };
    if (operation == enOpType::Add)
    {
        return '+';
    }
    else if (operation == enOpType::Sup)
    {
        return '-';
    }
    else if (operation == enOpType::Mul)
    {
        return '*';
    }
    else
    {
        return '/';
    }
}
struct stQuizz
{
    short Questionnum = 0;
    enQuizzLvl lvlOfQuizz;
    enOpType opType;
    enOpType opQuestionType;
    int num1 = 0;
    int num2 = 0;
    int answer = 0;
    int result = 0;
    string answerMsg;
};
struct stResult
{
    string succOrFail;
    int questionCount;
    string quizzlvl;
    string opType;
    int correctCount;
    int faillCount;
};
int ReadNumber(string msg)
{
    int num;
    cout << msg << endl;
    cin >> num;
    return num;
}
int RandFunc(int from, int to)
{
    int num = rand() % (to - from + 1) + from;
    return num;
}
enQuizzLvl ChoiseQuestLvl()
{
    int num;
    do
    {
        num = ReadNumber("Enter Question Lvl [1] Easy, [2] Mid, [3] Hard, [4] Mix?");
        return (enQuizzLvl)num;
    } while (num > 4 || num < 0);
}

enOpType OpTypeFunc()
{
    int num;
    do
    {
        num = ReadNumber("Enter Operation Type [1] Add, [2] Sub, [3] Mul, [4] Div, [5] Mix ?");
        return (enOpType)num;
    } while (num > 5 || num < 1);
}
enOpType ChoiseOpType(enOpType optype1)
{
    // enOpType optype1;
    if (optype1 != enOpType::Miix)
    {
        return  optype1;
    }
    return (enOpType)RandFunc(1, 4);

}
int QuizzNum(enQuizzLvl lvlquizz)
{
    if (lvlquizz == enQuizzLvl::Easy)
    {
        return RandFunc(1, 10);
    }
    else if (lvlquizz == enQuizzLvl::Mid)
    {
        return RandFunc(10, 50);
    }
    else if (lvlquizz == enQuizzLvl::Hard)
    {
        return RandFunc(50, 99);
    }
    else {
        return RandFunc(1, 100);
    }
}
int Result(enOpType typeop, stQuizz quizznum)
{
    if (typeop == enOpType::Add)
    {
        return quizznum.num1 + quizznum.num2;
    }
    else if (typeop == enOpType::Sup)
    {
        return quizznum.num1 - quizznum.num2;
    }
    else if (typeop == enOpType::Mul)
    {
        return quizznum.num1 * quizznum.num2;
    }
    else
    {
        return quizznum.num1 / quizznum.num2;
    }
}
bool AnswerVsResult(stQuizz ansEqualRes)
{
    return ansEqualRes.answer == ansEqualRes.result;
}

string msgResult(bool anstrueOrFalse)
{
    if (anstrueOrFalse)
    {
        return "Right Answer";
    }
    else
    {
        return "Wrong Answer";
    }
}
void PrintFillQuizz(stQuizz quizzst)
{
    cout << "Question num [" << quizzst.Questionnum << "]" << endl;
    cout << quizzst.num1 << endl;
    cout << optypeAsStr(quizzst.opQuestionType) << endl;
    cout << quizzst.num2 << endl;
    cout << "________________\n";
}
void PrintResult(stQuizz quizzst)
{
    if (AnswerVsResult(quizzst))
    {
        cout << quizzst.answerMsg << endl;
        system("color 2F");
    }
    else
    {
        cout << quizzst.answerMsg << endl;
        system("color 4F");
        cout << "\a";
        cout << "Right Answer is = " << quizzst.result << endl;
    }
}
stQuizz FillQuizz(int nums[2])
{
    stQuizz QuizzSt;
    int questionCount = ReadNumber("Enter How many question");
    QuizzSt.lvlOfQuizz = ChoiseQuestLvl();
    QuizzSt.opType = OpTypeFunc();
    for (int i = 1; i <= questionCount; i++)
    {
        QuizzSt.Questionnum = i;
        QuizzSt.opQuestionType = ChoiseOpType(QuizzSt.opType);
        QuizzSt.num1 = QuizzNum(QuizzSt.lvlOfQuizz);
        QuizzSt.num2 = QuizzNum(QuizzSt.lvlOfQuizz);
        PrintFillQuizz(QuizzSt);
        QuizzSt.answer = ReadNumber(" ");
        QuizzSt.result = Result(QuizzSt.opQuestionType, QuizzSt);
        QuizzSt.answerMsg = msgResult(AnswerVsResult(QuizzSt));
        PrintResult(QuizzSt);
        cout << "\n___________________\n";
        if (AnswerVsResult(QuizzSt))
        {
            nums[0]++;
        }
        else
        {
            nums[1]++;
        }
    }
    return QuizzSt;
}
string SuccesOrFailld(int nums[2])
{
    if (nums[0] > nums[1])
    {
        return "u Pass The Exsam ";
    }
    return "u faild in The Exsam ";

}
void passOrFailedColor(int nums[2])
{
    if (nums[0] > nums[1])
    {
        system("color 2F");
    }
    else
    {
        system("color 4F");
        cout << "\a";
    }
}
string lvlAsStr(enQuizzLvl lvlstr)
{
    string str[] = { "Easy" , "Mid","Hard","Mix" };
    return str[lvlstr - 1];
}
string opAsStr(enOpType opstr)
{
    string str[] = { "Add","Sub","Mul","Div", "Mix" };
    return str[opstr - 1];
}

stResult FillResult(stQuizz quizzResult, int nums[2])
{
    stResult QuizzResult;
    QuizzResult.correctCount = nums[0];
    QuizzResult.faillCount = nums[1];
    QuizzResult.succOrFail = SuccesOrFailld(nums);
    passOrFailedColor(nums);
    QuizzResult.questionCount = quizzResult.Questionnum;
    QuizzResult.quizzlvl = lvlAsStr(quizzResult.lvlOfQuizz);
    QuizzResult.opType = opAsStr(quizzResult.opType);
    return QuizzResult;
}
void PrintResult(stResult Result)
{
    cout << Result.succOrFail << endl;
    cout << "_______________________\n";
    cout << "Question numbers = " << Result.questionCount << endl;
    cout << "Correct Answer =   " << Result.correctCount << endl;
    cout << "Wrong Answer =     " << Result.faillCount << endl;
    cout << "Question Level ==> " << Result.quizzlvl << endl;
    cout << "Operation Type ==> " << Result.opType << endl;
}
void ResetScreen()
{
    system("cls");
    system("color 0F");
}

int main()
{
    srand(time(0));
    char playAgain = 'y';
    do
    {
        ResetScreen();
        int nums[2] = { 0 , 0 };
        PrintResult(FillResult(FillQuizz(nums), nums));
        cout << "Do u wanna play again [y] = yes [n] = no \n";
        cin >> playAgain;
    } while (playAgain == 'Y' || playAgain == 'y');


    return 0;
}




//#include<iostream>
//using namespace std;
//
//enum enQuestionsLevel {
//    EasyLevel = 1,
//    MedLevel = 2,
//    HardLevel = 3,
//    Mix = 4
//};
//
//enum enOperationType {
//    Add = 1,
//    Sub = 2,
//    Mult = 3,
//    Div = 4,
//    MixOp = 5
//};
//
//string GetOpTypeSymbol(enOperationType OpType) {
//    switch (OpType) {
//    case enOperationType::Add:
//        return "+";
//    case enOperationType::Sub:
//        return "-";
//    case enOperationType::Mult:
//        return "x";
//    case enOperationType::Div:
//        return "/";
//    default:
//        return "Mix";
//    }
//}
//
//string GetQuestionLevelText(enQuestionsLevel QuestionLevel) {
//    string arrQuestionLevelText[4] = { "Easy", "Med", "Hard", "Mix" };
//    return arrQuestionLevelText[QuestionLevel - 1];
//}
//
//int RandomNumber(int From, int To) {
//    int randNum = rand() % (To - From + 1) + From;
//    return randNum;
//}
//
//void SetScreenColor(bool Right) {
//    if (Right)
//        system("color 2F");
//    else {
//        system("color 4F");
//        cout << "\a";
//    }
//}
//
//short ReadHowManyQuestions() {
//    short NumberOfQuestions;
//    do {
//        cout << "How Many Questions do you want to answer? ";
//        cin >> NumberOfQuestions;
//    } while (NumberOfQuestions < 1 || NumberOfQuestions > 10);
//    return NumberOfQuestions;
//}
//
//enQuestionsLevel ReadQuestionsLevel() {
//    short QuestionLevel = 0;
//    do {
//        cout << "Enter Questions Level [1] Easy, [2] Med, [3] Hard, [4] Mix? ";
//        cin >> QuestionLevel;
//    } while (QuestionLevel < 1 || QuestionLevel > 4);
//    return (enQuestionsLevel)QuestionLevel;
//}
//
//enOperationType ReadOpType() {
//    short OpType;
//    do {
//        cout << "Enter Operation Type [1] Add, [2] Sub, [3] Mul, [4] Div, [5] Mix? ";
//        cin >> OpType;
//    } while (OpType < 1 || OpType > 5);
//    return (enOperationType)OpType;
//}
//
//struct stQuestion {
//    int Number1 = 0;
//    int Number2 = 0;
//    enOperationType OperationType;
//    enQuestionsLevel QuestionLevel;
//    int CorrectAnswer = 0;
//    int PlayerAnswer = 0;
//    bool AnswerResult = false;
//};
//
//struct stQuizz {
//    stQuestion QuestionList[100];
//    short NumberOfQuestions;
//    enQuestionsLevel QuestionsLevel;
//    enOperationType OpType;
//    short NumberOfWrongAnswers = 0;
//    short NumberOfRightAnswers = 0;
//    bool isPass = false;
//};
//
//int SimpleCalculator(int Number1, int Number2, enOperationType OpType) {
//    switch (OpType) {
//    case enOperationType::Add:
//        return Number1 + Number2;
//    case enOperationType::Sub:
//        return Number1 - Number2;
//    case enOperationType::Mult:
//        return Number1 * Number2;
//    case enOperationType::Div:
//        return Number1 / Number2;
//    default:
//        return Number1 + Number2;
//    }
//}
//
//enOperationType GetRandomOperationType() {
//    int Op = RandomNumber(1, 4);
//    return (enOperationType)Op;
//}
//
//stQuestion GenerateQuestion(enQuestionsLevel QuestionLevel, enOperationType OpType) {
//    stQuestion Question;
//    if (QuestionLevel == enQuestionsLevel::Mix) {
//        QuestionLevel = (enQuestionsLevel)RandomNumber(1, 3);
//    }
//    if (OpType == enOperationType::MixOp) {
//        OpType = GetRandomOperationType();
//    }
//    Question.OperationType = OpType;
//    switch (QuestionLevel) {
//    case enQuestionsLevel::EasyLevel:
//        Question.Number1 = RandomNumber(1, 10);
//        Question.Number2 = RandomNumber(1, 10);
//        Question.CorrectAnswer = SimpleCalculator(Question.Number1, Question.Number2, Question.OperationType);
//        Question.QuestionLevel = QuestionLevel;
//        return Question;
//    case enQuestionsLevel::MedLevel:
//        Question.Number1 = RandomNumber(10, 50);
//        Question.Number2 = RandomNumber(10, 50);
//        Question.CorrectAnswer = SimpleCalculator(Question.Number1, Question.Number2, Question.OperationType);
//        Question.QuestionLevel = QuestionLevel;
//        return Question;
//    case enQuestionsLevel::HardLevel:
//        Question.Number1 = RandomNumber(50, 100);
//        Question.Number2 = RandomNumber(50, 100);
//        Question.CorrectAnswer = SimpleCalculator(Question.Number1, Question.Number2, Question.OperationType);
//        Question.QuestionLevel = QuestionLevel;
//        return Question;
//    }
//    return Question;
//}
//
//void GenerateQuizzQuestions(stQuizz& Quizz) {
//    for (short Question = 0; Question < Quizz.NumberOfQuestions; Question++) {
//        Quizz.QuestionList[Question] = GenerateQuestion(Quizz.QuestionsLevel, Quizz.OpType);
//    }
//}
//
//int ReadQuestionAnswer() {
//    int Answer = 0;
//    cin >> Answer;
//    return Answer;
//}
//
//void PrintTheQuestion(stQuizz& Quizz, short QuestionNumber) {
//    cout << "\n";
//    cout << "Question [" << QuestionNumber + 1 << "/" << Quizz.NumberOfQuestions << "] \n\n";
//    cout << Quizz.QuestionList[QuestionNumber].Number1 << endl;
//    cout << Quizz.QuestionList[QuestionNumber].Number2 << " ";
//    cout << GetOpTypeSymbol(Quizz.QuestionList[QuestionNumber].OperationType);
//    cout << "\n_________" << endl;
//}
//
//void CorrectTheQuestionAnswer(stQuizz& Quizz, short QuestionNumber) {
//    if (Quizz.QuestionList[QuestionNumber].PlayerAnswer != Quizz.QuestionList[QuestionNumber].CorrectAnswer) {
//        Quizz.QuestionList[QuestionNumber].AnswerResult = false;
//        Quizz.NumberOfWrongAnswers++;
//        cout << "Wrong Answer :-( \n";
//        cout << "The right answer is: ";
//        cout << Quizz.QuestionList[QuestionNumber].CorrectAnswer;
//        cout << "\n";
//    }
//    else {
//        Quizz.QuestionList[QuestionNumber].AnswerResult = true;
//        Quizz.NumberOfRightAnswers++;
//        cout << "Right Answer :-) \n";
//    }
//    cout << endl;
//    SetScreenColor(Quizz.QuestionList[QuestionNumber].AnswerResult);
//}
//
//void AskAndCorrectQuestionListAnswers(stQuizz& Quizz) {
//    for (short QuestionNumber = 0; QuestionNumber < Quizz.NumberOfQuestions; QuestionNumber++) {
//        PrintTheQuestion(Quizz, QuestionNumber);
//        Quizz.QuestionList[QuestionNumber].PlayerAnswer = ReadQuestionAnswer();
//        CorrectTheQuestionAnswer(Quizz, QuestionNumber);
//    }
//    Quizz.isPass = (Quizz.NumberOfRightAnswers >= Quizz.NumberOfWrongAnswers);
//}
//
//string GetFinalResultsText(bool Pass) {
//    if (Pass)
//        return "PASS :-)";
//    else
//        return "Fail :-(";
//}
//
//void PrintQuizzResults(stQuizz Quizz) {
//    cout << "\n";
//    cout << "______________________________\n\n";
//    cout << " Final Results is " << GetFinalResultsText(Quizz.isPass);
//    cout << "\n______________________________\n\n";
//    cout << "Number of Questions: " << Quizz.NumberOfQuestions << endl;
//    cout << "Questions Level: " << GetQuestionLevelText(Quizz.QuestionsLevel) << endl;
//    cout << "OpType: " << GetOpTypeSymbol(Quizz.OpType) << endl;
//    cout << "Number of Right Answers: " << Quizz.NumberOfRightAnswers << endl;
//    cout << "Number of Wrong Answers: " << Quizz.NumberOfWrongAnswers << endl;
//    cout << "______________________________\n";
//}
//
//void PlayMathGame() {
//    stQuizz Quizz;
//    Quizz.NumberOfQuestions = ReadHowManyQuestions();
//    Quizz.QuestionsLevel = ReadQuestionsLevel();
//    Quizz.OpType = ReadOpType();
//    GenerateQuizzQuestions(Quizz);
//    AskAndCorrectQuestionListAnswers(Quizz);
//    PrintQuizzResults(Quizz);
//}
//
//void ResetScreen() {
//    system("cls");
//    system("color 0F");
//}
//
//void StartGame() {
//    char PlayAgain = 'Y';
//    do {
//        ResetScreen();
//        PlayMathGame();
//        cout << endl << "Do you want to play again? Y/N? ";
//        cin >> PlayAgain;
//    } while (PlayAgain == 'Y' || PlayAgain == 'y');
//}
//
//int main() {
//    srand((unsigned)time(NULL));
//    StartGame();
//    return 0;
//}
