#include <bits/stdc++.h>
using namespace std;

const int N = 101;
const int MOD = 1e9 + 7;

int n,k;
long long dp[N][N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> k;

    for(int i = 0;i <= n;i++) dp[0][i] = dp[i][0] = 1;

    for(int i = 1;i <= n;i++) for(int j = 1;j <= n;j++)
    {
        for(int x = 1;x <= k;x++)
        {
            if(i-x>=1) dp[i][j] = (dp[i][j]+dp[i-x-1][j-1]);
            if(j-x>=1) dp[i][j] = (dp[i][j]+dp[i-1][j-x-1]);
        }
        dp[i][j] = (dp[i][j]+dp[i-1][j]+dp[i][j-1]-dp[i-1][j-1])%MOD;
    }

    cout << (dp[n][n]-1+MOD)%MOD;
}
