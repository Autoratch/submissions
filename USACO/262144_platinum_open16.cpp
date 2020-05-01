#include <bits/stdc++.h>
using namespace std;

const int N = (1 << 18)+1;
const int K = 70;

int n,a[N],dp[K][N],ans;

int main()
{
    freopen("262144.in","r",stdin);
    freopen("262144.out","w",stdout);
    cin >> n;
    for(int i = 1;i <= n;i++) cin >> a[i],ans = max(ans,a[i]);
    for(int i = 1;i < K;i++) for(int j = 1;j <= n;j++)
    {
        if(a[j]==i) dp[i][j] = j;
        else 
        {
            if(!dp[i-1][j]) continue;
            if(!dp[i-1][dp[i-1][j]-1]) continue;
            dp[i][j] = dp[i-1][dp[i-1][j]-1];
            ans = max(ans,i);
        }
    }
    cout << ans;
}
