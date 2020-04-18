#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n;

    cin >> n;

    vector<int> a(n);

    for(int i = 0;i < n;i++) cin >> a[i];

    sort(a.begin(),a.end());

    int mx = 0;

    for(int i = 0;i < n;i++)
    {
        auto it = upper_bound(a.begin(),a.end(),a[i]+5);
        mx = max(mx,(int)(it-a.begin())-i);
    }

    cout << mx;
}
