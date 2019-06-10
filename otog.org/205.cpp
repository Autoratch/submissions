#include <bits/stdc++.h>
using namespace std;

const int N = 1001;

int m,n,x,y;
int a[N][N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> m >> n >> x >> y;

    for(int i = 1;i <= m;i++) for(int j = 1;j <= n;j++) cin >> a[i][j];

    int s = 0;

    for(int i = 1;i <= m;i++) s+=a[i][y];
    for(int i = 1;i <= n;i++) s+=a[x][i];

    cout << s-a[x][y];
}
