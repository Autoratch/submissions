#include <bits/stdc++.h>
using namespace std;

const int N = 1001;

int m,n;
long long a[N][N],s[N][N][3];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); 

    cin >> m >> n;

    for(int i = 1;i <= m;i++) for(int j = 1;j <= n;j++) cin >> a[i][j];

    for(int i = 1;i <= m;i++) for(int j = 1;j <= n;j++) for(int k = 0;k < 3;k++)
    {
        if(k) s[i][j][k] = max(s[i][j-1][k-1],s[i-1][j][k-1])+a[i][j];
        else 
        {
            for(int x = 0;x < 3;x++) s[i][j][k] = max(s[i][j][k],s[i][j-1][x]),s[i][j][k] = max(s[i][j][k],s[i-1][j][x]);
        }
    }

    long long ans = 0;

    for(int i = 0;i < 3;i++) ans = max(ans,s[n][n][i]);

    cout << ans;
}