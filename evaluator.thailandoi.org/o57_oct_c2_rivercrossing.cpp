#include <bits/stdc++.h>
using namespace std;

const int N = 5e4 + 2;
const int MOD = 30011;

int n,m,k,l;
vector<int> f[N][2],ff[N][2];
int st[N][2],en[N][2];
int dp[N][11],ans;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> m >> k >> l;

    for(int i = 0;i < l;i++)
    {
        int a,b;
        cin >> a >> b;
        ff[a][0].push_back(b);
        ff[b][1].push_back(a);
    }

    for(int i = 1;i <= n;i++)
    {
        int sz;
        cin >> sz >> st[i][0];
        en[i][0] = -1;
        sort(ff[i][0].begin(),ff[i][0].end());
        for(int j = 0;j < ff[i][0].size();j++) if(ff[i][0][j]>st[i][0]) f[i][0].push_back(ff[i][0][j]);
        for(int j = 0;j < f[i][0].size();j++)
        {
            if(f[i][0][j]-1-st[i][0]+1-j>=sz){ en[i][0] = st[i][0]+sz-1+j; break; }
        }
        if(en[i][0]==-1) en[i][0] = st[i][0]+sz-1+f[i][0].size();
    }

    for(int i = 1;i <= m;i++)
    {
        int sz;
        cin >> sz >> st[i][1];
        en[i][1] = -1;
        sort(ff[i][1].begin(),ff[i][1].end());
        for(int j = 0;j < ff[i][1].size();j++) if(ff[i][1][j]>st[i][1]) f[i][1].push_back(ff[i][1][j]);
        for(int j = 0;j < f[i][1].size();j++)
        {
            if(f[i][1][j]-1-st[i][1]+1-j>=sz){ en[i][1] = st[i][1]+sz-1+j; break; }
        }
        if(en[i][1]==-1) en[i][1] = st[i][1]+sz-1+f[i][1].size();
    }

    for(int i = 1;i <= n;i++) dp[i][0] = 1;

    for(int i = 1;i <= k;i++) 
    {
        int sz;
        if(i%2==1) sz = n;
        else sz = m;
        int fr = 1-i%2;
        for(int j = 1;j <= sz;j++)
        {
            int val = dp[j][i-1];
            dp[st[j][fr]][i] = (dp[st[j][fr]][i]+val)%MOD,dp[en[j][fr]+1][i] = (dp[en[j][fr]+1][i]-val+MOD)%MOD;
            for(int x : f[j][fr]) if(x>=st[j][fr] and x<=en[j][fr]) dp[x][i] = (dp[x][i]-val+MOD)%MOD,dp[x+1][i] = (dp[x+1][i]+val)%MOD;
        }
        for(int j = 1;j <= m+n-sz;j++) dp[j][i] = (dp[j][i]+dp[j-1][i])%MOD;
        if(i%2==1) for(int j = 1;j <= m+n-sz;j++) ans = (ans+dp[j][i])%MOD;
    }

    cout << ans;
}
