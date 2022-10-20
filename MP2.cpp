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
    int score1_total = 0; //Total score for each player
    int score2_total = 0; 
    int score1_org = 0; //Starting total score for each player
    int score2_org = 0;
    int score1 = 0; //Turn score for each player
    int score2 = 0; 
    int player1_turn;
    int player2_turn;
    char continuePlay; //Input from human player

    //Begin game. Player 1 will roll first and the game will 
    //continue until either the user or the computer reaches
    //a minimum of 100 points. 
    //In a turn, if a single one is rolled, then the score for that 
    //turn is 0. If two 1's are rolled, then that player's total 
    //score is 0. Otherwise the score for each trun is added to the 
    //total score.
    cout << "Player 1 rolls first.\n";
    cout << "Would you like to play? (R/S): ";
    while (score1_total <= 100 && score2_total <= 20) {
       
        score1 = 0;
        while (getUserInput() != 's') {
      

            srand(time(0));
            cout << "Player 1 turn" << endl;
            die1 = rollDie(); //Generates each dice roll number
            die2 = rollDie();
            displayRollResults(die1, die2); //Displays each dice roll 
            score1 = die1 + die2;
            score1_total += score1;    
            if(isTurnScoreLost(die1,die2)){
                score1 = 0;
                break;
            }
            if(isTotalScoreLost(die1, die2)) {
                score1_total = 0;
                break;
            }

            if(isWinningScore(score1_total)) {
                cout << "Player 1 wins!\n" << "Game over." << endl;
                return 0;
            }

            cout << "Turn score is " << score1 << endl;
                    
            cout << "Total score is " << score1_total << endl;
       
            cout << "Do you want to roll again (R/S): ";
             
        }

        cout << "Turn score is " << score1 << endl;         
        cout << "Total score is " << score1_total << endl;            
        cout << "Do you want to roll again (R/S): ";
        
        while (score2_total < 20) {
            srand(time(0));
            cout << "Player 2 turn" << endl;
            die1 = rollDie();
            die2 = rollDie();
            displayRollResults(die1, die2);
            score2 = die1 + die2;
            score2_total += score2;
            if (isTurnScoreLost(die1, die2)) {
                score2 = 0;
                break;
            }
            
            if (isTotalScoreLost(die1, die2)) {
                score2_total = 0;
                break;
            }

            if(isWinningScore(score2_total)) {
            cout << "Player 2 wins!\n" << "Game over." << endl;
            return 0;
            }

            cout << "Turn score is " << score2 << endl;
                    
            cout << "Total score is " << score2_total << endl;
        }

        cout << "Turn score is " << score2 << endl;         
        cout << "Total score is " << score2_total << endl;            
    }
}

char getUserInput(void) {
    char a;
    cin >> a;
    return a;
}
int rollDie(void) {
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


