#include <bits/stdc++.h>
using namespace std;

const int N = 4e5 + 12;
const int MOD = 1e9;

int m,n,k,ans = 1,am;
int pa[N];

int root(int x){ if(pa[x]==x) return x; return pa[x] = root(pa[x]); }

int f(int x){ return m+n+x; }

void connect(int a,int b){ if(root(a)!=root(b)) pa[root(a)] = root(b); }

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> m >> n >> k;
    for(int i = 1;i < N;i++) pa[i] = i;
    while(k--)
    {
        int x,y;
        bool k;
        cin >> x >> y >> k;
        k^=((x%2==0) and (y%2==0));
        int a = x,b = y+m;
        if(k) connect(a,f(b)),connect(f(a),b);
        else connect(a,b),connect(f(a),f(b));
    }
    for(int i = 1;i <= n+m;i++) if(root(f(i))==root(i)){ cout << "0"; return 0; } else if(root(i)==i) am++;
    am--;
    while(am--) ans = (ans*2LL)%MOD;
    cout << ans;
}
