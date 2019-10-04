#include <bits/stdc++.h>
using namespace std;

const int N = 1e4;
const int K = 16;

int n,m,k;
vector<int> adj[N];
int deg[N],dist[K][K];
vector<int> s;
bool visited[N];
int res[1 << K];
queue<pair<int,int> > q;

int bfs(int u,int d)
{
    while(!q.empty()) q.pop();
    q.push({u,0});
    visited[u] = true;
    while(!q.empty())
    {
        int u = q.front().first,lv = q.front().second;
        q.pop();
        if(u==d) return lv;
        for(int v : adj[u]) if(!visited[v])
        {
            q.push({v,lv+1});
            visited[v] = true;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> m;

    for(int i = 0;i < m;i++)
    {
        int a,b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
        deg[a]++,deg[b]++;
    }

    for(int i = 1;i <= n;i++) if(deg[i]%2==1) s.push_back(i);

    k = s.size();

    for(int i = 0;i < k;i++) for(int j = i+1;j < k;j++)
    {
        dist[i][j] = dist[j][i] = bfs(s[i],s[j]);
        for(int l = 1;l <= n;l++) visited[l] = false;
    }

    for(int i = 1;i < (1 << k);i++) res[i] = INT_MAX;

    vector<bool> t;

    for(int i = 0;i < (1 << k);i++)
    {
        int tmp = i,id = 0,cn = 0;
        t.assign(k,false);
        while(tmp) t[id++] = tmp%2,tmp/=2,cn+=t[id-1];
        if(cn%2) continue;
        for(int j = 0;j < k;j++) for(int l = j+1;l < k;l++) if(!t[j] and !t[l]) 
        {
            res[i|(1 << j)|(1 << l)] = min(res[i|(1 << j)|(1 << l)],res[i]+dist[j][l]);
        }
    }

    cout << m-res[(1 << k)-1];
}
