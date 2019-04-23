#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 1;

int n,k;
long long a[N],mn = LLONG_MAX,ans = LLONG_MIN;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> k;

    for(int i = 1;i <= n;i++)
    {
        cin >> a[i];
        a[i]+=a[i-1];
        if(i>=k)
        {
            mn = min(mn,a[i-k]);
            ans = max(ans,a[i]-mn);
        }
    }

    cout << ans;
}
