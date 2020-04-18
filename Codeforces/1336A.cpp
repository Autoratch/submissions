#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 1;

int n,k;
vector<int> adj[N];
int lv[N],sub[N];
vector<int> res;
long long ans;

void dfs(int u,int p)
{
    lv[u] = lv[p]+1;
    sub[u] = 1;
    for(int v : adj[u]) if(v!=p) dfs(v,u),sub[u]+=sub[v];
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> k;
    for(int i = 1;i < n;i++)
    {
        int a,b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(1,0);
    for(int i = 1;i <= n;i++) res.push_back(lv[i]-1-sub[i]+1);
    sort(res.begin(),res.end());
    reverse(res.begin(),res.end());
    for(int i = 0;i < k;i++) ans+=res[i];
    cout << ans;
}
