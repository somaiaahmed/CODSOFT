#include <bits/stdc++.h>
using namespace std;


char board[3][3];
char player1;
char player2;

void resetBoard(){
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            board[i][j]=' ';

        }
    }
}
void printBoard(){

    cout<<" "<<board[0][0]<<" | "<<board[0][1]<<" | "<<board[0][2]<<" ";
    cout<<"\n"<<"---"<<"|"<<"---"<<"|"<<"---"<<"\n";
    cout<<" "<<board[1][0]<<" | "<<board[1][1]<<" | "<<board[1][2]<<" ";
    cout<<"\n"<<"---"<<"|"<<"---"<<"|"<<"---"<<"\n";
    cout<<" "<<board[2][0]<<" | "<<board[2][1]<<" | "<<board[2][2]<<" ";
    //  cout<<"\n"<<"---"<<"|"<<"---"<<"|"<<"---"<<"\n";
}
int checkFreeSpace(){
    int freeSpace=9;
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(board[i][j]!=' ')
                freeSpace--;

        }
    }
    return freeSpace;
}
void player1Move(char c){
    int x,y;
    do{
        cout<<"\n"<<"Player "<<c<<" Enter row #(1-3):";

        cin>>x;
        x--;
        cout<<"\n"<<"Player "<<c<<" Enter column #(1-3):";
        cin>>y;
        y--;
        if(board[x][y]!=' ')
            cout<<"\n"<<"Invalid move!\n";
        else {
            board[x][y] = c;
            break;
        }
    }
    while (board[x][y]!=' ');

}
void player2Move(char c){
    int x,y;
    do{
        cout<<endl<<"Player "<<c<<" Enter row #(1-3):\n";
        cin>>x;
        x--;
        cout<<endl<<"Player "<<c<<" Enter column #(1-3):\n";
        cin>>y;
        y--;
        if(board[x][y]!=' ')
            cout<<endl<<"Invalid move!\n";
        else {
            board[x][y] = c;
            break;
        }
    }
    while (board[x][y]!=' ');
}
char checkWinner(){
    //check rows
    for(int i=0;i<3;i++) {
        if (board[i][0] == board[i][1] && board[i][0] == board[i][2]) {
            return board[i][0];

        }
    }
    //check columns
    for(int i=0;i<3;i++) {
        if (board[0][i] == board[1][i] && board[0][i] == board[2][i]) {
            return board[0][i];

        }
    }
    //check diagonals
    if (board[0][0] == board[1][1] && board[0][0] == board[2][2]) {
        return board[0][0];

    }
    //check diagonals
    if (board[0][2] == board[1][1] && board[0][2] == board[2][0]) {
        return board[0][2];

    }
    return ' ';


}
void printWinner(char winner){
    if(winner == player1){
        cout<<endl<<"PLAYER ONE WINS!\n";
    }
    else if(winner == player2){
        cout<<endl<<"PLAYER TWO WINS!\n";
    }
    else
        cout<<endl<<"IT'S A TIE!\n";


}



int main() {
    char winner=' ';
    char response;

    cout<<endl<<"Welcome to tic-tac-toe game!\n";
    start:
    {
        char winner=' ';
        char response;
        cout << endl<<"PLAYER ONE IS: ";
        cin >> player1;


        do { cout<<"\n"<<"PLAYER TWO IS: ";
            cin>>player2;}
        while(player1==player2);
        cout<<"\n";

        resetBoard();

        while (winner == ' ' && checkFreeSpace() > 0) {
            printBoard();

            player1Move(player1);
            printBoard();
            winner = checkWinner();
            if (winner != ' ' || checkFreeSpace() == 0)
                break;

            player2Move(player2);
            winner = checkWinner();
        }

        printBoard();
        printWinner(winner);

    }
    cout<<endl<<"Would you like to play again? (Y/N):";
    cin>>response;
    if(response=='Y')goto start;
    else cout<<endl<<"Thank you for playing!\n";
    return 0;
}
