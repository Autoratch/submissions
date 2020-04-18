#include <bits/stdc++.h>
using namespace std;

const int N = 101;

int n,m,k;
int a[N];
int ans = INT_MAX;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> m >> k;

    for(int i = 1;i <= n;i++) cin >> a[i];

    for(int i = 1;i <= n;i++) if(a[i] and a[i]<=k) ans = min(ans,abs(i-m));

    cout << ans << '0';
}
