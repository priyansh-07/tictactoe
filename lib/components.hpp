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
class _SCORE{
	std::unordered_map<std::string,size_t> scores;
public:
	/**
	 * CONSTRUCTORS
	 **/
	_SCORE(): scores{ptup("1",0),ptup("2",0)}{}
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
	void printScoreCard()
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
};
#endif /*COMPONENTS_HPP*/