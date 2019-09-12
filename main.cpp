#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>

using namespace std;

void SeparateRows(){ //separate rows
    cout << "~~~~~" << endl;
}

int main() {
    vector<vector<int> > space{ { 0, 0, 0 },
                                { 0, 0, 0 },
                                { 0, 0, 0 } }; //matrix to represent user guess
    int TargetRow;
    int TargetColumn; //mark target location

    int UserRow;
    int UserColumn; //mark user guess

    int NumbersOfTrials; //number of trials

    int breaker = 0; //indicator for loop to break

    srand(time(0)); //random seed

    TargetColumn = rand() % 2;
    TargetRow = rand() % 2; // initialize target location

    for (int i = 0; i < 3; ++i) { //print initial matrix
        for (int j = 0; j < 3; ++j) { //print row
            cout << " ";
            if(j < 2){
                cout << "!"; //separate grids
            }
        }
        cout << endl;
        if(i < 2){
            SeparateRows();
        }
    }

    cout << "How many times would you like to try?" << endl;
    cin >> NumbersOfTrials; // input numbers of trials from user

    for(int k = 0; k < NumbersOfTrials; k++){
        cout << "Where will you fire at?" << endl;
        cout << "Row:";
        cin >> UserRow;
        cout << "Column:";
        cin >> UserColumn; //input user guess of location
        cout << endl;

        //assume the nice user wouldn't enter numbers greater than 3
        space[UserRow - 1][UserColumn - 1] += 1; //apply change to the matrix

        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                if(UserRow - 1 == TargetRow && UserColumn - 1 == TargetColumn && UserRow - 1 == i && UserColumn - 1 == j){
                    cout << "O"; //print "O" for correct guess
                    breaker +=1;
                }
                else if(space[i][j] > 0){
                    cout << "X"; //print "X" for wrong guesses
                }
                else{
                    cout << " "; //print " " for black grids
                }
                if(j < 2){
                    cout << "!"; //separate grids
                }
            }
            cout << endl;
            if(i < 2){
                SeparateRows();
            }
        }
        if(breaker > 0){ //break from loop if correct guess were made
            cout << "Ahhh! You sunk my battleship!";
            break;
        }
    }
    return 0;
}