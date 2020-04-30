#include <bits/stdc++.h>
using namespace std;

const long long N = 5e4 + 1;

long long n,m;
long long res[N];
vector<long long> adj[N];
long long deg[N];
queue<long long> q;
long long ans;
long long dp[N];

int main()
{
    freopen("msched.in","r",stdin);
    freopen("msched.out","w",stdout);

    cin >> n >> m;

    for(long long i = 1;i <= n;i++) cin >> res[i];

    for(long long i = 0;i < m;i++)
    {
        long long a,b;
        cin >> a >> b;
        adj[a].push_back(b);
        deg[b]++;
    }

    for(long long i = 1;i <= n;i++) if(!deg[i]) q.push(i),deg[i] = -1;

    while(!q.empty())
    {
        long long p = q.front();
        q.pop();
        dp[p]+=res[p];
        ans = max(ans,dp[p]);
        for(long long v : adj[p]) 
        {
            if(deg[v]==-1) continue;
            deg[v]--;
            dp[v] = max(dp[v],dp[p]);
            if(deg[v]==0) deg[v] = -1,q.push(v);
        }
    }

    cout <<  ans;
}
