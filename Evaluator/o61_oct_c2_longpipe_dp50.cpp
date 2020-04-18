#include <bits/stdc++.h>
using namespace std;

const int N = 5e5 + 1;
const int MOD = 1e9 + 7;

int n,dp[N][3];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n;

    dp[0][0] = dp[0][1] = 1;
    for(int i = 1;i <= n;i++) 
    {
        dp[i][0] = ((dp[i-1][0]+dp[i-1][1])%MOD+dp[i-1][2])%MOD;
        dp[i][1] = ((dp[i-1][0]*2)%MOD+dp[i-1][1])%MOD;
        dp[i][2] = (dp[i-1][0]+dp[i-1][2])%MOD;
    }
    
    cout << ((dp[n][0]*2)%MOD+dp[n][1])%MOD;
}
