#include <bits/stdc++.h>
using namespace std;

long long n,m;
int q;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> m >> q;
    
    long long g = __gcd(n,m);

    while(q--)
    {
        long long a,b,c,d;
        cin >> a >> b >> c >> d;
        b--,d--;
        long long x,y;
        if(a==1) x = b/(n/g);
        else x = b/(m/g);
        if(c==1) y = d/(n/g);
        else y = d/(m/g);
        if(x==y) cout << "YES\n";
        else cout << "NO\n";
    }
}
