#include <bits/stdc++.h>
using namespace std;

const int N = 101;

int n,m,s,t,ans;
int adj[N][N],dis[N],p[N];
queue<int> q;

bool play()
{
    for(int i = 1;i <= n;i++) dis[i] = -1;
    dis[s] = 0;
    q.push(s);
    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        for(int v = 1;v <= n;v++) if(dis[v]==-1 and adj[u][v]) dis[v] = dis[u]+1,p[v] = u,q.push(v);
    }
    return dis[t]!=-1;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> m >> s >> t;
    for(int i = 0;i < m;i++)
    {
        int a,b,d;
        cin >> a >> b >> d;
        adj[a][b] = d;
    }   
    while(play())
    {
        int x = t,w = INT_MAX;
        while(x!=s) w = min(w,adj[p[x]][x]),x = p[x];
        x = t;
        while(x!=s) adj[p[x]][x]-=w,adj[x][p[x]]+=w,x = p[x];
        ans+=w;
    }
    cout << ans;
}
