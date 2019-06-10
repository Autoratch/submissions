#include <bits/stdc++.h>
using namespace std;

const int N = 1e5;

int n,m;
int a[N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> m;

    for(int i = 0;i < n;i++) cin >> a[i];

    while(m--)
    {
        int x,y;
        cin >> x >> y;
        swap(a[x-1],a[y-1]);
    }

    for(int i = 0;i < n;i++) cout << a[i] << ' ';
}
