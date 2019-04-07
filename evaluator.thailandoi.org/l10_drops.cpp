#include <bits/stdc++.h>
using namespace std;

int l,r,n;
int a[5001];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> r >> l >> n;
    r+=l;

    for(int i = 0;i < n;i++)
    {
        int x;
        cin >> x;
        a[x]++;
    }

    int ans = 0;

    for(int i = l;i <= r;i++) ans = max(ans,a[i]);

    cout << ans;
}
