#include <bits/stdc++.h>
using namespace std;

const int N = 100;

int n,a[N],ans = INT_MAX;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n;

    for(int i = 0;i < n;i++) cin >> a[i];
    sort(a,a+n);

    for(int i = 1;i <= 100;i++)
    {
        int x;
        if(abs(i-a[0])==0) x = abs(i-a[n-1]);
        else x = abs(i-a[0]);
        bool ok = true;
        for(int j = 0;j < n;j++) if(x!=abs(i-a[j]) and i!=a[j]) ok = false;
        if(ok) ans = min(ans,x);
    }

    if(ans==INT_MAX) ans = -1;
    cout << ans;
}
