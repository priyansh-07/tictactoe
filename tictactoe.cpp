#include<iostream>
#include<fstream>
using namespace std;

class score {
public:
	int scores[2];
	score() {
		scores[0]=0;
		scores[1]=0;
	}
	void winner();
};

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
		cout<<"\n\n=================== GAME INITIALIZED ===================\n\n";
	}
	void display();
	void start(score &s);
	int changeTurn(int a);
	string evaluate();
	void displayScores(score &s);	
};

void Tictactoe::display() {
	cout<<"\nPlayer "<<changeTurn(currentPlayer)<<"'s Turn"<<endl;
	cout<<"\t   1   2   3\n";
	for (int i=0; i<3; i++) {
		cout<<"\t"<<(i+1)<<"  ";
		for (int j=0; j<3; j++) {
			cout<<board[i][j];
			if (j<2)
				cout<<" | ";
		}
		if (i<2)
			cout<<"\n\t   ---------\n";
	}
	cout<<endl<<endl;	
}

int Tictactoe::changeTurn(int a) {
	if (a==1)
		return 2;
	return 1;
}

void Tictactoe::start(score &s) {
	int x, y;
	for (int i=0; i<9; i++) {
		currentPlayer=changeTurn(currentPlayer);
		while (true) {
			cout<<"Enter the co-ordinates (format: <row> <column> ) : ";			
			cin>>x>>y;
			cout<<endl<<"\n<------------------------------------------------------>"<<endl;			
			if (x>3 || y>3) {
				cout<<"Invalid Co-ordinates! Please try again!\n\n";
				continue;
			} 
			else if (boxes[x-1][y-1]==1) {
				cout<<"That box is already filled. Select another one!!\n";
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
			cout<<"Player 1 Wins!\n";			
			s.scores[0]++;
			displayScores(s);
			return;
		} else if (evaluate()=="O") {
			cout<<"Player 2 Wins!\n";
			s.scores[1]++;
			displayScores(s);
			return;
		} 
	}
	if (evaluate()=="-1") {
		cout<<"It's a Draw!\n";
		return;
	}	
}

string Tictactoe::evaluate() {
	if (board[0][0]==board[0][1] && board[0][1]==board[0][2])
		return board[0][0];
	else if (board[1][0]==board[1][1] && board[1][1]==board[1][2])
		return board[1][0];
	else if (board[2][0]==board[2][1] && board[2][1]==board[2][2])
		return board[2][0];
	else if (board[0][0]==board[1][0] && board[1][0]==board[2][0])
		return board[0][0];
	else if (board[0][1]==board[1][1] && board[1][1]==board[2][1])
		return board[0][1];
	else if (board[0][3]==board[1][3] && board[1][3]==board[2][3])
		return board[0][3];
	else if (board[0][0]==board[1][1] && board[1][1]==board[2][2])
		return board[0][0];
	else if	(board[0][2]==board[1][1] && board[1][1]==board[2][0])
		return board[0][2];
	else 
		return "-1";	
}

void Tictactoe::displayScores(score &s) {
	cout<<"\n\n======================== SCORES ========================";
	cout<<"\n\nPlayer 1 : "<<s.scores[0]<<"\n\nPlayer 2 : "<<s.scores[1]<<endl<<endl;
}

void score::winner() {
	if (this->scores[0] > this->scores[1])
		cout<<"\nPlayer 1 wins the session with a score of "<<this->scores[0]<<"-"<<this->scores[1]<<".\n\n";
	else if (this->scores[0] < this->scores[1])
		cout<<"\nPlayer 2 wins the session with a score of "<<this->scores[1]<<"-"<<this->scores[0]<<".\n\n";
	else 
		cout<<"\nThis Session is tied "<<this->scores[0]<<"-"<<this->scores[1];
}

void rate() {
	int rating;
	ofstream fout;
	fout.open("ratings.txt", ios::app);
	cout<<"On the scale of 1-10, how much would you like to rate our game? ";
	cin>>rating;
	fout<<rating<<endl;
	fout.close();
	cout<<"\nThank you for your response!\n"
}
 
int main() {
	char ch='y', c='y';
	int n;
	do {		
		cout<<"\nPress 1 to start a new session \n(When you start a new session all scores are set to zero)";
		cout<<"\nPress 2 to exit.\n";
		cin>>n;	

		switch (n) {
			case 1:	{
						score s1;
						do {
							Tictactoe t;		
							t.display();
							t.start(s1);				
							cout<<"\nDo you want to play again?(y/n)";
							cin>>ch;
						} while (ch=='y');
						s1.winner();
					}	
					break;
			case 2: cout<<"\n\nThank you for playing this game!\n\n";
					cout<<"Would you like to rate this game?(y/n)";
					cin>>c;
					if (c=='y')
						rate();
					return 0;
					break;
			default: cout<<"\nPlease Enter a valid Choice!";
		}
	} while(true);
return 0;
}