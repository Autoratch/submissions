#include <bits/stdc++.h>
using namespace std;

const int N = 5e5 + 1;

int n,q;
vector<int> adj[N];
string res;
int sz[N],lv[N];
bool cnt[26][N];
int tg[N];
bool big[N],ans[N];
vector<pair<int,int> > qe[N];

void pre(int u){ sz[u] = 1; for(int v : adj[u]) lv[v] = lv[u]+1,pre(v),sz[u]+=sz[v]; }

void add(int u)
{
    cnt[res[u-1]-'a'][lv[u]]^=1;
    if(cnt[res[u-1]-'a'][lv[u]]) tg[lv[u]]++;
    else tg[lv[u]]--;
    for(int v : adj[u]) if(!big[v]) add(v);
}

void dfs(int u,int k)
{
    int mx = -1,bc = -1;
    for(int v : adj[u]) if(sz[v]>mx) mx = sz[v],bc = v;
    for(int v : adj[u]) if(v!=bc) dfs(v,0);
    if(bc!=-1) dfs(bc,1),big[bc] = 1;
    add(u);
    for(auto [l,i] : qe[u]) ans[i] = tg[l]<=1;
    if(bc!=-1) big[bc] = 0;
    if(!k) add(u);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> q;
    for(int i = 2;i <= n;i++)
    {
        int x;
        cin >> x;
        adj[x].push_back(i);
    }
    cin >> res;
    for(int i = 1;i <= q;i++)
    {
        int x,y;
        cin >> x >> y;
        qe[x].push_back({y,i});
    }
    lv[1] = 1;
    pre(1);
    dfs(1,1);
    for(int i = 1;i <= q;i++) if(ans[i]) cout << "Yes\n"; else cout << "No\n";
}
