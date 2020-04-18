#include <bits/stdc++.h>
using  namespace std;

const int N = 1e5 + 1;
const int MOD = 1e9 + 7;

int m,n;
int dp[N][2][2];
int ans;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> m >> n;

    dp[1][1][0] = 1;
    dp[1][0][1] = 1;

    for(int i = 2;i < N;i++) 
    {
        dp[i][0][0] = (dp[i][0][0]+dp[i-1][0][1])%MOD;
        dp[i][0][1] = (dp[i][0][1]+dp[i-1][1][1])%MOD;
        dp[i][0][1] = (dp[i][0][1]+dp[i-1][1][0])%MOD;
        dp[i][1][1] = (dp[i][1][1]+dp[i-1][1][0])%MOD;
        dp[i][1][0] = (dp[i][1][0]+dp[i-1][0][1])%MOD;
        dp[i][1][0] = (dp[i][1][0]+dp[i-1][0][0])%MOD;
    }

    for(int i = 0;i < 2;i++) for(int j = 0;j < 2;j++) ans = (ans+dp[m][i][j])%MOD;
    for(int i = 0;i < 2;i++) for(int j = 0;j < 2;j++) ans = (ans+dp[n][i][j])%MOD;

    cout << ((ans-2)+MOD)%MOD;
}
