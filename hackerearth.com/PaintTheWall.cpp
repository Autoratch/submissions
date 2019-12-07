#include <bits/stdc++.h>
using namespace std;

const int N = 1001;

int t,n,m,k;
long long a[N][N],s[N][N];
long long ans;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> t;
    while(t--)
    {
        cin >> m >> n >> k;
        for(int i = 1;i <= m;i++) for(int j = 1;j <= n;j++) cin >> a[i][j],s[i][j] = s[i-1][j]+s[i][j-1]-s[i-1][j-1]+a[i][j];
        ans = LLONG_MAX;
        for(int i = 1;i <= m;i++) for(int j = 1;j <= n;j++)
        {
            if(i+2-1<=m and j+k-1<=n) ans = min(ans,s[i+2-1][j+k-1]-s[i+2-1][j-1]-s[i-1][j+k-1]+s[i-1][j-1]);
            if(i+k-1<=m and j+2-1<=n) ans = min(ans,s[i+k-1][j+2-1]-s[i+k-1][j-1]-s[i-1][j+2-1]+s[i-1][j-1]);
        }
        if(ans==LLONG_MAX) ans = -1;
        cout << ans << '\n';
    }
}
