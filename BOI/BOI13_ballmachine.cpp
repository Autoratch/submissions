#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 1;
const int K = 19;

int n,q,root,t;
vector<int> adj[N];
int dp[K][N],lv[N],mn[N],prio[N];
priority_queue<pair<int,int> > ava;
vector<pair<int,int> > tmp;
bool filled[N];

void dfs(int u,int p)
{
    lv[u] = lv[p]+1,dp[0][u] = p;
    mn[u] = u;
    for(int v : adj[u]) dfs(v,u),mn[u] = min(mn[u],mn[v]);
    tmp.clear();
    for(int v : adj[u]) tmp.push_back({mn[v],v});
    sort(tmp.begin(),tmp.end());
    int id = 0;
    for(int &v : adj[u]) v = tmp[id++].second;
}

void findpr(int u,int p)
{
    for(int v : adj[u]) findpr(v,u);
    prio[u] = ++t;
}

int jump(int x)
{
    for(int i = K-1;i >= 0;i--) if(filled[dp[i][x]])
    {
        x = dp[i][x];
        if(!filled[dp[0][x]]) return x;
    }
    return x;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> q;
    for(int i = 1;i <= n;i++) 
    {
        int x;
        cin >> x;
        if(!x) root = i;
        else adj[x].push_back(i);
    }
    dfs(root,0);
    findpr(root,0);
    for(int i = 1;i < K;i++) for(int j = 1;j <= n;j++) dp[i][j] = dp[i-1][dp[i-1][j]];
    for(int i = 1;i <= n;i++) ava.push({-prio[i],i});
    while(q--)
    {
        int t,x;
        cin >> t >> x;
        if(t==1)
        {
            int ans;
            while(x--) ans = ava.top().second,filled[ava.top().second] = true,ava.pop();            
            cout << ans << '\n';
        }
        else
        {
            int res = jump(x);
            filled[res] = false,ava.push({-prio[res],res});
            cout << lv[x]-lv[res] << '\n';
        }
    }
}
