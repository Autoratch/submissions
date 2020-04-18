#include <bits/stdc++.h>
using namespace std;

const int N = 1001;

int m,n,q;
int a[N][N];
int s[N],t[N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> m >> n >> q;

    for(int i = 1;i <= m;i++) for(int j = 1;j <= n;j++) cin >> a[i][j];

    for(int i = 1;i <= m;i++) for(int j = 1;j <= n;j++) s[i]+=a[i][j],t[j]+=a[i][j];

    while(q--)
    {
        int x,y;
        cin >> x >> y;
        cout << s[x]+t[y]-a[x][y] << '\n';
    }
}
