#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 2;

int n,k;
long long a[N],l[N],r[N],ans;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> k;

    for(int i = 1;i <= n;i++) cin >> a[i];

    for(int i = 1;i <= n;i++) l[i] = l[i-1]+a[i];

    for(int i = n;i >= 1;i--) r[i] = r[i+1]+a[i];

    for(int i = 1;i <= k;i++) ans = max(ans,l[i]+r[n+1+i-k]);

    cout << ans;
}
