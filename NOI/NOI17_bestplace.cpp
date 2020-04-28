#include <bits/stdc++.h>
using namespace std;

const int N = 1e5;

int n;
int a[N],b[N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n;
    for(int i = 0;i < n;i++) cin >> a[i] >> b[i];
    sort(a,a+n),sort(b,b+n);
    cout << a[n/2] << ' ' << b[n/2];
}
