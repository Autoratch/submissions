#include <bits/stdc++.h>
using namespace std;

const long long N = 1e5 + 1;

long long n;
long long c[N][3];
long long dp[N][3][3];
vector<long long> adj[N];
long long an[N];

void dfs(long long u,long long p)
{
    for(long long i = 0;i < 3;i++) for(long long j = 0;j < 3;j++) if(i!=j) dp[u][i][j] = c[u][i];
    long long ch = -1;
    for(long long v : adj[u]) if(v!=p) ch = v;
    if(ch==-1) return;
    dfs(ch,u);
    for(long long i = 0;i < 3;i++) for(long long j = 0;j < 3;j++)
    {
        if(i==j) continue;
        long long mn = LLONG_MAX;
        for(long long k = 0;k < 3;k++) if(i!=k and j!=k) mn = min(mn,dp[ch][j][k]);
        dp[u][i][j]+=mn;
    }
}

void dfs2(long long u,long long p,long long x,long long a,long long b)
{
///    cout << u << ' ' << p << ' ' << a << ' ' << endl;
//    for(int i = 0;i < 3;i++) an[u] = i+1;
    for(long long i = 0;i < 3;i++) for(long long j = 0;j < 3;j++) if(dp[u][i][j]==x and i!=j and i!=a and i!=b and j!=b)
    {
         an[u] = i+1;
        long long ch = -1;
        for(long long v : adj[u]) if(v!=p) ch = v;
        if(ch==-1) return;
        dfs2(ch,u,x-c[u][i],b,i);
        return;
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n;

    for(long long i = 0;i < 3;i++) for(long long j = 1;j <= n;j++) cin >> c[j][i];

    for(long long i = 0;i < n-1;i++)
    {
        long long a,b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    for(long long i = 1;i <= n;i++) if(adj[i].size()>=3){ cout << "-1"; return 0; }

    long long root;

    for(long long i = 1;i <= n;i++) if(adj[i].size()==1){ dfs(i,0); root = i; break; }

    long long ans = LLONG_MAX;

    for(long long i = 0;i < 3;i++) for(long long j = 0;j < 3;j++) if(i!=j) ans = min(ans,dp[root][i][j]);

    dfs2(root,0,ans,4,4);

    cout << ans << '\n';
    for(long long i = 1;i <= n;i++) cout << an[i] << ' ';
}
