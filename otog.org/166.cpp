#include <bits/stdc++.h>
using namespace std;

const int N = 1001;

int n,m,k;
pair<int,int> a[N];
int res[N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> m >> k;

    for(int i = 1;i <= n;i++) cin >> a[i-1].first,a[i-1].second = -i;

    sort(a,a+n);

    for(int i = 0;i < n;i++) res[-a[i].second] = n-i-1;

    while(m--)
    {
        int x;
        cin >> x;
        cout << res[x]/k+1 << ' ' << res[x]%k+1 << '\n';
    }
}
