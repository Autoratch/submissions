#include <bits/stdc++.h>
using namespace std;

const int N = 2e6 + 10;

int n,m,adj[N],dp[N],st[N],id,cm,sz[N];
bool visited[N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> m;
    for(int i = 0,a,b;i < n;i++) cin >> a >> b,adj[a] = b,adj[b] = a,dp[a]++,dp[b]++;
    for(int i = 1;i < N;i++)
    {
        dp[i]+=dp[i-1];
        if(dp[i]!=dp[i-1]) st[id++] = i;
    }   
    for(int i = 0;i < n*2;i++) if(!visited[i])
    {
        cm++;
        visited[i] = true;
        int u = i;
        while(true)
        {
            sz[cm]++;
            int v = dp[adj[st[u]]];
            if(visited[v] or v==n*2) break;
            visited[v] = true;
            u = v;
        }
    }
    int ans = sz[1];
    for(int i = 2;i <= cm;i++) dp[i-2] = sz[i];
    sort(dp,dp+cm-1);
    reverse(dp,dp+cm-1);
    for(int i = 0;i < cm-1 and m;i++,m--) ans+=dp[i]+2;
    if(m) ans+=2*(m-(m&1))+(m&1);
    cout << ans;
}
