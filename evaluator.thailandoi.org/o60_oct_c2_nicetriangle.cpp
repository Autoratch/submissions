#include <bits/stdc++.h>
using namespace std;

const int N = 701;
const int MOD = 29947;

int x,y,z,dp[N][N],ans;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> x >> y >> z;
    x--,y--,z--;

    for(int i = 0;i < N;i++) for(int j = 0;j < N;j++)
    {
        if(i==0 or j==0) dp[i][j] = 1;
        else dp[i][j] = (dp[i][j-1]+dp[i-1][j])%MOD;
    }

    for(int i = 1;i <= x;i++) for(int j = 1;j <= y;j++)
    {
        int res = (dp[i-1][j-1]*dp[x-i+y-j][z])%MOD;
        ans = (ans+res)%MOD;
    }
    ans = (ans+dp[x+y][z])%MOD;

    cout << ans;
}
