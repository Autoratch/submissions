#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 1;
const int K = 20;

int n;
vector<pair<int,int> > adj[N];
int lv[N],dp[K][N],mx[K][N];

void dfs(int u){ if(u==1) lv[u] = 1; for(auto [d,v] : adj[u]) mx[0][v] = d,dp[0][v] = u,lv[v] = lv[u]+1,dfs(v); }

int dist(int a,int b)
{
    int ans = INT_MAX;
    if(lv[a]<lv[b]) swap(a,b);
    for(int i = K-1;i >= 0;i--) if(lv[dp[i][a]]>=lv[b]) ans = min(ans,mx[i][a]),a = dp[i][a];
    if(a==b) return ans;
    for(int i = K-1;i >= 0;i--) if(dp[i][a]!=dp[i][b]) ans = min(ans,min(mx[i][a],mx[i][b])),a = dp[i][a],b = dp[i][b];
    return min(ans,min(mx[0][a],mx[0][b]));
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n;
    for(int i = 1;i < n;i++) 
    {
        int x,y;
        cin >> x >> y;
        adj[x+1].push_back({y,i+1});
    }
    dfs(1);
    for(int i = 1;i < K;i++) for(int j = 1;j <= n+1;j++) dp[i][j] = dp[i-1][dp[i-1][j]],mx[i][j] = min(mx[i-1][j],mx[i-1][dp[i-1][j]]);
    int q,k,m,a1,a2;
    cin >> q >> k >> m >> a1 >> a2;
    for(int i = 1;i <= q;i++)
    {
        int ans = dist(a1+1,a2+1);
        if(ans==INT_MAX) ans = 0;
        cout << ans << '\n';
        a1 = a2;
        a2 = ((a1*k+ans)%m)%n;
    }
}
