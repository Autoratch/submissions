#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 1;

int n,m;
int deg[N];
vector<int> adj[N];
queue<int> q;
vector<int> ans;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    cin >> n >> m;

    for(int i = 0;i < m;i++)
    {
        int a,b;
        cin >> a >> b;
        adj[a].push_back(b);
        deg[b]++;
    }

    int st = -1;

    for(int i = 1;i <= n;i++) if(deg[i]==0){ st = i; q.push(i); }

    if(st==-1){ cout << "no"; return 0; }

    while(!q.empty())
    {
        int p = q.front();
        q.pop();
        ans.push_back(p);
        for(int i = 0;i < adj[p].size();i++)
        {
            if(deg[adj[p][i]]==-1) continue;
            deg[adj[p][i]]--;
            if(deg[adj[p][i]]==0) q.push(adj[p][i]);
        }
    }

    if(ans.size()<n) cout << "no";
    else for(int i = 0;i < n;i++) cout << ans[i] << '\n';
}
