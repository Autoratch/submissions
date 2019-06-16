#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 1;

int n,m,q;
int pa[N];

int root(int x)
{
    if(pa[x]==x) return x;
    else return pa[x] = root(pa[x]);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> m;

    for(int i = 1;i <= n;i++) pa[i] = i;

    for(int i = 0;i < m;i++)
    {
        int a,b;
        cin >> a >> b;
        if(root(a)!=root(b)) pa[root(a)] = root(b);
    }

    cin >> q;

    while(q--)
    {
        int a,b;
        cin >> a >> b;
        if(root(a)==root(b)) cout << "YES\n";
        else cout << "NO\n";
    }
}
