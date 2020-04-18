#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 1;

int n,m,k;
vector<int> adj[N],re[N];
int res[N],lv[N];
bool visited[N];
queue<int> q;
priority_queue<long long> pq;
long long ans;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> m >> k;

    for(int i = 1;i <= n;i++) cin >> res[i];
    
    for(int i = 0;i < m;i++)
    {
        int a,b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    
    q.push(k);
    visited[k] = true;
    
    while(!q.empty())
    {
        int p = q.front();
        q.pop();
        re[lv[p]].push_back(p);
        for(int i = 0;i < adj[p].size();i++)
        {
            if(visited[adj[p][i]]) continue;
            visited[adj[p][i]] = true;
            lv[adj[p][i]] = lv[p]+1;
            q.push(adj[p][i]);
        }
    }

    for(int i = 1;i <= n;i++) if(lv[i]==0 and i!=k) re[n].push_back(i);

    for(int i = n;i >= 1;i--)
    {
        for(int x : re[i]) pq.push(res[x]); 
        if(!pq.empty() and pq.top()>=0){ ans+=pq.top(); pq.pop(); }
    }

    cout << ans;
}
