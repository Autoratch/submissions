#include <bits/stdc++.h>
using namespace std;

long long n;
vector<long long> a;
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n;

    a.resize(n);

    for(long long i = 0;i < n;i++) cin >> a[i];

    sort(a.begin(),a.end());

    long long l = 0,r = n-1;

    long long ans = 0;

    while(true)
    {
        ans+=(a[l]+a[r])*(a[l]+a[r]);
        l++;
        r--;
        if(l>=r) break;
    }

    cout << ans;

}
