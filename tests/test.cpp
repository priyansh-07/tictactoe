#include"../lib/components.hpp"
using namespace std;
int main(int argc, char const *argv[])
{
	string name1,name2;
	cout<<"Enter the name of first player: ";
	getline(cin,name1);
	cout<<"Enter the name of second player: ";
	getline(cin,name2);
	_GAMEPLAY game(name1,name2);
	game.start();
	game.print();
	short x=0,y=0;
	while (!game.end()){
		cout<<"Enter coordinates for "<<game.which()<<"'s turn: ";
		cin>>x>>y;
		game.move(coords(x-1,y-1));
		game.print();
	}
	game.scoreCard();
	cout<<game.winner()<<endl;
	return 0;
}
