#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 1;

int t,n,m;
vector<vector<int> > adj;
vector<int> ev,od;
queue<pair<int,int> > q;
vector<bool> visited;

void bfs()
{
	q.push({1,0});
	visited[1] = true;
	while(!q.empty())
	{
		int p = q.front().first,lv = q.front().second;
		q.pop();
		if(lv%2) od.push_back(p);
		else ev.push_back(p);
		for(int v : adj[p]) if(!visited[v]){ visited[v] = true; q.push({v,1-lv}); }
	}
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> t;
	
	while(t--)
	{
		cin >> n >> m;
		adj.clear();
		adj.resize(n+1);
		for(int i = 0;i < m;i++)
		{
			int a,b;
			cin >> a >> b;
			adj[a].push_back(b);
			adj[b].push_back(a);
		}
		ev.clear(),od.clear();
		visited.assign(n+1,false);
		bfs();
		if(ev.size()<od.size()) 
		{
			cout << ev.size() << '\n';
			for(int x : ev) cout << x << ' ';
		}
		else
		{
			cout << od.size() << '\n';
			for(int x : od) cout << x << ' ';
		}
		cout << '\n';
	}
}