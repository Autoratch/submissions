#include <bits/stdc++.h>
using namespace std;

const int N = 1e5;

int n,dp[N][3],now,mn = INT_MAX;
string s,ans,h = "BWG";

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> s;

    for(int i = 1;i <= n;i++)
    {
        char c = s[i-1];
        if(c=='B')
        {
            dp[i][0] = min(dp[i-1][1],dp[i-1][2]);
            dp[i][1] = dp[i][2] = 1e9;
        }
        else if(c=='W')
        {
            dp[i][1] = min(dp[i-1][0],dp[i-1][2]);
            dp[i][0] = dp[i][2] = 1e9;
        }
        else
        {
            dp[i][0] = min(dp[i-1][1],dp[i-1][2]);
            dp[i][1] = min(dp[i-1][0],dp[i-1][2]);
            dp[i][2] = min(dp[i-1][0],dp[i-1][1])+1;
        }
    }

    for(int i = 0;i < 3;i++) if(dp[n][i]<mn) mn = dp[n][i],now = i;

    for(int i = n;i >= 1;i--)
    {
        ans+=h[now];
        int nxt;
        for(int j = 0;j < 3;j++) if(dp[i-1][j]+(now==2)==dp[i][now] and j!=now) nxt = j;
        now = nxt;
    }

    for(int i = ans.length()-1;i >= 0;i--) cout << ans[i];
}
