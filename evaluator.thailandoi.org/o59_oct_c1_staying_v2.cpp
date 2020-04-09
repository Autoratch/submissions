#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 1;
const int MOD = 1e9 + 7;

int n,a[3];
long long dp[N][3][N][8],sum[N][3][8];
vector<int> t;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n;
    for(int i = 0;i < 3;i++) cin >> a[i];

    sum[1][0][1] = dp[1][0][1][1] = 1;
    for(int i = 2;i <= n;i++)
    {
        for(int j = 0;j < 3;j++) for(int k = 1;k <= a[j];k++) for(int l = 0;l < 8;l++)
        {
            t.assign(4,false);
            int tmp = l,idx = 0;
            while(tmp) t[idx++] = tmp%2,tmp/=2;
            if(!t[j]) continue;
            dp[i][j][k][l] = dp[i-1][j][k-1][l];
            if(j==0) 
            {
                if(k==1) dp[i][j][k][l] = (dp[i][j][k][l]+sum[i-1][2][l]+sum[i-1][2][l-1])%MOD;
            }
            else if(j==1)
            {
                if(k==1) dp[i][j][k][l] = (dp[i][j][k][l]+sum[i-1][0][l]+sum[i-1][0][l-2])%MOD;
            }
            else
            {
                if(k==1) dp[i][j][k][l] = (dp[i][j][k][l]+sum[i-1][0][l]+sum[i-1][1][l]+sum[i-1][0][l-4]+sum[i-1][1][l-4])%MOD;
            }
            sum[i][j][l] = (sum[i][j][l]+dp[i][j][k][l])%MOD;
        }
    }

    int ans = 0;
    for(int i = 0;i < 3;i++) for(int j = 1;j <= a[i];j++) ans = (ans+dp[n][i][j][7])%MOD;

    cout << ans;
}
