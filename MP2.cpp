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
    int score1_org = 0;
    int score2_org = 0;
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
    while (score1_total <= 100 && score2_total <= 20) {
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
                    score1 = score1 + isTurnScoreLost(die1, die2);
                    score1_total = isTotalScoreLost(die1, die2);
                } while (score1_total < 100);
            }
            if (score1_total >= 100) {
                cout << "Player 1 wins!\n" << "Game Over." << endl;
                return 0;
            }
        }
       /*
        if (score1_total < 100 && score2_total < 100) {
            do {
                cout << "Player 2 turn" << endl;
                die1 = rollDie();
                die2 = rollDie();
                displayRollResults(die1, die2);
                isTurnScoreLost(die1, die2);
                if (die1 != 1 && die2 != 1) {
                    score2_total += die1 + die2;
                    cout << "Total score is " << score2_total << endl;
                }
                if (die1 == 1 || die2 == 1) {
                    score2_total = score2_total;
                    cout << "Total score is " << score2_total << endl;
                    break;
                }
                if (die1 == 1 && die2 == 1) {
                    score2_total = score2_org;
                    cout << "Total score is " << score2_total << endl;
                    break;
                }
            } while (score2_total < 20);
        }
        if (score2_total >= 100) {
            cout << "Player 2 wins!\n" << "Game over." << endl;
        }
        */
    }
}

int rollDie(void) {
    const int high_die = 6; //Parameters for number of sides on dice
    const int low_die = 1;
    return rand() % high_die + low_die;
}

void displayRollResults(int die1, int die2) {
    cout << "Player 1 rolled a " << die1 << " and a " << die2 << endl;
    //cout << "Player 2 rolled a " << die1 << "and a " << die2 << endl;
}

bool isTurnScoreLost(int die1value, int die2value) {
    //Below are the parameters  for the score that is returned
    //during each turn depending on what is rolled.
    int score1 = 0;
    int score2 = 0;
    if (die1value == 1 || die2value == 1) {
        score1 = 0;
       // score2 = 0;
    }
    else if (die1value != 1 && die2value != 1) {
        score1 = die1value + die2value;
        //score2 = die1value + die2value;
    }
    cout << "Turn score is " << score1 << endl;
    //cout << "Turn score is " << score2 << endl;
}

bool isTotalScoreLost(int die1value, int die2value) {
    int score1_total;
    int score1_org = 0;
    char continuePlay;
    if (die1value != 1 && die2value != 1) {
        score1_total += die1value + die2value;
        cout << "Total score is " << score1_total << endl; 
        cout << "Do you want to roll again (R/S): ";
        cin >> continuePlay;
        if (continuePlay == 's' || continuePlay == 'S') {
            return 0;
        }
    }
    if (die1value == 1 || die2value == 1) {
        score1_total = score1_total;
        cout << "Total score is " << score1_total << endl;
    }
    else if (die1value == 1 && die2value == 1) {
        score1_total = score1_org;
        cout << "Total score is " << score1_total << endl;
    }
    cout << "Total score is " << score1_total << endl;
}

