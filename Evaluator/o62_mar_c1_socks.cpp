#include "sockslib.h"
#include <bits/stdc++.h>
using namespace std;

const int N = 2001;

int n;
bool kn[N];
vector<int> a,b;
int y;

void solve(int x,int l,int r)
{
    int m = (l+r)/2;
    if(l==r){ y = a[l]; return; }
    b.resize(0);
    for(int i = l;i <= m;i++) b.push_back(a[i]);
    int s = ask(b);
    b.push_back(x);
    if(ask(b)==s) solve(x,l,m);
    else solve(x,m+1,r);
}

int main()
{
    n = num();
    n*=2;

    for(int i = 1;i <= n;i++) if(!kn[i])
    {
        a.resize(0);
        for(int j = 1;j <= n;j++) if(!kn[j] and j!=i) a.push_back(j);
        solve(i,0,a.size()-1);
        match(i,y);
        kn[i] = true,kn[y] = true;
    }
}
