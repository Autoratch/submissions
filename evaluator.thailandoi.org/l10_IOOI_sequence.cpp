#include <bits/stdc++.h>
using namespace std;

const int MOD = 2553;

int n,k,ans,dp[5001][2];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> k;

    for(int i = 1;i <= n;i++)
    {
        dp[i][0] = dp[i-1][0];
        if(i<=k) dp[i][0] = (dp[i][0]+1)%MOD;
    }

    if(k==n) ans = 1;

    for(int i = 2;i <= n;i++)
    {
        for(int j = 1;j <= n;j++) dp[j][1] = (dp[j-1][1]+dp[j-1][0]-dp[max(j-k-1,0)][0])%MOD;
        for(int j = 1;j <= n;j++) dp[j][0] = dp[j][1];
        int res = (dp[n][0]-dp[n-1][0]+MOD)%MOD;
        ans = (ans+((res*res)%MOD*res)%MOD)%MOD;
    }

    cout << ans;
}
