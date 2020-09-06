#include "cycle.h"
#include <bits/stdc++.h>
using namespace std;

int n,now;

int ask(int x)
{
    int ne = x;
    x-=now;
    x+=n;
    x%=n;
    now = ne;
    return jump(x);
}

void escape(int _n) 
{
    n = _n;
    int l = 0,r = n-1;
    while(l<r)
    {
        int m = (l+r+1)/2;
        if(ask(m)) l = m;
        else r = m-1;
    }
    ask(l);
}
