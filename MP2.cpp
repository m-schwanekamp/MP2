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
void displayScore(int score1);
bool isTurnScoreLost(int die1value, int die2value);
bool isTotalScoreLost(int die1value, int die2value);
bool isWinningScore(int score);
char getUserInput(void);

int main () {
    int die1value; //Value of each dice
    int die2value;
    int D1; //Each dice being rolled
    int D2;
    int score1_total = 0; //Player 1 total score
    int score2_total = 0; //Player 2 total score
    int score1 = 0; //Player 1 score
    int score2 = 0; //Player 2 score
    int player1_turn;
    int player2_turn;
    char continuePlay;

    //Choose a player to start.
    cout << "Player 1 rolls first.\n";
    srand(time(0));

    cout << "Would you like to play? (R/S): ";
    while (cin >> continuePlay) {
        if (continuePlay == 'r' || continuePlay == 'R') {
            do {
                D1 = rollDie(); //Generates each dice roll number
                D2 = rollDie();
                displayRollResults(D1, D2); 
                isTurnScoreLost(D1, D2);
                if (isTurnScoreLost(die1value, die2value) == true) {
                    cout << "Player 1 score is " << score1 << endl;
                }
                if (isTurnScoreLost(die1value, die2value) == false) {
                    cout << "Player 1 score is " << score1 << endl;
                }
                cout << "Do you want to roll again (R/S): ";
                cin >> continuePlay;
                if (continuePlay == 's' || continuePlay == 'S') {
                    return 0;
                }
            } while (score1 < 100);
        }
    }
}

int rollDie(void) {
    const int high_die = 6; //Parameters for number of sides on dice
    const int low_die = 1;
    return rand() % high_die + low_die;
}

void displayRollResults(int die1, int die2) {
    cout << "Player 1 rolled a " << die1 << " and a " << die2 << endl;
}

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


   /* while (cin >> continuePlay){
        if(continuePlay == 'r') {
            do {
                die1value = rand() % high_die + low_die;
                die2value = rand() % high_die + low_die;
                cout << "Player 1 rolled a " << die1value << " and a " << die2value << endl;
                if (die1value == 1 || die2value == 1) {
                    score1 = 0;
                }
                if (die1value == 1 && die2value == 1) {
                    score = 0;
                }
                else if (die1value != 1 && die2value != 1) {
                    score1 = die1value + die2value;
                    score += score1;
                    cout << "score is " << score << endl;
                }
                cout << "Would you like to roll again (R/S): ";
                cin >> continuePlay;
            } while (score < 100);
        }
        
    }
}

    if (score1 < 100) {
            cout << "Roll again? (R/S): ";
            cin >> continuePlay;
            while (continuePlay == 'R' || continuePlay == 'r'){
            do {
        die1value = rand() % high_die + low_die;
        die2value = rand() % high_die + low_die;
        cout << "Player 1 rolled a " << die1value << " and a " << die2value << endl;
        if (die1value == 1 || die2value == 1) {
            score1 = 0;
        }
        if (die1value == 1 && die2value == 1) {
            score = 0;
        }
        else if (die1value != 1 && die2value != 1) {
            score1 = die1value + die2value;
            score += score1;
        }
    
        cout << "score is " << score << endl;
    
            } 
    
}

*/
