#include <iostream>
#include <string>
using namespace std;

enum enGameChoice { stone = 1, paper = 2, scissors = 3 };

enum enWinner { Player1 = 1, Computer = 2, Draw = 3 };

struct stRoundInfo
{
    short RoundNumber = 0;          // Round number.
    enGameChoice Player1Choice;     // Player's choice.
    enGameChoice ComputerChoice;    // Computer's choice.
    enWinner Winner;                // Stores the winner of the round.
    string WinnerName;               // Stores the winner's name.
};

struct stGameResults
{
    short GameRounds = 0;        // Number of rounds played.
    short Player1WinTimes = 0;   // Count of Player1's wins.
    short ComputerWinTimes = 0;  // Count of Computer's wins.
    short DrawTimes = 0;         // Number of rounds that ended in a draw.
    enWinner GameWinner;         // Stores the overall game winner.
    string WinnerName = "";      // Name of the game winner.
};

struct stWinners
{
    int user = 0;
    int comp = 0;
    int draw = 0;
};

int RandomNumber(int From, int To)
{
    // Calculate a random number using the modulus operator.
    // rand() % (To - From + 1) produces a value between 0 and (To - From).
    // Adding From shifts the value into the range [From, To].
    int randNum = rand() % (To - From + 1) + From;
    return randNum;  // Return the generated random number.
}

int ReadNumber()
{
    int Number;  // Variable to store user input.

    // Prompt the user to enter a floating-point number.
    cout << "how many rounds 1 to 10? ";
    cin >> Number;  // Read input from the user.

    return Number;  // Return the input number.
}

void resetScreen()
{
    system("cls");
    system("color 07");
}

short readHowManyRounds()
{
    short gameRounds = 1;

    do
    {
        cout << "how many rounds 1 to 10? \n";
        cin >> gameRounds;
    } while (gameRounds < 1 || gameRounds>10);
    return gameRounds;
}

string tabs(int num)
{
    string t = "";
    for (int i = 1;i < num;i++)
    {
        t = t + "\t";
    }
    return t;
}

void showGameOverScreen()
{
    cout << tabs(2) << "-------------------------------------\n\n";
    cout << tabs(2) << "            +++ Game Over +++\n";
    cout << tabs(2) << "-------------------------------------\n\n";
}

void setWinnerScreenColor(enWinner winner)
{
    switch (winner)
    {
    case enWinner::Player1:
        system("color 2F");
        break;
    case enWinner::Computer:
        system("color 4F");
        cout << "\a";
        break;
    default:
        system("color 6F");
        break;
    }
}

void showFinalGameResults(stGameResults gameResults)
{
    cout << tabs(2) << "-----------------[game result]------------\n\n";
    cout << tabs(2) << "game rounds         : " << gameResults.GameRounds << endl;
    cout << tabs(2) << "player 1 won times  : " << gameResults.Player1WinTimes << endl;
    cout << tabs(2) << "computer won times  : " << gameResults.ComputerWinTimes << endl;
    cout << tabs(2) << "draw times          : " << gameResults.DrawTimes << endl;
    cout << tabs(2) << "final winner        : " << gameResults.WinnerName << endl;
    cout << tabs(2) << "------------------------------------------" << endl;
    setWinnerScreenColor(gameResults.GameWinner);
}

enGameChoice readPlayer1Choice()
{
    short choice;
    do
    {
        cout << "\nYour Choice: [1]:Stone, [2]:Paper, [3]:Scissors? ";
        cin >> choice;
    } while (choice > 3 || choice < 1);
    return (enGameChoice)choice;
}

enGameChoice getComputerChoice()
{
    return (enGameChoice)RandomNumber(1, 3);
}

enWinner whoWonTheRound(stRoundInfo roundInfo)
{
    // If both choices are the same, it's a draw.
    if (roundInfo.Player1Choice == roundInfo.ComputerChoice)
        return enWinner::Draw;

    // Determine the winner based on game rules.
    switch (roundInfo.Player1Choice)
    {
    case enGameChoice::stone:
        return (roundInfo.ComputerChoice == enGameChoice::paper) ? enWinner::Computer : enWinner::Player1;
    case enGameChoice::paper:
        return (roundInfo.ComputerChoice == enGameChoice::scissors) ? enWinner::Computer : enWinner::Player1;
    case enGameChoice::scissors:
        return (roundInfo.ComputerChoice == enGameChoice::stone) ? enWinner::Computer : enWinner::Player1;
    }
}

string winnerName(enWinner winner)
{
    string arr[3] = { "player1", "computer", "no winner" };
    return arr[winner - 1];
}

string ChoiceName(enGameChoice Choice)
{
    string arrGameChoices[3] = { "Stone", "Paper", "Scissors" };
    return arrGameChoices[Choice - 1];
}

void printRoundResults(stRoundInfo RoundInfo)
{
    cout << "\n____________ Round [" << RoundInfo.RoundNumber << "] ____________\n\n";
    cout << "Player1 Choice: " << ChoiceName(RoundInfo.Player1Choice) << endl;
    cout << "Computer Choice: " << ChoiceName(RoundInfo.ComputerChoice) << endl;
    cout << "Round Winner   : [" << RoundInfo.WinnerName << "]\n";
    cout << "_________________________________________\n" << endl;
    setWinnerScreenColor(RoundInfo.Winner);
}

enWinner whoWonTheGame(short Player1WinTimes, short ComputerWinTimes)
{
    if (Player1WinTimes > ComputerWinTimes) return enWinner::Player1;
    else if (ComputerWinTimes > Player1WinTimes) return enWinner::Computer;
    else return enWinner::Draw;

}

stGameResults fillGameResults(int gameRounds, short player1winTimes, short computerWinTimes, short drawTimes)
{
    stGameResults gameResults;
    gameResults.GameRounds = gameRounds;
    gameResults.Player1WinTimes = player1winTimes;
    gameResults.ComputerWinTimes = computerWinTimes;
    gameResults.DrawTimes = drawTimes;
    gameResults.GameWinner = whoWonTheGame(player1winTimes, computerWinTimes);
    gameResults.WinnerName = winnerName(gameResults.GameWinner);
    return gameResults;


}

stGameResults playGame(short numOfRounds)
{
    stRoundInfo roundInfo;
    short Player1WinTimes = 0, ComputerWinTimes = 0, DrawTimes = 0;

    for (short gameRound = 1;gameRound <= numOfRounds;gameRound++)
    {
        cout << "\nRound [" << gameRound << "] begins:\n";
        roundInfo.RoundNumber = gameRound;
        roundInfo.Player1Choice = readPlayer1Choice();
        roundInfo.ComputerChoice = getComputerChoice();
        roundInfo.Winner = whoWonTheRound(roundInfo);
        roundInfo.WinnerName = winnerName(roundInfo.Winner);
        if (roundInfo.Winner == enWinner::Player1)
            Player1WinTimes++;
        else if (roundInfo.Winner == enWinner::Computer)
            ComputerWinTimes++;
        else
            DrawTimes++;

        printRoundResults(roundInfo);
    }

    return fillGameResults(numOfRounds, Player1WinTimes, ComputerWinTimes, DrawTimes);
}


void startGame()
{
    char playAgain = 'y';
    do
    {
        resetScreen();
        stGameResults gameResults = playGame(readHowManyRounds());
        showGameOverScreen();
        showFinalGameResults(gameResults);
        cout << "do you want to play again (y/n)? ";
        cin >> playAgain;
    } while (playAgain == 'y' || playAgain == 'Y');

}



int main()
{
    srand((unsigned)time(NULL));

    startGame();

}


