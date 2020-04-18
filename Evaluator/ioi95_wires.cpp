#include "wirelib.h"
#include <bits/stdc++.h>
using namespace std;

const int N = 91;

int n,sol[N];
bool status[N];

void solve(int l,int r,vector<int> res)
{
    if(l==r){ for(int x : res) sol[x] = l; return; }
    int m = (l+r)/2;
    for(int i = l;i <= m;i++) if(!status[i]) status[i] = cmd_C(i);
    for(int i = m+1;i <= r;i++) if(status[i]) status[i] = cmd_C(i);
    vector<int> L,R;
    for(int x :res) if(cmd_T(x)) L.push_back(x); else R.push_back(x);
    solve(l,m,L);
    solve(m+1,r,R);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    n = wire_init();
    
    vector<int> res;
    for(int i = 1;i <= n;i++) res.push_back(i);
    solve(1,n,res);

    cmd_D(sol);
}
