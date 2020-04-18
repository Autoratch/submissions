#include <bits/stdc++.h>
using namespace std;

const int N = 401;
const int L = 51;

int n,m,l,d,x,ans;
int a[N],c[N][N],dp[N][N][L];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> m >> l >> d >> x; x++,d++;
    for(int i = 1;i <= n;i++) cin >> a[i];
    for(int i = 1;i <= m;i++) for(int j = 1;j <= n;j++) cin >> c[i][j];
    for(int i = 1;i <= n;i++) for(int j = 1;j <= m;j++) for(int k = 1;k <= l;k++)
    {
        dp[i][j][k] = a[i]-c[j][i];
        if(i>x and j>d) dp[i][j][k]+=dp[i-x][j-d][k-1];
        dp[i][j][k] = max(dp[i][j][k],max(dp[i-1][j][k],dp[i][j-1][k]));
        ans = max(ans,dp[i][j][k]);
    }
    cout << ans;
}
