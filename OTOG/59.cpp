#include <bits/stdc++.h>
using namespace std;

const int N = 1e5;

int n;
int a[N],b[N];
int mx;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n;

    for(int i = 0;i < n;i++) cin >> a[i];
    for(int i = 0;i < n;i++) cin >> b[i];

    sort(a,a+n),sort(b,b+n);

    for(int i = 0;i < n;i++) mx = max(mx,min(a[i],b[n-i-1]));

    cout << mx;
}
