#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n,k;

    cin >> n >> k;

    vector<int> a(n);

    for(int i = 0;i < n;i++) cin >> a[i];

    vector<int> b(k);

    for(int i = 0;i < n;i++) b[a[i]%k]++;

    int ans = 0;

    ans+=((b[0]/2)*2);

    for(int i = 1;i < k;i++)
    {
        if(k-i<i) break;
        if(k-i!=i) ans+=min(b[i],b[k-i])*2;
        else ans+=(b[i]/2)*2;
    }

    cout << ans;
}
