#include<bits/stdc++.h>

using namespace std;
#define SIDE 3
#define PLAYER1MOVE 'X'
#define PLAYER2MOVE 'O'





bool rowCrossed(char board[][SIDE]){

    for(int i=0;i<SIDE;i++){
        if(board[i][0]==board[i][1] && board[i][1]==board[i][2] && board[i][1] != '*'){
            return(true);
        }
    }
    return false;

}
bool colCrossed(char board[][SIDE]){
    for(int i=0;i<SIDE;i++){
        if(board[0][i]==board[1][i] && board[1][i]==board[2][i] && board[1][i] != '*'){
            return(true);
        }
    }
    return false;

}
bool diagnolCrossed(char board[][SIDE]){
  
        if(board[0][0]==board[1][1] && board[1][1]==board[2][2] && board[1][1] != '*'){
            return(true);
        }
        if(board[0][2]==board[1][1] && board[1][1]==board[2][0] && board[1][1] != '*'){
            return(true);
        }
    
    return false;

}


bool gameOver(char board[][SIDE]){

return(rowCrossed(board)||colCrossed(board)||diagnolCrossed(board));
   

}



void declareWinner(string WhoseTurn,string player1,string player2){

if(WhoseTurn==player1)
{
    cout<<player1<<" has Won";
}
else if(WhoseTurn==player2)
{
    cout<<player2<<" has Won";
}


}


void showInstruction(){
    cout<<"Choose a cell from 1 to 9 \n";

    cout<<"\t\t\t 1 | 2 | 3\n";
    cout<<"\t\t\t-----------\n";
    cout<<"\t\t\t 4 | 5 | 6\n";
    cout<<"\t\t\t-----------\n";
    cout<<"\t\t\t 7 | 8 | 9\n\n";
}

void initialise(char board[][SIDE]){
    for(int i=0;i<SIDE;i++){
        for(int j=0;j<SIDE;j++){
            board[i][j]='*';
        }
    }
}

void showBoard(char board[][SIDE]){

    cout<<"\t\t\t"<<board[0][0]<<" | "<<board[0][1]<<" | "<<board[0][2]<<"\n";
    cout<<"\t\t\t-----------\n";
    cout<<"\t\t\t"<<board[1][0]<<" | "<<board[1][1]<<" | "<<board[1][2]<<"\n";
    cout<<"\t\t\t-----------\n";
    cout<<"\t\t\t"<<board[2][0]<<" | "<<board[2][1]<<" | "<<board[2][2]<<"\n";

}


void playTTT(string WhoseTurn,string player1,string player2){
    char board[SIDE][SIDE];
    int moveIndex=0,x=0,y=0;

    initialise(board);
    showInstruction();

    while(gameOver(board)== false && moveIndex != SIDE*SIDE){


        int n;
        if(WhoseTurn==player1){

            cout<<player1<< "can enter in following position\n";

            for(int i=0;i<SIDE;i++){
                for(int j=0;j<SIDE;j++){
                    if(board[i][j] == '*'){
                        cout<<(i*3+j)+1<<" ";

                    }

                    
                }
            }
            cout<<"\nEnter the poistion\n";
            cin>>n;
            n--;
            x=n/SIDE;
            y=n%SIDE;

            if(board[x][y]=='*' && n<9 && n>=0){

                board[x][y]=PLAYER1MOVE;
                cout<<player1<<" has put "<<PLAYER1MOVE<<" into "<<n+1<<" position\n\n";
                showBoard(board);
                moveIndex++;
                WhoseTurn=player2;

        



            }
            else if(board[x][y]!='*' && n<9 && n>=0){
                cout<<"poistion is occupied\n";

            }
            else if(n<0 && n>8){

            cout<<"Invalid poistion\n";

            }


        }

       else if(WhoseTurn==player2){
              cout<<player2<<" can enter in following poistions\n";

            for(int i=0;i<SIDE;i++){
                for(int j=0;j<SIDE;j++){
                    if(board[i][j] == '*'){
                        cout<<(i*3+j)+1<<" ";

                    }

                    
                }
            }
            cout<<"\nEnter the poistion\n";
            cin>>n;
            n--;
            x=n/SIDE;
            y=n%SIDE;

            if(board[x][y]=='*' && n<9 && n>=0){

                board[x][y]=PLAYER2MOVE;
                cout<<player1<<" has put "<<PLAYER2MOVE<<" into "<<n+1<<" poistion\n\n";
                showBoard(board);
                moveIndex++;
                WhoseTurn=player1;

        



            }
            else if(board[x][y]!='*' && n<9 && n>=0){
                cout<<"poistion is occupied\n";

            }
            else if(n<0 && n>8){

            cout<<"Invalid poistion\n";

            }

        }




    }
if (gameOver(board) == false && moveIndex == SIDE * SIDE)
cout<<"it's a draw\n";
else
{
if (WhoseTurn == player1)
WhoseTurn = player2;
else if (WhoseTurn == player2)
WhoseTurn = player1;
declareWinner(WhoseTurn,player1,player2);
}


}









int main(){

   string c,player1,player2;

printf("\n===================================================================\n\n");
printf("\t\t\t Tic-Tac-Toe\n");
printf("\n===================================================================\n\n");




cout<<"Enter Player Name\n";
cout<<"\n-----------------\n\n";
cout<<"First Player Name : \n";
cin>>player1;
cout<<"Second Player Name : \n";
cin>>player2;
cout<<"Who wants to play first, Please Enter Name\n";
cin>>c;


if(c==player1){
    playTTT(player1,player1,player2);
}
else if(c==player2){
        playTTT(player2,player1,player2);
}
else{
cout<<("Invalid Name Entered");
}





return 0;
}