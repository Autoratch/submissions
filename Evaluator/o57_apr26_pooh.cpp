#include <bits/stdc++.h>
using namespace std;

const int N = 3001;

int m,n,k,a[N][N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> m >> n >> k;
    while(k--)
    {
        int x,y;
        cin >> x >> y;
        a[x+1][y+1] = 1;
    }
    for(int i = 1;i <= m;i++) for(int j = 1;j <= n;j++) a[i][j]+=max(a[i-1][j],a[i][j-1]);
    cout << a[m][n];
}
