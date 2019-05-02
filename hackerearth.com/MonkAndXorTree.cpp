#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 1;
const int K = 21;

int n,k;
int res[N],pa[N];
vector<int> adj[N];
int ex[1 << K];
long long ans;

void dfs(int u,int p,int all)
{
    all^=res[u];
    ans+=ex[all^k];
    ex[all]++;
    for(int v : adj[u]) if(v!=p) dfs(v,u,all);
    ex[all]--;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    cin >> n >> k;
    
    for(int i = 1;i <= n;i++) cin >> res[i];
    for(int i = 2;i <= n;i++)
    {
        int p;
        cin >> p;
        adj[i].push_back(p);
        adj[p].push_back(i);
    }
    
    ex[0] = true;
    dfs(1,0,0);
    
    cout << ans;
}
