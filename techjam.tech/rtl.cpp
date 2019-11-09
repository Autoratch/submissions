#include <bits/stdc++.h>
using namespace std;

const int N = 2001;
const int MOD = 1e9 + 7;

int n,m,a[N],b[N],s[N],t[N];
long long dp[N][N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n;
    for(int i = 1;i <= n;i++) cin >> a[i],s[i] = s[i-1]+a[i];
    cin >> m;
    for(int i = 1;i <= m;i++) cin >> b[i],t[i] = t[i-1]+b[i];
    for(int i = 0;i <= n;i++) for(int j = 0;j <= m;j++)
    {
        if(s[i]+t[j]<0) continue;
        if(i==0 and j==0) dp[i][j] = 1;
        if(i) dp[i][j] = (dp[i][j]+dp[i-1][j])%MOD;
        if(j) dp[i][j] = (dp[i][j]+dp[i][j-1])%MOD;
    }
    cout << dp[n][m];
}
