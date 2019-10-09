#include <bits/stdc++.h>
using namespace std;

int t;
long long a,b;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> t;

    while(t--)
    {
        cin >> a >> b;
        if(a-b==1) cout << "NO\n";
        else cout << "YES\n";
    }
}
