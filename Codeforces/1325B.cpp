#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    int t;
    set<int> s;
    cin >> t;
    while(t--)
    {
        s.clear();
        int n;
        cin >> n;
        while(n--){ int x; cin >> x; s.insert(x); }
        cout << s.size() << '\n';
    }
}
