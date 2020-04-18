#include <bits/stdc++.h>
using namespace std;

int t;
long long n,k;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> t;
    while(t--)
    {
        cin >> n >> k;
        if(n%2 != k%2 or n<k*k) cout << "NO\n";
        else cout << "YES\n";
    }
}
