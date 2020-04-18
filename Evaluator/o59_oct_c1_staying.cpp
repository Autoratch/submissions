#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 1;
const int MOD = 1e9 + 7;

int n,k[3],ans;
int dp[N][3][N][8],sum[N][3][8];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> k[0] >> k[1] >> k[2];
 
    dp[1][0][1][1] = 1;
    sum[1][0][1] = 1;
    for(int i = 2;i <= n;i++)
    {
        for(int x = 0;x < 3;x++) for(int l = 1;l <= k[x];l++) for(int j = 1;j < 8;j++)
        {
            vector<bool> t(3);
            int tmp = j,cnt = 0;
            while(tmp)
            {
                t[cnt] = tmp%2;
                tmp/=2;
                cnt++;
            }
            if(!t[x]) continue;
            for(int y = 0;y < 3;y++)
            {
                if(!t[y]) continue;
                if(x==0 and y==1) continue;
                if(x==1 and y==2) continue;
                if(x==y)
                {
                    if(l==1) continue;
                    dp[i][x][l][j] = (dp[i][x][l][j]+dp[i-1][x][l-1][j])%MOD;
                }
                else
                {
                    if(l!=1) continue;
                    dp[i][x][l][j] = (dp[i][x][l][j]+sum[i-1][y][j^(1 << x)]+sum[i-1][y][j])%MOD;
                }
            }
            sum[i][x][j] = (sum[i][x][j]+dp[i][x][l][j])%MOD;
        }
    }

    for(int i = 0;i < 3;i++) ans = (ans+sum[n][i][7])%MOD;

    cout << ans;
}
