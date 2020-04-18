#include <bits/stdc++.h>
using namespace std;

const int N = 1001;

int n,l,a[N];
double ans;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> l;
    for(int i = 1;i <= n;i++) cin >> a[i];
    sort(a+1,a+n+1);
    for(int i = 1;i < n;i++) ans = max(ans,(a[i+1]-a[i])/2.0);
    ans = max(ans,(double)a[1]);
    ans = max(ans,(double)l-(double)a[n]);
    cout << fixed;
    cout << setprecision(3) << ans;
}
