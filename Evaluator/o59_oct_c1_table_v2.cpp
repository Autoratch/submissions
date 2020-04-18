#include <bits/stdc++.h>
using namespace std;

const int N = 5e3 + 1;

int m,n,q;
int a[N][N],mn[N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> m >> n >> q;

    while(q--)
    {
        int t;
        cin >> t;
        if(t==1)
        {
            int x,y,k;
            cin >> x >> y >> k;
            a[x][y] = k;
            mn[x] = INT_MAX;
            for(int i = 1;i <= n;i++) mn[x] = min(mn[x],a[x][i]);
        }
        else if(t==2)
        {
            int x,k;
            cin >> x >> k;
            for(int i = 1;i <= n;i++) a[x][i] = k;
            mn[x] = k;
        }
        else if(t==3)
        {
            int x,y;
            cin >> x >> y;
            cout << a[x][y] << '\n';
        }
        else
        {
            int ans = INT_MAX;
            for(int i = 1;i <= m;i++) ans = min(ans,mn[i]);
            cout << ans << '\n';
        }
    }
}
