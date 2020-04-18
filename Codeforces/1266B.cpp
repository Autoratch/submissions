#include <bits/stdc++.h>
using namespace std;

int t;
long long x;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> t;
    while(t--)
    {
        cin >> x;
        if(x<=14 or x%14==0LL or x%14LL>6LL) cout << "NO\n";
        else cout << "YES\n";
    }
}   
