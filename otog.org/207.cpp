#include <bits/stdc++.h>
using namespace std;

const int N = 1001;

int n,q;
int a[N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> q;

    for(int i = 1;i <= n;i++) cin >> a[i],a[i]+=a[i-1];

    while(q--)
    {
        int x,y;
        cin >> x >> y;
        cout << a[y]-a[x-1] << '\n';
    }
}
