#include <bits/stdc++.h>
using namespace std;

const int N = 1000;

int n,m;
int a[N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> m;

    for(int i = 0;i < n;i++) cin >> a[i];
    for(int i = 0;i < m;i++)
    {
        int l,r;
        cin >> l >> r;
        l--;
        r+=l-1;
        while(l<r)
        {
            swap(a[l%n],a[r%n]);
            l++; r--;
        }
    }
    for(int i = 0;i < n;i++) cout << a[i] << ' ';
}
