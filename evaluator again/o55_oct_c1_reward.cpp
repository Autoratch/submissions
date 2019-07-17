#include <bits/stdc++.h>
using namespace std;

const int N = 1e5;

int n,k,mx;
int a[N];

bool solve(int x)
{
    int tmp = 0;
    for(int i = 0;i < n;i++) tmp+=(a[i]+x-1)/x;
    return tmp<=k;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> k;

    for(int i = 0;i < n;i++) cin >> a[i],mx = max(mx,a[i]);

    int l = 0,r = mx;

    while(l<r)
    {
        int m = (l+r)/2;
        bool ok = solve(m);
        if(ok) r = m;
        else l = m+1;
    }

    cout << l;
}
