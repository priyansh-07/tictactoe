#include<iostream>
#include "lib/components.hpp"
using namespace std;
class Tictactoe {
public:
	string board[3][3];
	int boxes[3][3];
	int currentPlayer = 2;
	Tictactoe() {
		for (int i=0; i<3; i++) {
			for (int j=0; j<3; j++) {
				board[i][j]=" ";
				boxes[i][j]=0;
			}
		}
		cout<<endl<<endl<<"=================== GAME INITIALIZED ==================="<<endl<<endl;
	}
	void display();
	void start(_SCORE &s);
	int changeTurn(int a);
	string evaluate();
	void displayScores(_SCORE &s);	
};

void Tictactoe::display() {
	cout<<endl<<"Player "<<changeTurn(currentPlayer)<<"'s Turn"<<endl;
	cout<<"\t   1   2   3"<<endl;
	for (int i=0; i<3; i++) {
		cout<<"\t"<<(i+1)<<"  ";
		for (int j=0; j<3; j++) {
			cout<<board[i][j];
			if (j<2)
				cout<<" | ";
		}
		if (i<2)
			cout<<endl<<"\t   ---------"<<endl;
	}
	cout<<endl<<endl;	
}

int Tictactoe::changeTurn(int a) {
	if (a==1)
		return 2;
	return 1;
}

void Tictactoe::start(_SCORE &s) {
	int x, y;
	for (int i=0; i<9; i++) {
		currentPlayer=changeTurn(currentPlayer);
		while (true) {
			cout<<"Enter the co-ordinates (format: <row> <column> ) : ";			
			cin>>x>>y;
			cout<<endl<<endl<<"<------------------------------------------------------>"<<endl;			
			if (x>3 || y>3) {
				cout<<"Invalid Co-ordinates! Please try again!"<<endl<<endl;
				continue;
			} 
			else if (boxes[x-1][y-1]==1) {
				cout<<"That box is already filled. Select another one!!"<<endl;
				continue;
			} 
			else {
				boxes[x-1][y-1]=1;
				break;
			}
		}		
		
		if (currentPlayer==1)
			board[x-1][y-1]="X";
		else if(currentPlayer==2)
			board[x-1][y-1]="O";
		display();
		if (evaluate()=="X") {
			cout<<"Player 1 Wins!"<<endl;			
			s.increase("0");
			displayScores(s);
			return;
		} else if (evaluate()=="O") {
			cout<<"Player 2 Wins!"<<endl;
			s.increase("1");
			displayScores(s);
			return;
		} 
	}
	if (s.tie()) {
		cout<<"It's a Draw!"<<endl;
		return;
	}	
}

string Tictactoe::evaluate() {
	if (board[0][0]==board[0][1] && board[0][1]==board[0][2])
		return board[0][0];		//1st row
	else if (board[1][0]==board[1][1] && board[1][1]==board[1][2])
		return board[1][0];		//2nd row
	else if (board[2][0]==board[2][1] && board[2][1]==board[2][2])
		return board[2][0];		//3rd row
	else if (board[0][0]==board[1][0] && board[1][0]==board[2][0])
		return board[0][0];		//1st col
	else if (board[0][1]==board[1][1] && board[1][1]==board[2][1])
		return board[0][1];		//2nd col
	else if (board[0][2]==board[1][2] && board[1][2]==board[2][2])
		return board[0][2];		//3rd col
	else if (board[0][0]==board[1][1] && board[1][1]==board[2][2])
		return board[0][0];		//1st diag
	else if	(board[0][2]==board[1][1] && board[1][1]==board[2][0])
		return board[0][2];		//2nd diag
	else 
		return "-1";	
}

void Tictactoe::displayScores(_SCORE &s) {
	cout<<endl<<endl<<"SCORES";
	//cout<<endl<<endl<<"Player 1 : "<<s.scores[0]<<endl<<endl<<"Player 2 : "<<s.scores[1]<<endl<<endl;
	s.printScoreCard();
}

 
int main() {
	char ch='y', c='y';
	int n;
	do {		
		cout<<endl<<"Press 1 to start a new session "<<endl<<"(When you start a new session all scores are set to zero)";
		cout<<endl<<"Press 2 to exit."<<endl;
		cin>>n;	

		switch (n) {
			case 1:	{
						_SCORE s1;
						do {
							Tictactoe t;		
							t.display();
							t.start(s1);				
							cout<<endl<<"Do you want to play again?(y/n)";
							cin>>ch;
						} while (ch=='y');
						s1.winner();
					}	
					break;
			case 2: cout<<endl<<endl<<"Thank you for playing this game!"<<endl<<endl;
					return 0;
			default: cout<<endl<<"Please Enter a valid Choice!";
		}
	} while(true);
return 0;
}
