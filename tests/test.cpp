#include"../lib/components.hpp"
using namespace std;
int main(int argc, char const *argv[])
{
	unordered_map<string,size_t> m{ptup("Priyansh Jain",100),ptup("Shivangi Varshney",0)};
	_SCORE s(m);
	auto s_ka_score_map=s.get();
	_SCORE s1(s_ka_score_map);
	s.printScoreCard();
	auto winner=s.winner();
	if(!s.tie())
	cout<<winner.first<<endl;
	return 0;
}
