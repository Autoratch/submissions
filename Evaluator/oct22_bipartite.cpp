#include <bits/stdc++.h>
using namespace std;

int t,n,m;
vector<int> lv;
vector<vector<int> > adj;
queue<int> q;

bool bfs(int x)
{
    while(!q.empty()) q.pop();
    q.push(x);
    lv[x] = 1;
    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        for(int i = 0;i < adj[u].size();i++) 
        {
            int v = adj[u][i];
            if(lv[v]==3-lv[u]) continue;
            else if(lv[v]==lv[u]) return false;
            else{ lv[v] = 3-lv[u]; q.push(v); }
        }
    }
    return true;
}

bool solve()
{
    for(int i = 1;i <= n;i++)
    {
        if(lv[i]) continue;
        if(!bfs(i)) return false;
    }
    return true;
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
        lv.assign(n+1,0);
        for(int i = 0;i < m;i++)
        {
            int a,b;
            cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        if(solve()) cout << "yes\n";
        else cout << "no\n";
    }
}
