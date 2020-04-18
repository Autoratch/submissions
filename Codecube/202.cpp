#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 1;

int n,a[N],ans;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n;
    for(int i = 1;i <= n;i++) cin >> a[i];
    for(int i = 1;i < n;i++) if(a[i+1]>a[i]) ans+=a[i+1]-a[i];
    cout << ans;
}
