#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> adj[(int)1e4 + 1];
queue<pair<int,int> > q;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n;

    if(n==1){ cout << "1"; return 0; }

    for(int i = 0;i < n-1;i++)
    {
        int a,b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    for(int i = 1;i <= n;i++) if(adj[i].size()==1)
    {
        q.push({i,i});
        int cnt = 0;
        while(!q.empty())
        {
            int u = q.front().first,p = q.front().second;
            q.pop();
            cnt++;
            if(cnt*2-1==n){ cout << u; return 0; }
            for(int j = 0;j < adj[u].size();j++) if(adj[u][j]!=p) q.push({adj[u][j],u});
        }
    }
}
