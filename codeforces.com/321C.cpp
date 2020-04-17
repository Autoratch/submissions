#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 1;

int n;
vector<int> adj[N];
int sz[N];
bool blocked[N];
char ans[N],mxx;

void dfs(int u,int p){ sz[u] = 1; for(int v : adj[u]) if(v!=p and !blocked[v]) dfs(v,u),sz[u]+=sz[v]; }

void build(int u,int cp,char ch)
{
    dfs(u,0);
    int c = u,prev = 0;
    while(true)
    {
        int mx = 0,id = -1;
        for(int v : adj[c]) if(v!=prev and !blocked[v]) if(sz[v]>mx) mx = sz[v],id = v;
        if(mx*2>sz[u]) prev = c,c = id;
        else break;
    }
    blocked[c] = true;
    ans[c] = ch,mxx = max(mxx,ch);
    for(int v : adj[c]) if(!blocked[v]) build(v,c,ch+1);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n;
    for(int i = 0;i < n-1;i++)
    {
        int a,b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    build(1,0,'A');
    if(mxx>'Z'){ return 0; cout << "Impossible!"; }
    for(int i = 1;i <= n;i++) cout << ans[i] << ' ';
}
