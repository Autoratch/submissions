#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    int t,a,b,c,d,k;

    cin >> t;
    
    while(t--)
    {
        cin >> a >> b >> c >> d >>  k;
        int x = (a+c-1)/c,y = (b+d-1)/d;
        if(x+y>k) cout << "-1\n";
        else cout << x << ' ' << y << '\n';
    }
}
