#ifndef COMPONENTS_HPP
#define COMPONENTS_HPP
#ifndef IOSTREAM
#include<iostream>
#endif
#ifndef EXCEPTION
#include<exception>
#endif
#ifndef UTILITY
#include<utility>
#endif
#ifndef MAP
#include<unordered_map>
#endif
#define PLAYER_COUNT 0x2
typedef std::pair<std::string,size_t> ptup;
typedef std::pair<short,short> coords;
class _SCORE{
	std::unordered_map<std::string,size_t> scores;
public:
	/**
	 * CONSTRUCTORS
	 **/
	_SCORE(): scores{ptup("PLAYER 1",0),ptup("PLAYER 2",0)}{}
	_SCORE(const ptup& p1,const ptup& p2):scores{p1,p2}{}
	_SCORE(const std::string& name1,const std::string& name2): scores{ptup(name1,0),ptup(name2,0)}{}
	explicit _SCORE(std::unordered_map<std::string,size_t>& m)
	{
		if(m.size()>PLAYER_COUNT){
			std::cerr<<"Invalid initialization score map enterd"<<std::endl;
			scores=std::unordered_map<std::string,size_t>{ptup("1",0),ptup("2",0)};
		}
		else
			scores=m;
	}
	/**
	 * Methods
	 * */
	const std::unordered_map<std::string,size_t> get() const
	{
		return scores;
	}
	const size_t get(const std::string& player) const
	{
		const std::unordered_map<std::string,size_t>::const_iterator it=scores.find(player);
		if(it!=scores.end())
			return it->second;
		std::cerr<<"Invalid player entered!"<<std::endl;
		return 0;
	}
	const bool tie() const
	{
		const auto s1=scores.begin()->second,s2=(++scores.begin())->second;
		return s1==s2;
	}
	const ptup winner() const
	{
		const auto s1=scores.begin(),s2=(++scores.begin());
		//std::cout<<"S1: "<<s1->second<<", S2: "<<s2->second<<std::endl;
		if(s1->second>s2->second)
			return *s1;
		else if(s1->second<s2->second)
			return *s2;
		return ptup("MATCH TIE!",0);
	}
	void printScoreCard() const
	{
		std::cout<<"=============================================="<<std::endl
		<<"|\t\tPLAYER \t\t|"<<"\t\tSCORE\t\t|"<<std::endl;
		for(auto i: scores)
			std::cout<<"|\t"<<i.first<<"\t\t\t"<<i.second<<std::endl;
		std::cout<<"=============================================="<<std::endl;
	}
	void update(const ptup& p)
	{
		if(scores.find(p.first)!=scores.end())
			scores[p.first]=p.second;
		else
			std::cerr<<"Invalid player requested to update"<<std::endl;
	}
	void update(const std::string& name,const size_t& score)
	{
		if(scores.find(name)!=scores.end())
			scores[name]=score;
		else
			std::cerr<<"Invalid player requested to update"<<std::endl;
	}
	void update(const std::string& name,size_t (*fn)(const size_t&))
	{
		auto match=scores.find(name);
		if(match!=scores.end())
			scores[name]=fn(match->second);
	}
	void increase(const std::string& name,const size_t& diff=1)
	{
		auto match=scores.find(name);
		if(match!=scores.end())
			scores[name]=(match->second)+diff;
	}
	void decrease(const std::string& name,const size_t& diff=1)
	{
		auto match=scores.find(name);
		if(match!=scores.end()){
			if(match->second-diff<0){
				std::cerr<<"Invalid score updation"<<std::endl;
				return;
			}
			scores[name]=(match->second)-diff;
		}
	}
	void reset()
	{
		scores.begin()->second=0;
		(++scores.begin())->second=0;
	}
};
class _BOARD{
	char board[3][3];
public:
	_BOARD():board{{0,0,0},{0,0,0},{0,0,0}}{}
	bool fill(const coords& c,const char& ch)
	{
		try{
			if(all_filled()||check_diag()||check_lines())
				return false;
			if(c.first<=3&&c.first>=0&&c.second<=3&&c.first>=0){
				if(board[c.first][c.second]==0){
					if(ch=='X'||ch=='0')
						board[c.first][c.second]=ch;
					else throw std::runtime_error("Invalid char for fill");
				}else throw std::runtime_error("Trying to fill at a preoccupied position");
			}
			else throw std::runtime_error("Filling out of board");
		}catch(const std::exception& e){
			print();
			std::cout<<"Coords are: ("<<c.first<<", "<<c.second<<") "
			<<" and char is: "<<ch<<" ("<<int(ch)<<')'<<std::endl;
			std::cerr<<"Error: "<<e.what()<<std::endl;
			return false;
		}
		return true;
	}
	char check_diag() const
	{
		if(board[0][0]==board[1][1] && board[0][0]==board[2][2])		//1st diagonal
			return board[0][0];
		if(board[0][2]==board[1][1] && board[0][2]==board[2][0])		//2nd diagonal
			return board[0][2];
		return 0;
	}
	char check_lines() const
	{
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
	return 0;
	}
	auto get() const
	{
		return board;
	}
	bool all_filled() const
	{
		for(int x=0;x<3;x++)
			for(int y=0;y<3;y++)
				if(board[x][y]==0)
					return 0;
		return 1;
	}
	void print() const
	{
		for(int x=0;x<3;x++){
		for(int y=0;y<3;y++){
			std::cout<<'\t';
			if(board[x][y])
				std::cout<<board[x][y];
			else
				std::cout<<'_';
		}
		std::cout<<std::endl<<std::endl;
	}
	}
	void reset()
	{
		for(int x=0;x<3;x++)
			for(int y=0;y<3;y++)
				board[x][y]=0;
	}
};
struct _PLAYER{
	std::string name;
	char sign;
	size_t moves;
	_PLAYER(const std::string& n,const char& s):name(n),sign(s),moves(0){}
};
class _GAMEPLAY{
	_SCORE* scores;
	_BOARD* board;
	_PLAYER player1,player2;
	bool turn,endb;
public:
	_GAMEPLAY():scores(nullptr),board(nullptr),
	player1("PLAYER 1",'X'),player2("PLAYER 2",'0'),turn(false),endb(false){}
	_GAMEPLAY(const std::string& p1,const std::string& p2):scores(nullptr),
	board(nullptr),player1(p1,'X'),player2(p2,'0'),turn(false),endb(false)
	{
		if(player1.name=="")
			player1.name="Player 1";
		if(player2.name=="")
			player2.name="Player 2";
	}
	void start()
	{
		scores=new _SCORE(player1.name,player2.name);
		board=new _BOARD();
	}
	void fill(const coords& c,const char& ch)
	{
		try{
			if(board){
				if(board->fill(c,ch)) {
					turn = !turn;
				}
				char diags = board->check_diag(), lines = board->check_lines();
				if (diags || lines) {
					std::cout << diags << lines << " won!" << std::endl;
					endb=true;
					if(turn)
						scores->increase(player1.name);
					else
						scores->increase(player2.name);
				}
			}
			else throw std::runtime_error("Game not yet started!");
		}catch(const std::exception& e){
			std::cerr<<"Error: "<<e.what()<<std::endl;
		}
	}
	void move(const coords& c)
	{
		char s;
		if(!turn)
			s=player1.sign;
		else
			s=player2.sign;
		fill(c,s);
	}
	void print() const
	{
		try {
			if(board)
				board->print();
			else throw std::runtime_error("Game not yet started!");
		}catch (const std::exception& e){
			std::cerr<<"Error: "<<e.what()<<std::endl;
		}
	}
	void scoreCard() const
	{
		try {
			if(scores)
				scores->printScoreCard();
			else throw std::runtime_error("Game not yet started!");
		}catch (const std::exception& e){
			std::cerr<<"Error: "<<e.what()<<std::endl;
		}
	}
	const std::string which() const
	{
		if(turn)
			return player2.name;
		return player1.name;
	}
	bool end() const
	{
		return endb||board->all_filled();
	}
	 std::string winner() const
	{
		if(!end())
			return "The game is in progress";
		return scores->winner().first;
	}
};
#endif /*COMPONENTS_HPP*/
/**
 * Things to do
 * standardize the library by #defining vars like BOARD_COL_MAX and writing function and constructor overloads
 * check and solve for any loop holes and vulnerabilities in the code
 * write deconstructors
 * write .gitignore
 * solve the 'mysterious win' bug
**/