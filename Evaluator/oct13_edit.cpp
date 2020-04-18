#include <bits/stdc++.h>
using namespace std;
 
const int N = 1e5 + 5;
 
int m,am;
string s[N];
int fw[N],bw[N],st,en,idx;
 
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
 
	cin >> m;
 
	for(int i = 0;i < m;i++) fw[i] = bw[i] = -1;
 
	for(int i = 0;i < m;i++)
	{
		char c;
		cin >> c;
		if(c=='i')
		{
			cin >> s[am];
			if(st==-1)
			{
				st = en = am;
				idx = am;
			}
			else if(idx==en)
			{
				fw[en] = am;
				bw[am] = en;
				en = am;
				idx = am;
			}
			else if(idx==-1)
			{
				bw[st] = am;
				fw[am] = st;
				st = am;
				idx = am;
			}
			else
			{
				fw[am] = fw[idx];
				bw[fw[am]] = am;
				fw[idx] = am;
				bw[am] = idx;
				idx = am;
			}
			am++;
		}
		else if(c=='l') 
		{
			if(idx!=-1) idx = bw[idx];
		}
		else if(c=='r')
		{
			if(idx==-1) idx = st;
			else if(idx!=en) idx = fw[idx];
		}
		else if(c=='b')
		{
			if(idx==-1) continue;
			if(bw[idx]!=-1) fw[bw[idx]] = fw[idx];
			else st = fw[idx];
			if(fw[idx]!=-1) bw[fw[idx]] = bw[idx];
			else en = bw[idx];
			idx = bw[idx];
		}
		else 
		{
			if(idx==en) continue;
			if(idx==-1 and st==-1) continue;
			if(idx==-1) idx = st;
			else idx = fw[idx];
			if(idx==-1) continue;
			if(bw[idx]!=-1) fw[bw[idx]] = fw[idx];
			else st = fw[idx];
			if(fw[idx]!=-1) bw[fw[idx]] = bw[idx];
			else en = bw[idx];
			idx = bw[idx];
		}
	}
 
	for(int i = st;i != -1;i = fw[i]) cout << s[i] << ' ';
}