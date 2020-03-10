#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    int t,n,m;
    cin >> t;   
    while(t--){ cin >> n >> m; if(n%m==0) cout << "YES\n"; else cout << "NO\n"; }
}
