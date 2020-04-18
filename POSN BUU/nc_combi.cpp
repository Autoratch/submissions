#include <bits/stdc++.h>
using namespace std;

const int N = 101;
const int MOD = 1e9 + 7;

int n,m,a,b;
long long dp[N][N][N][2],sum[N][N][2];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> m >> a >> b;
    if(a>n) a = n;
    if(b>m) b = m;
    dp[1][0][1][0] = dp[0][1][1][1] = sum[1][0][0] = sum[0][1][1] = 1;
    for(int i = 0;i <= n;i++) for(int j = 0;j <= m;j++)
    {
        if(i==0 and j==0) continue;
        if(i==1 and j==0) continue;
        if(i==0 and j==1) continue;
        for(int k = 1;k <= min(a,i);k++)
        {
            dp[i][j][k][0] = (dp[i][j][k][0]+dp[i-1][j][k-1][0])%MOD;
            if(k==1) dp[i][j][k][0] = (dp[i][j][k][0]+sum[i-1][j][1])%MOD;
            sum[i][j][0] = (sum[i][j][0]+dp[i][j][k][0])%MOD;
        }
        for(int k = 1;k <= min(b,j);k++)
        {
            dp[i][j][k][1] = (dp[i][j][k][1]+dp[i][j-1][k-1][1])%MOD;
            if(k==1) dp[i][j][k][1] = (dp[i][j][k][1]+sum[i][j-1][0])%MOD;
            sum[i][j][1] = (sum[i][j][1]+dp[i][j][k][1])%MOD;
        }
    }
    cout << (sum[n][m][0]+sum[n][m][1])%MOD;
}
