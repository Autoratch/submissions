#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 1;

int t,n;
int pa[N],sz[N];

int root(int x){ if(pa[x]==x) return x; else return pa[x] = root(pa[x]); }

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> t;

    while(t--)
    {
        cin >> n;
        for(int i = 1;i <= n;i++) sz[i] = 1,pa[i] = i;
        for(int i = 1;i <= n;i++)
        {
            int x;
            cin >> x;
            int y = i;
            if(root(x)==root(y)) continue;
            int sx = sz[root(x)],sy = sz[root(y)];
            pa[root(x)] = root(y);
            sz[root(y)] = sx+sy;
        }
        for(int i = 1;i <= n;i++) cout << sz[root(i)] << ' ';
        cout << '\n';
    }

}
