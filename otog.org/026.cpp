#include <bits/stdc++.h>
using namespace std;

int n,m;
map<int,set<int> > s;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> m;

    for(int i = 0;i < m;i++)
    {
        int x,y;
        cin >> x >> y;
        s[x].insert(y);
    }

    for(int i = 1;i <= n;i++) cout << i << ' ' << s[i].size() << '\n';
}
