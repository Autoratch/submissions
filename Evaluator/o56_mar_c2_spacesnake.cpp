#include <bits/stdc++.h>
using namespace std;

long long x,y;
long long a;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> x >> y;
    if(x==0 and y==0){ cout << "0"; return 0; }
    long long b = max(abs(x),abs(y))-1,c = 2LL*b+1LL;
    a = c*c+1LL;
    if(y==b+1LL) 
    {
        if(x==-(b+1LL)){ cout << (2LL*(b+1LL)+1LL)*(2LL*(b+1LL)+1LL); return 0; }
        else{ cout << a+(x-(-b)); return 0; }
    }
    else if(x==b+1LL)
    {
        a+=c;
        cout << a+(b+1LL-y);
        return 0;
    }
    else if(y==-(b+1LL))
    {
        a+=c+1LL;
        cout << a+(b+1LL-x);
        return 0;
    }
    else
    {
        a+=c+1LL;
        cout << a+(y-(-(b+1LL)));
    }
}
