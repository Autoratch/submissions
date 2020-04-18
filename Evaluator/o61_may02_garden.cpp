#include <bits/stdc++.h>
using namespace std;

const int N = 1 << 10;
const int MOD = 1e6 + 3;

int n,m,k;
int c[N];
vector<int> adj[N];
int dp[N][N];
int ans;
vector<bool> t;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> m >> k;

    for(int i = 0;i < n;i++) cin >> c[i];

    for(int i = 0;i < m;i++)
    {
        int a,b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    for(int i = 1;i < (1 << k);i++) for(int j = 0;j < n;j++)
    {
        if((1 << c[j])==i){ dp[i][j] = 1; continue; }
        t.resize(n);
        int tmp = i,cnt = 0;
        while(tmp) t[cnt++] = tmp%2,tmp/=2;
        if(!t[c[j]]) continue;
        for(int x : adj[j]) if(t[c[x]]) dp[i][j] = (dp[i][j]+dp[i^(1 << c[j])][x])%MOD;
    }

    for(int i = 0;i < n;i++) ans = (ans+dp[(1 << k)-1][i])%MOD;

    cout << ans;
}
