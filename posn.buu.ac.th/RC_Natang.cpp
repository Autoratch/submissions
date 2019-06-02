#include <bits/stdc++.h>
using namespace std;

const int M = 641;
const int N = 361;

int m,n;
int a[M][N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    while(true)
    {
        char c;
        cin >> c;
        if(c=='I') cin >> m >> n;
        else if(c=='C')
        {
            int idx,l,r,u,d;
            cin >> idx >> l >> u >> r >> d;
            for(int i = l;i < min(l+r,m);i++) for(int j = u;j < min(u+d,n);j++) a[i][j] = idx;
        }
        else if(c=='G')
        {
            int x,y;
            cin >> x >> y;
            cout << a[x][y] << '\n';
        }
        else return 0;
    }
}
