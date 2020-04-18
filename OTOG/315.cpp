#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 1;

int n,a[N],b[N],res[N],mx,mn;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n;

    for(int i = 1;i <= n;i++){ int x; cin >> x; a[x] = i; }

    for(int i = 1;i <= n;i++){ int x; cin >> x; b[x] = i; }

    for(int i = 1;i <= n;i++)
    {
        int tmp = b[i]-a[i];
        if(tmp<0) tmp+=n;
        res[tmp]++;
    }

    for(int i = 0;i < n;i++)
    {
        if(res[i]>mx) mx = res[i],mn = i;
    }

    cout << mx << ' ' << mn;
}
