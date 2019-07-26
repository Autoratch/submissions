#include <bits/stdc++.h>
using namespace std;

const int N = 1e5;

int t,n;
int a[N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> t;

    while(t--)
    {
        cin >> n;
        for(int i = 0;i < n;i++) cin >> a[i];
        sort(a,a+n);
        cout << min(min(a[n-1],a[n-2])-1,n-2) << '\n';
    }
}
