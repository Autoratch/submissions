#include <bits/stdc++.h>
using namespace std;

int m,n,d,k,ans;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> m >> n >> d >> k;
    int a[m+2][n+2];
    char c[m+1][n+1];
    for(int i = 1;i <= m;i++) for(int j = 1;j <= n;j++) cin >> c[i][j];
    for(int i = 0;i <= m;i++) for(int j = 0;j <= n;j++) a[i][j] = 0;
    for(int i = 1;i <= m;i++) for(int j = 1;j <= n;j++) if(c[i][j]=='S') 
        a[max(1,i-d)][max(1,j-d)]++,a[min(m,i+d)+1][max(1,j-d)]--,a[max(1,i-d)][min(n,j+d)+1]--,a[min(m,i+d)+1][min(n,j+d)+1]++;
    for(int i = 1;i <= m;i++) for(int j = 1;j <= n;j++) a[i][j]+=a[i-1][j]+a[i][j-1]-a[i-1][j-1];
    for(int i = 1;i <= m;i++) for(int j = 1;j <= n;j++) if(c[i][j]=='M' and a[i][j]>=k) ans++;
    cout << ans;
}
