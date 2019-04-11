#include <bits/stdc++.h>
using namespace std;

const int N = 1e4 + 1;

int n,m,k;
vector<int> adj[N],res;
bool od[N];
int id[N],dist[16][16];
queue<pair<int,int> > q;
vector<bool> visited,t;
int ret[1 << 16];

void bfs(int x)
{
    q.push({x,0});
    visited.assign(n+1,0);
    visited[x] = true;

    while(!q.empty())
    {
        int p = q.front().first,lv = q.front().second;
        q.pop();
        if(od[p]) dist[id[x]][id[p]] = lv;
        for(int v : adj[p])
        {
            if(visited[v]) continue;
            visited[v] = true;
            q.push({v,lv+1});
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
    }

    for(int i = 1;i <= n;i++) if(adj[i].size()%2==1){ od[i] = true; id[i] = res.size(); res.push_back(i); }
    
    for(int x : res) bfs(x);
    k = res.size();
    
    for(int i = 1;i < (1 << k);i++) ret[i] = INT_MAX;
    for(int i = 0;i < (1 << k)-1;i++)
    {
        int tmp = i,cnt = 0,cn = 0;
        t.assign(k,false);
        while(tmp)
        {
            if(tmp%2) cn++;
            t[cnt] = tmp%2;
            tmp/=2;
            cnt++;
        }
        if(cn%2) continue;
        for(int x = 0;x < k;x++) for(int y = x+1;y < k;y++)
        {
            if(t[x] or t[y]) continue;
            ret[i|(1<<x)|(1<<y)] = min(ret[i|(1<<x)|(1<<y)],ret[i]+dist[x][y]);
        }
    }

    cout << m-ret[(1 << k)-1];
}
