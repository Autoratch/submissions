#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 1;

int n,q;
int pa[N];

int root(int x){ if(pa[x]==x) return x; else return pa[x] = root(pa[x]); }

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> q;
    for(int i = 1;i <= n;i++) pa[i] = i;
    while(q--)
    {
        char c;
        int a,b;
        cin >> c >> a >> b;
        if(c=='c'){ if(root(a)!=root(b)) pa[root(a)] = root(b); }
        else{ if(root(a)==root(b)) cout << "yes\n"; else cout << "no\n"; }
    }
}