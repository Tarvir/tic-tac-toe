#include<iostream>
#include<array>
#include<string>
using namespace std;
std::array<std::array<char,3>,3>space={{{'1','2','3'},{'4','5','6'},{'7','8','9'}}};
int row ,column;
char turn='X';
bool tie=false;
string player1;
string player2;
int choice;
//************************************************************
//         STRUCTURE OF PROJECT
//************************************************************
void printboard()
{
   // std::array<std::array<int,3>,3>space={{{1,2,3},{4,5,6},{7,8,9}}};
    cout<<"     |      |     \n";      
    cout<<"  "<<space[0][0]<<"  |  " <<space[0][1]<<"   | " <<space[0][2] <<"  \n";
    cout<<"_____|______|______\n";
    cout<<"     |      |     \n";
    cout<<"  " <<space[1][0]<<"  |  "<<space[1][1]<<"   | " <<space[1][2]<<"  \n";
    cout<<"_____|______|______\n";
    cout<<"     |      |     \n";
    cout<<"  "<<space[2][0]<<"  |    "<<space[2][1]<<" | " <<space[2][2]<<"  \n";
    cout<<"     |      |     \n";
    cout<<"\n";
    cout<<"----------------------------------------------------------\n";

}
//***************************************************************
//      ASSIGNING SYMBOL TO A POSITION
//***************************************************************
void player_turn()
{
    int digit;

    if (turn=='X')
    {
        cout<<player1<<" "<<" Please enter Digit Its your TURN (X):-";
        cin>>digit; 
    }
    if (turn=='0')
    {
        
        cout<<player2<<" "<<"Please enter Digit Its your TURN (0):-";
        cin>>digit;
    }
    

    switch (digit)
    {
    case 1:
        row=0;
        column=0;
        break;
    case 2:
        row=0;
        column=1;
        break;
    case 3:
        row=0;
        column=2;
        break;    
    case 4:
        row=1;
        column=0;
        break;
    case 5:
        row=1;
        column=1;
        break;
    case 6:
        row=1;
        column=2;
        break;
    case 7:
        row=2;
        column=0;
        break;
    case 8:
        row=2;
        column=1;
        break;
    case 9:
        row=2;
        column=2;
        break;        
    default:
        cout<<"Invalid Move";
    }
if (turn=='X' && space[row][column]!='X' && space[row][column]!='0')
{
    
    space[row][column]='X';
    turn='0';
}
else if (turn=='0' && space[row][column]!='X' && space[row][column]!='0')
{
    
    space[row][column]='0';
    turn='X';
}
else{
    cout<<"There is no empty space"<<endl;
    player_turn();
}

printboard();

}
//***********************************************************************
//      CONDITION CHECK
//***********************************************************************
bool checkwin()
{
    for(int i=0;i<3;i++)
        if (space[i][0]==space[i][1]&& space[i][0]==space[i][2] || space[0][i]==space[1][i]&& space[0][i]==space[2][i])
        {
            return true;
        }
        if(space[0][0]==space[1][1]&& space[0][0]==space[2][2] || space[0][2]==space[1][1]&& space[0][2]==space[2][0])
        {
            return true;
        }
    
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(space[i][j]!='X'&& space [i][j]!='0'){
                return false;
            }

        }
    }
    tie=true;
    return false;
}

int main()
{
    
    cout<<"Enter the Name of Player1:- \n";
    getline(cin,player1);
    cout<<"Enter the Name of Player2:-\n";
    getline(cin,player2);
    cout<<player1<<" "<<"Is Player1 so they will play First \n";
    cout<<player2<<" "<<"Is Player2 so they will play Second \n";
     while(!checkwin()){
        printboard();
        player_turn();
        checkwin();

     }
     if(turn=='X'&& tie==false)
     {
        cout<<player1<<"WINS!"<<endl;
     }
     else if(turn=='0'&& tie==false)
     {
        cout<<player2<<"WINS!"<<endl;
     }
     else if(checkwin()==false){
        cout<<"Its Draw"<<endl;
     }
}