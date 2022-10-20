// MP2- Roll'em Pigs! Madalynn Schwanekamp
#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

int rollDie(void);
void displayRollResults(int die1, int die2);
bool isTurnScoreLost(int die1value, int die2value);
bool isTotalScoreLost(int die1value, int die2value);
bool isWinningScore(int score);
char getUserInput(void);

int main() {
    int die1value; //Value of each dice
    int die2value;
    int die1; //Each dice being rolled
    int die2;
    int score1_total = 0; //Total score for each player
    int score2_total = 0;
    int score1 = 0; //Turn score for each player
    int score2 = 0;

    //Begin game. Player 1 will roll first and the game will 
    //continue until either the user or the computer reaches
    //a minimum of 100 points. 
    //In a turn, if a single one is rolled, then the score for that 
    //turn is 0. If two 1's are rolled, then that player's total 
    //score is 0. Otherwise the score for each trun is added to the 
    //total score.
    srand(time(0));
    cout << "Player 1 rolls first.\n";
    cout << "Would you like to play? (R/S): ";
    while (score1_total <= 100 && score2_total <= 100) {
    
        score1 = 0;
        while (getUserInput() != 's') {
            //Player 1 loop for that player's turn. This will loop
            //until a 1 is rolled or the player reaches 100 points.
            
            cout << "Player 1 turn" << endl;
            die1 = rollDie(); //Generates each dice roll number
            die2 = rollDie();
            displayRollResults(die1, die2); //Displays each dice roll 
            score1 = die1 + die2;
            
            if (isTurnScoreLost(die1, die2)) { //Tests for turn score lost
                score1 = 0;
                break;
            }
            score1_total += score1;
            if (isTotalScoreLost(die1, die2)) { //Tests for total score lost
                score1_total = 0;
                break;
            }

            if (isWinningScore(score1_total)) { //Tests if player has won
                cout << "Player 1 wins!\n" << "Game over." << endl;
                return 0;
            }

            cout << "Turn score is " << score1 << endl; //Output for Player 1
            cout << "Total score is " << score1_total << endl;
            cout << "Do you want to roll again (R/S): ";

        }

        score2 = 0;
        while (score2 < 20) {
            //This is the loop for the computer's turn. The computer
            //plays until a 1 is rolled, or it reaches 20 points in a
            //single turn. Also ends if the computer reaches 100 points.
       
            cout << "Computer turn" << endl;
            die1 = rollDie(); //Generates new numbers for computer
            die2 = rollDie();
            displayRollResults(die1, die2);
            score2 += die1 + die2;
            
            if (isTurnScoreLost(die1, die2)) {
                score2 = 0;
                break;
            }
            
            if (isTotalScoreLost(die1, die2)) {
                score2_total = 0;
                break;
            }

            if (isWinningScore(score2_total)) {
                cout << "Computer wins!\n" << "Game over." << endl;
                return 0;
            }

            cout << "Turn score is " << score2 << endl; //Output for computer
            cout << "Total score is " << score2_total << endl;
        }
        if (score2 >= 20) {
            break;
        }
        score2_total += score2;
        cout << "Turn score is " << score2 << endl;
        cout << "Total score is " << score2_total << endl;
    }
}

//These functions tie into the main function by generating random
//numbers and testing for true or false throughout the game. They 
//also determine correct user input for each human turn.

int rollDie(void) {
    //This function generates a random number for each dice.
    const int high_die = 6; //Parameters for number of sides on dice
    const int low_die = 1;
    return rand() % high_die + low_die;
}

void displayRollResults(int die1, int die2) {
    //Function displays the number on each dice being rolled.
    cout << "Player rolled a " << die1 << " and a " << die2 << endl;

}

bool isTurnScoreLost(int die1value, int die2value) {
    //Determines through true or false whether each turn's
    //score is kept or lost.
    if (die1value == 1 || die2value == 1) {
        return true;
    }
    else return false;
}

bool isTotalScoreLost(int die1value, int die2value) {
    //Determines if a player's total score has been lost or kept.
    if (die1value == 1 && die2value == 1) {
        return true;
    }
    else return false;
}

bool isWinningScore(int score) {
    //Dtermines winner by choosing the player
    //that has at least 100 points first.
    if (score >= 100) {
        return true;
    }
    else return false;
}
char getUserInput(void) {
    char a; //Input variable for human player
    cin >> a;
    return a;
}

