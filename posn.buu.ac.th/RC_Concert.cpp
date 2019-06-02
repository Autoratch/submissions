#include <bits/stdc++.h>
using namespace std;

const int N = 3e5 + 1;

int n;
vector<pair<int,int> > adj[N];
int dist[N],lv[N],ans;

bool dfs(int u)
{
    bool f = u==n;
    for(int i = 0;i < adj[u].size();i++)
    {
        int w = adj[u][i].first,v = adj[u][i].second;
        dist[v] = dist[u]+w;
        f|=dfs(v); 
    }
    if(adj[u].size()) lv[u] = -1;
    return f;
}

bool dfs2(int u)
{
    bool f = u==n;
    if(lv[u]==-1) lv[u] = 0;
//    cout << u << endl;
    for(int i = 0;i < adj[u].size();i++)
    {
        int v = adj[u][i].second;
        bool xn = dfs2(v);
        f|=xn;
        if(!xn) ans = max(ans,lv[v]);
        lv[u]+=lv[v];
//        cout << u << ' ' << v << ' ' << lv[v] << endl;
    }
    return f;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n;

    for(int i = 0;i < n-1;i++)
    {
        int a,b,d;
        cin >> a >> b >> d;
        adj[b].push_back({d,a});
    }

    dfs(1);
    int xx = 0;

    for(int i = 1;i <= n;i++) if(lv[i]!=-1 and i!=n and dist[i]<=dist[n]) lv[i] = 1,xx++; 

    dfs2(1);

    cout << xx-ans+1;
}
