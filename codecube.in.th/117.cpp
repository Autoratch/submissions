#include <bits/stdc++.h>
using namespace std;

const int N = 1000;
const int K = 1e5 + 8;

int t,n,k,pre,cur = 1;
int a[N],dp[K][2];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> t;
    dp[0][0] = dp[0][1] = 1;
    for(int x = 1;x <= t;x++)
    {
        cin >> n >> k;
        for(int i = 0;i < n;i++) cin >> a[i];
        for(int i = 1;i < k;i++) dp[i][pre] = dp[i][cur] = 0;
        for(int i = 0;i < n;i++) 
        {
            for(int j = 0;j < k;j++) dp[(j+a[i])%k][cur]|=dp[j][pre];
            for(int j = 0;j < k;j++) dp[j][pre]|=dp[j][cur];
        }
        int ans = 0;
        for(int i = 0;i < k;i++) if(dp[i][cur]) ans = i;
        cout << "Case #" << x << ": " << ans << '\n';
    }
}
