#include <bits/stdc++.h>
using namespace std;

int n,m;
vector<pair<int,int> > edj;
vector<vector<int> > adj;
vector<bool> visited;
vector<int> lv;
queue<int> q;

bool bfs(int x)
{
    while(!q.empty()) q.pop();
    q.push(x);
    lv[x] = 1;
    visited[x] = true;
    while(!q.empty())
    {
        int p = q.front();
        q.pop();
        for(int i = 0;i < adj[p].size();i++)
        {
            if(!visited[adj[p][i]])
            {
                visited[adj[p][i]] = true;
                lv[adj[p][i]] = lv[p]+1;
                q.push(adj[p][i]);
            }
            else if(lv[adj[p][i]]==lv[p]) return true; 
        }
    }
    return false;
}

bool solve(int x)
{
    adj.clear();
    adj.resize(n+1);
    visited.assign(n+1,false);
    lv.assign(n+1,0);
    for(int i = 0;i < x;i++)
    {
        int a = edj[i].first,b = edj[i].second;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for(int i = 1;i <= n;i++)
    {
        if(visited[i]) continue;
        if(bfs(i)) return false;
    }
    return true;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> m;

    for(int i = 0;i < m;i++)
    {
        int a,b;
        cin >> a >> b;
        edj.push_back({a,b});
    }

    int l = 1,r = m;

    while(l<r)
    {
        int m = (l+r)/2;
        bool ok = solve(m);
        if(!ok) r = m-1;
        else if(m==r or !solve(m+1)){ l = m; break; }
        else l = m+1;
    }

    cout << l;
}

