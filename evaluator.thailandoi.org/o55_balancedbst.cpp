#include <bits/stdc++.h>
using namespace std;

int n,m;
set<int> s;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> m;

    for(int i = 0;i < n;i++){ int x; cin >> x; s.insert(x); }
    
    for(int i = 0;i < m;i++){ int x; cin >> x; if(s.find(x)==s.end()) cout << "n\n"; else cout << "y\n"; }
}
