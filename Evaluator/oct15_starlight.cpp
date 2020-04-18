#include <bits/stdc++.h>
using namespace std;

int n,sz;
int x[5000],y[5000];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    cin >> sz >> n;

    for(int i = 0;i < n;i++) cin >> x[i] >> y[i];

    sort(x,x+n);
    sort(y,y+n);

    int mx = 0,my = 0;

    for(int i = 0;i < n-1;i++){ mx = max(mx,x[i+1]-x[i]); my = max(my,y[i+1]-y[i]); }
    mx = max(mx,x[0]);
    mx = max(mx,sz-x[n-1]);
    my = max(my,y[0]);
    my = max(my,sz-y[n-1]);

    double ans = min(mx,my);
    ans/=2.0;

    cout << fixed;
    cout << setprecision(3) << ans;
}
