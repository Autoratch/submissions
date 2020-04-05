#include <bits/stdc++.h>
using namespace std;

const int N = 101;

int t,n;
int a[N][N];
set<int> tmp;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> t;
    for(int tt = 1;tt <= t;tt++)
    {
        cin >> n;
        for(int i = 1;i <= n;i++) for(int j = 1;j <= n;j++) cin >> a[i][j];
        cout << "Case #" << tt << ": ";
        int s = 0;
        for(int i = 1;i <= n;i++) s+=a[i][i];
        cout << s << ' ';
        int x = 0,y = 0;
        for(int i = 1;i <= n;i++)
        {
            tmp.clear();
            for(int j = 1;j <= n;j++) tmp.insert(a[i][j]);
            if(tmp.size()<n) x++;
        }
        for(int i = 1;i <= n;i++)
        {
            tmp.clear();
            for(int j = 1;j <= n;j++) tmp.insert(a[j][i]);
            if(tmp.size()<n) y++;
        }
        cout << x << ' ' << y << '\n';
    }
}
