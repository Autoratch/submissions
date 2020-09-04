#include <bits/stdc++.h>
using namespace std;
 
const int N = 1e5 + 1;
const int K = 350;
 
int n,m,k;
vector<int> adj[N],rev[N];
int id[N],dp[N];
queue<int> q;
vector<pair<int,int> > res[N];
bool out[N];
stack<int> st;
 
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
 
	cin >> n >> m >> k;
	for(int i = 0;i < m;i++)
	{
		int a,b;
		cin >> a >> b;
		adj[a].push_back(b);
		rev[b].push_back(a);
	}
	for(int u = 1;u <= n;u++)
	{
		for(int v : rev[u]) id[v] = 0;
		for(int j = 0;j < K;j++)
		{
			pair<int,int> mx = {u,0};
			for(int v : rev[u]) 
			{
				while(id[v]<res[v].size() and out[res[v][id[v]].first]) id[v]++;
				if(id[v]<res[v].size() and res[v][id[v]].second+1>mx.second) mx = {res[v][id[v]].first,res[v][id[v]].second+1};
			}
			res[u].push_back(mx);
			out[mx.first] = true;
			st.push(mx.first);
			if(mx.first==u) break;
			else id[mx.first]++;
		}
		while(!st.empty()) out[st.top()] = false,st.pop();
	}
	while(k--)
	{
		int u,am,mm;
		cin >> u >> am,mm = am;
		while(am--){ int x; cin >> x; out[x] = true; st.push(x); }
		if(mm>=K)
		{
			for(int i = 1;i <= n;i++) dp[i] = INT_MIN;
			dp[u] = 0;
			int ans = -1;
			if(!out[u]) ans = 0;
			for(int i = u-1;i >= 1;i--)
			{
				for(int v : adj[i]) dp[i] = max(dp[i],dp[v]+1);
				if(!out[i]) ans = max(ans,dp[i]);
			}
			cout << ans << '\n';
		}
		else
		{
			int ans = -1;
			for(auto [x,y] : res[u]) if(!out[x]){ ans = y; break; } 
			cout << ans << '\n';
		}
		while(!st.empty()) out[st.top()] = false,st.pop();
	}
}
