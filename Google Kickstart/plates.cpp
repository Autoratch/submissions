#include <bits/stdc++.h>
using namespace std;

const int N = 51;
const int K = 31;
const int P = 1501;

int t,n,k,p,ans;
int a[N][K],dp[P][N],s[N][K];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> t;
    for(int tt = 1;tt <= t;tt++)
    {
        cin >> n >> k >> p;
        ans = 0;
        for(int i = 1;i <= n;i++) for(int j = 1;j <= k;j++) cin >> a[i][j],s[i][j] = s[i][j-1]+a[i][j];
        for(int i = 1;i <= p;i++) for(int j = 1;j <= n;j++) dp[i][j] = 0;
        for(int i = 1;i <= n;i++) for(int j = 0;j <= k;j++) for(int x = 1;x <= p;x++)
        {
            if(x>=j) dp[x][i] = max(dp[x][i],dp[x-j][i-1]+s[i][j]);
            ans = max(ans,dp[x][i]);
        }
        cout << "Case #" << tt << ": " << ans << '\n';
    }
}
