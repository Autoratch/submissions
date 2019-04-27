#include <bits/stdc++.h>
using namespace std;

const int M = 5051;
const int N = 1e6 + 2;

int n,m,q;
int a[N],l[M],r[M];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> m >> q;

    for(int i = 1;i <= m;i++) cin >> l[i] >> r[i];

    while(q--)
    {
        int x;
        cin >> x;
        a[l[x]]++;
        a[r[x]+1]--;
    }

    for(int i = 1;i <= n;i++) a[i]+=a[i-1];

    for(int i = 1;i <= n;i++) cout << a[i] << '\n';
}
