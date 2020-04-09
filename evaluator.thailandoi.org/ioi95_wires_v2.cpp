#include "wirelib.h"
#include <bits/stdc++.h>
using namespace std;

const int N = 91;

int n,sol[N];
bool state[N];
vector<int> a;

void solve(int l,int r,vector<int> a)
{
    if(l==r) 
    {
        for(int x : a) sol[x] = l;
        return;
    }
    int m = (l+r)/2;
    for(int i = l;i <= m;i++) if(!state[i]) state[i] = cmd_C(i);
    for(int i = m+1;i <= r;i++) if(state[i]) state[i] = cmd_C(i);
    vector<int> b,c;
    for(int x : a) if(cmd_T(x)) b.push_back(x); else c.push_back(x);
    solve(l,m,b),solve(m+1,r,c);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    n = wire_init();

    for(int i = 1;i <= n;i++) a.push_back(i);
    solve(1,n,a);
        
    cmd_D(sol);
}
