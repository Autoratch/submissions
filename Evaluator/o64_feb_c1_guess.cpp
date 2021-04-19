#include "guess.h"
#include <bits/stdc++.h>
using namespace std;

const int N = 1 << 10;

string s[2] = {"RCRCXXXCR","RBCXXCRB"};
vector<pair<int,char> > as;
vector<int> now,nex;
int va[N];

int find_answer(int N, int K) 
{
	if(K==1)
	{
		for(int i = 0;i < N;i++) if(s[0][i%9]=='R') as.push_back({i,'R'});
		char ret = ask(as);
		as.clear();
		for(int i = 0;i < 9;i++) s[0][i] = ' ';
		if(ret=='R')
		{
			s[0][0] = 'R',s[0][2] = 'X',s[0][8] = 'C';
			for(int i = 0;i < N;i++) if(i%9==0 or i%9==7) as.push_back({i,'R'});
		}
		else if(ret=='C')
		{
			s[0][1] = 'R',s[0][3] = 'C',s[0][7] = 'X';
			for(int i = 0;i < N;i++) if(i%9==1 or i%9==2) as.push_back({i,'R'});
		}
		else 
		{
			s[0][4] = 'R',s[0][5] = 'C',s[0][6] = 'X';
			for(int i = 0;i < N;i++) if(i%9==4) as.push_back({i,'R'});
		}
		ret = ask(as);
		for(int i = 0;i < N;i++) if(s[0][i%9]==ret) now.push_back(i);
		while(now.size()>1)
		{
			as.clear();
			for(int i = 0;i < now.size();i++) 
				if(i%3==0) as.push_back({now[i],'R'}),va[now[i]] = 'R'; 
				else if(i%3==1) as.push_back({now[i]-1,'R'}),va[now[i]] = 'C';
				else va[now[i]] = 'X';
			ret = ask(as);
			nex.clear();
			for(int x : now) if(va[x]==ret) nex.push_back(x);
			swap(now,nex);
		}
		return now[0];
	}
	else
	{
		for(int i = 0;i < N;i++) if(s[1][i%8]=='R' or s[1][i%8]=='B') as.push_back({i,s[1][i%8]});
		char ret = ask(as);
		as.clear();
		for(int i = 0;i < N;i++) if(s[1][i%8]==ret) now.push_back(i);
		while(now.size()>1)
		{
			as.clear();
			for(int i = 0;i < now.size();i++) 
				if(i%4==0) as.push_back({now[i],'R'}),va[now[i]] = 'R';
				else if(i%4==1) as.push_back({now[i],'B'}),va[now[i]] = 'B';
				else if(i%4==2) as.push_back({now[i]-1,'R'}),va[now[i]] = 'C';
				else va[now[i]] = 'X';
			ret = ask(as);
			nex.clear();
			for(int x : now) if(va[x]==ret) nex.push_back(x);
			swap(now,nex);
		}
		return now[0];
	}
}
