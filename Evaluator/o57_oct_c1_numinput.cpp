#include <bits/stdc++.h>
using namespace std;

const int N = 1001;
const int MOD = 9901;

int n,m,a[N],dp[N][N],b[N];
bool fix[N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> m;

    for(int i = 1;i <= n;i++){ cin >> a[i]; a[i]+=a[i-1]; for(int j = a[i-1]+1;j <= a[i];j++) b[j] = i; }
    for(int i = 0;i < m;i++){ int x; cin >> x; fix[x] = true; }

    dp[0][0] = 1;
    for(int i = 1;i <= a[n];i++) for(int j = 1;j <= n;j++)
    {
        if(fix[i] and b[i]!=j) continue;
        dp[i][j] = (dp[i-1][j]+dp[i-1][j-1])%MOD;
    }

    cout << dp[a[n]][n];
}
