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

int main () {
    int die1value; //Value of each dice
    int die2value;
    int die1; //Each dice being rolled
    int die2;
    int score1_total = 0; //Player 1 total score
    int score2_total = 0; //Player 2 total score
    int score1 = 0; //Player 1 score
    int score2 = 0; //Player 2 score
    int player1_turn;
    int player2_turn;
    char continuePlay;

    //Begin game. Player 1 will roll first and the game will 
    //continue until either the user or the computer reaches
    //a minimum of 100 points. 
    //In a turn, if a single one is rolled, then the score for that 
    //turn is 0. If two 1's are rolled, then that player's total 
    //score is 0. Otherwise the score for each trun is added to the 
    //total score.
    while (score1_total != 100 && score2_total != 100) {
        cout << "Player 1 rolls first.\n";
        srand(time(0));

        cout << "Would you like to play? (R/S): ";
        while (cin >> continuePlay) {
            if (continuePlay == 'r' || continuePlay == 'R') {
                do {
                    cout << "Player 1 turn" << endl;
                    die1 = rollDie(); //Generates each dice roll number
                    die2 = rollDie();
                    displayRollResults(die1, die2); //Displays each dice roll 
                    /* isTurnScoreLost(die1, die2);
                    cout << "Turn score is " << isTurnScoreLost(die1value, die2value) << endl;
                    */
                    if (die1 != 1 && die2 != 1) {
                        score1 = die1 + die2;
                        score1_total += score1;
                    }
                    if (die1 == 1 || die2 == 1) {
                        score1 = 0;
                        score1_total += score1;
                        
                    }
                    else if (die1 == 1 && die2 == 1) {
                        score1_total = 0;
                        
                    }
                    cout << "Total score is " << score1_total << endl;
                    cout << "Do you want to roll again (R/S): ";
                    cin >> continuePlay;
                    if (continuePlay == 's' || continuePlay == 'S') {
                        return 0;
                    }
                    

                } while (score1_total < 100);

            }
        }
    }
}

char getUserInput(void) {
    
}

int rollDie(void) {
    const int high_die = 6; //Parameters for number of sides on dice
    const int low_die = 1;
    return rand() % high_die + low_die;
}

void displayRollResults(int die1, int die2) {
    cout << "Player 1 rolled a " << die1 << " and a " << die2 << endl;
}
/*
bool isTurnScoreLost(int die1value, int die2value) {
    bool result = true;
    int score1 = 0;
    if (die1value == 1 || die2value == 1) {
        score1 = 0;
        result = false;
    }
    else if (die1value != 1 && die2value != 1) {
        score1 += die1value + die2value;
        result = true;
    }
    return result;
}
*/

