/*
Nick Bennett
Lab 5 October 27, 2021
The objective of the lab is to make a number guessing game that chooses a number between 0 to 100 and the user has 20 guesses to guess the correct number. Another part of the lab is to be creative in making the statements that are outputted to the screen when the user is wrong. Also having telling the user how many times they won and lost over the time that they were playing the game.
*/
#include <iostream>
#include <stdlib.h> // needed for srand function
#include <time.h>

using namespace std;

void GB(); // GB = game banner
bool NumCompare(); // generates random number that is choosen and keeps take of number of guesses
void WGMessage(); // wrong guess function
void WMess(); // win message function
void AGame(); // another game function
bool NewGame(); // new game function
void SB(int totalGames, int wins, int losses); // SB = scoreboard , scoreboard function
void GOver(); // function that plays the ending message , GOver = gameover
int main()
{
    bool gLoop = true; // gLoop = game loop
    int TG = 0; // TG = total games
    int wins = 0;
    int losses = 0;

    do
    {
        ++TG; // counting of total games played
        SB(TG, wins, losses); // prints initial scoreboard

        GB(); // prints welcome message/rules of the game

        if (NumCompare()) // if NumCompare returns true, the player has guess random number correctly and wins
        {
            ++wins;
            WMess(); // outputs success message
            AGame(); // prompts player for another game
            if (NewGame()) // if the user chooses a new game, NewGameMenu() returns true
            {
                gLoop = true; // loop control set to true
                continue; // new game is started
            }
            else // NewGame() returns false and player has chosen to end program execution
            {
                gLoop = false; // loop control is set to false
                continue; // game loop is exited
            }
        }
        else // player has lost the game by exceeding 20 guesses
        {
            ++losses; // loss count added
            if (NewGame()) // if player chooses a new game, NewGame() returns true
            {
                gLoop = true; // loop set to true
                continue; // new game is created
            }
            else // NewGame() if comes back as false the program will quit
            {
                gLoop = false; //loop set to false
                continue; //game loop has quit
            }
        }
    } while (gLoop);

    GOver(); // prints parting message
    SB(TG, wins, losses); // outputs final score board of the games played

    cout << "Hope you play again soon!" << endl << "Goodbye!";


    return 0;
}

void SB(int TG, int wins, int losses) // scoreboard function
{
    cout << "_____________________" << endl;
    cout << "Stats so far: ";
    cout << "Number of games: " << TG << endl;
    cout << "Games won: " << wins << endl;
    cout << "Games lost: " << losses << endl;
    cout << "_____________________" << endl << endl;
}

void GB() // game banner function
{
    cout << "Rules of the Game: " << endl;
    cout << "__________________" << endl;
    cout << "The computer has generated a random number between 1 and 100" << endl;
    cout << "You have 20 guesses to guess what the randomized number is." << endl;
    cout << "Enter your first guess:";
}

bool NumCompare() // random number generator and number of guesses function
{
    
    int ranNum; // stores the valve of the random number
    srand(int(time(NULL))); // random number generator
    ranNum = rand() % 100 + 1; // generates random numbers between 0 and 100.

    int gLeft = 19; // shows the player how many guesses that they have left for the game that is being played
    int gCount = 1; // starts the loop with

    int guess;
    cin >> guess;

    do
    {
        if (!cin) // when the player puts in a invalid guess this will run
        {
            cout << "You entered an invalid data type!" << endl;
            cout << "Your input should be only numbers between 1 and 100." << endl;
            cin.clear(); //clears the flag on the input stream
            cin.ignore(1000,'\n');

            cout << "Try again: ";
            cin >> guess;
        }
        else if ((isdigit(guess) && guess <= 0) || guess > 100) // checks if the valve that was inputed again is out or in the range that it is supposed to be
        {
            cout << "____________________________________________" << endl;
            cout << "That number is out of range!" << endl;
            cout << "Your input should be between 1 and 100 only!" << endl;
            cout << "____________________________________________" << endl;
            cout << "Try again: ";
            cin >> guess;
        }
        else if (guess != ranNum) // player enters incorrect guess
        {
            ++gCount;
            WGMessage(); // wrong guess returns a failure message

            // how many guesses the player has for each game
            if (gLeft > 1)
                cout << "You have " << gLeft << " guesses left" << endl;
            else
                cout << "You have " << gLeft << " guess left!" << endl;
            gLeft--;

            cout << "Please try again: " << endl;
            cin >> guess;
        }
        else // player guesses random number.
        {
            return true; //NumCompare returns a true value to the main function
        }
    } while (gCount < 20);

    cout << "_____________________________________________________" << endl;
    cout << "You are out of guesses!" << endl;
    cout << "In case you were wondering, the secret number was: " << ranNum << endl;
    cout << "_____________________________________________________";
    AGame(); // outputs a random message prompting the user for another game.
    return false; // returns false back to the main function

}

void WGMessage() // wrong guess function
{
    int fMess = 0; // used to generate random success messages , fMess = Fail Message

    srand(int(time(NULL))); // random number generator
    fMess = rand() % 10 + 1; // uses random number that the switch statement will use to

    switch (fMess) // switch statment with all the wrong guess messages
    {
    case 1:    cout << endl << "Sorry but that is not correct." << endl;
        break;

    case 2:    cout << endl << "Try again!" << endl;
        break;

    case 3:    cout << endl << "Wrong guess" << endl;
        break;

    case 4:    cout <<  endl << "You'll need to try again." << endl;
        break;

    case 5:    cout << endl << "You really thought you would be right, that's funny!" << endl;
        break;

    case 6:    cout << endl << "Look at that, wrong again." << endl;
        break;

    case 7:    cout << endl << "How many times do I have to tell you that you're wrong." << endl;
        break;

    case 8:    cout << endl << "This is just sad at this point." << endl;
        break;

    case 9:    cout << endl << "What's new! Wrong again!"<< endl ;
        break;

    case 10: cout << endl << "You're really not very good at this game! :(" << endl;
        break;

    default:    cout << "Other error";
    }
}

void WMess()
{
    int sMessage = 0; // used to generate random failure messages in the switch statement

    srand(int(time(NULL))); // random number generator
    sMessage = rand() % 10 + 1; // generates random numbers between 1 and 10

    switch (sMessage)
    {
    case 1:
        cout << endl << "You got it right!" << endl;
        break;

    case 2:
        cout << endl << "Nice job!" << endl;
        break;

    case 3:
        cout << endl << "Good job!" << endl;
        break;

    case 4:
        cout << endl << "You guessed the right number!" << endl;
        break;

    case 5:
        cout << endl << "You did it!" << endl;
        break;

    case 6:
        cout << endl << "Execellent" << endl;
        break;

    case 7:
        cout << endl << "Nice guess!" << endl;
        break;

    case 8:
        cout << endl << "Surprisingly you guessed the right number!" << endl;
        break;

    case 9:
        cout << endl << "You beat me, this time!" << endl;
        break;

    case 10:
        cout << endl << "Good getting the right number!" << endl;
        break;

    default:
        cout << "Other error";
    }
}

void AGame() //AGame = another game
{
    int MenuP = 0; // used to generate random failure messages in the switch statement below

    srand(int(time(NULL))); // random number generator
    MenuP = rand() % 10 + 1; // generates random numbers between 1 and 10

    switch (MenuP) // whatever the MenuP come out as for 1 to 10 it will choose the case that is inside of the switch statement
    {
    case 1:
        cout << endl <<"Do you want to play again?" << endl;
        break;

    case 2:
        cout << endl << "I know that you want to play again!" << endl;
        break;

    case 3:
        cout << endl <<"Select an option from the following menu." << endl;
        break;

    case 4:
        cout << endl <<"Press 2 at the next menu, if you don't want to continue to play." << endl;
        break;

    case 5:
        cout << endl <<"You can choose to play again by pressing 1 in the next menu." << endl;
        break;

    case 6:
        cout << endl << "How about another game?" << endl;
        break;

    case 7:
        cout << endl << "Thanks for playing!" << endl;
        break;

    case 8:
        cout << endl << "I know that you want to play again!" << endl;
        break;

    case 9:
        cout << endl << "You can't be tired of me yet!" << endl;
        break;

    case 10:
        cout << endl << "Another game?" << endl;
        break;

    default:
        cout << "Error";
    }
}

bool NewGame()
{
    char choice; // stores user choice
    bool sLoop = true; // loop for do while loop
    bool nG = true; // used to see if the player is telling the computer to push a new game or not. nG = New Game

    do {
        cout << endl <<"Please make a selection from the menu below:" << endl; // outputting to the screen what the player would like to do
        cout << "New Game = 1" << endl;
        cout << "Quit Program = 2" << endl;
        cout << "Enter your choice: ";
        cin >> choice; // user puts in 1 or 2 to start or quit the game
        cout << endl << endl << endl; // pushes the board down the complier if the user says that they want to play again

        switch (choice)
        {
        case '1':
            nG = true; // return value nG
            sLoop = false; // breaks menu loop
            break;

        case '2':
            nG = false; // return value for nG
            sLoop = false; // breaks menu loop
            break;

        default:    cout << "Invaild choice - you must enter either 1 or 2" << endl;
            break;
        }
    } while (sLoop);

    return nG; // returns to the main if the player wants to play another game or not
}

void GOver() // outputs to the screen that the player has quit the game and the game is done
{
    cout << "You have choosen to quit the game." << endl;
    cout << "Here are your final stats:" << endl << endl;
}
