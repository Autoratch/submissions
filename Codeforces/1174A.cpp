#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n;

    cin >> n;

    set<int> s;
    vector<int> a(n*2);

    for(int i = 0;i < n*2;i++) cin >> a[i],s.insert(a[i]);

    if(s.size()==1){ cout << "-1"; return 0; }
    
    sort(a.begin(),a.end());

    for(int x : a) cout << x << ' ';
}
