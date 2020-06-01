#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 1;

int n;
vector<int> adj[N];
int s[N],va[N],vb[N],l[N],r[N];
long long ans;

void dfs(int u,int p)
{
    for(int v : adj[u]) if(v!=p)
    {
        s[v] = min(s[v],s[u]);
        dfs(v,u);
        l[u]+=l[v],r[u]+=r[v];
    }
    if(va[u]<vb[u]) l[u]++;
    if(va[u]>vb[u]) r[u]++;
    ans+=(long long)min(l[u],r[u])*(long long)s[u];
    int mn = min(l[u],r[u]);
    l[u]-=mn,r[u]-=mn;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n;
    for(int i = 1;i <= n;i++) cin >> s[i] >> va[i] >> vb[i];
    for(int i = 0;i < n-1;i++)
    {
        int a,b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(1,0);
    if(l[1] or r[1]) cout << "-1";
    else cout << ans*2LL;
}
