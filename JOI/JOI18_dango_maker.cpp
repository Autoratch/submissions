#include <bits/stdc++.h>
using namespace std;

const int N = 3002;

int m,n,ans;
char c[N][N];
int a[N][N][3];
bool val[N][N][2];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> m >> n;
    for(int i = 1;i <= m;i++) for(int j = 1;j <= n;j++) cin >> c[i][j];
    for(int i = 1;i <= m;i++) for(int j = 1;j <= n;j++)
    {
        if(c[i-1][j]=='R' and c[i][j]=='G' and c[i+1][j]=='W') val[i][j][0] = true;
        if(c[i][j-1]=='R' and c[i][j]=='G' and c[i][j+1]=='W') val[i][j][1] = true;
    }
    for(int i = 1;i <= m;i++) for(int j = 1;j <= n;j++)
    {
        a[i][j][0] = max(a[i-1][j+1][0],max(a[i-1][j+1][1],a[i-1][j+1][2]));
        if(val[i][j][0]) a[i][j][1] = 1+max(a[i-1][j+1][0],a[i-1][j+1][1]);
        if(val[i][j][1]) a[i][j][2] = 1+max(a[i-1][j+1][0],a[i-1][j+1][2]);
    }
    for(int i = 1;i <= m;i++) ans+=max(a[i][1][0],max(a[i][1][1],a[i][1][2]));
    for(int i = 2;i <= n;i++) ans+=max(a[m][i][0],max(a[m][i][1],a[m][i][2]));
    cout << ans;
}
