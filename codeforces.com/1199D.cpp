#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 1;

int n,q,a[N],lst[N],up[N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n;
    
    for(int i = 1;i <= n;i++) cin >> a[i];

    cin >> q;

    for(int i = 1;i <= q;i++)
    {
        int t;
        cin >> t;
        if(t==1)
        {
            int x,y;
            cin >> x >> y;
            a[x] = y,lst[x] = i;
        }
        else
        {
            int x;
            cin >> x;
            up[i] = x;
        }
    }

    for(int i = q-1;i >= 0;i--) up[i] = max(up[i],up[i+1]);

    for(int i = 1;i <= n;i++) cout << max(a[i],up[lst[i]]) << ' ';
}
