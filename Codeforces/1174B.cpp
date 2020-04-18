#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n;

    cin >> n;

    set<int> s;
    vector<int> a(n);

    for(int i = 0;i < n;i++) cin >> a[i],s.insert(a[i]%2);

    if(s.size()==2) sort(a.begin(),a.end());

    for(int x : a) cout << x << ' ';
}
