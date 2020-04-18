#include <bits/stdc++.h>
using namespace std;
#define pii pair<int,int>

const int N = 1e5 + 1;

int n,m,ans;
vector<pii> adj[N];
priority_queue<pii,vector<pii>,greater<pii> > q;
bool visited[N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> m;

    for(int i = 0;i < m;i++)
    {
        int a,b,d;
        cin >> a >> b >> d;
        adj[a].push_back({d,b});
        adj[b].push_back({d,a});
    }

    q.push({0,1});

    while(!q.empty())
    {
        int w = q.top().first,p = q.top().second;
        q.pop();
        if(visited[p]) continue;
        visited[p] = true;
        ans+=w;
        for(int i = 0;i < adj[p].size();i++) q.push(adj[p][i]);
    }

    cout << ans;
}
