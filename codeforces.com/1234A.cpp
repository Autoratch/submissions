#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    int t;

    cin >> t;

    while(t--)
    {
        int n,s = 0;
        cin >> n;
        for(int i = 0;i < n;i++){ int x; cin >> x; s+=x; }
        cout << (s+n-1)/n << '\n';
    }
}
