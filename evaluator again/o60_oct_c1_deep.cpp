#include <bits/stdc++.h>
using namespace std;

const int N = 2e5;

int n,q;
int l[N],r[N];
vector<int> jmp[N];

int s,a,b;

int dir()
{
    int res = ((s&8) >> 3);
    s = (s*a+b)%40507;
    return res;
}

void sol(int x,int pa)
{
    if(l[x]==-1 and r[x]==-1) return;
    if(r[x]==-1) jmp[pa].push_back(l[x]),sol(l[x],pa);
    else if(l[x]==-1) jmp[pa].push_back(r[x]),sol(r[x],pa);
    else sol(l[x],l[x]),sol(r[x],r[x]);
}

void solve(int lv,int x)
{
    if(lv==0 or (l[x]==-1 and r[x]==-1)){ cout << x << '\n'; return; }
    if(l[x]==-1 or r[x]==-1)
    {
        int sz = jmp[x].size();
        if(lv<=sz) solve(0,jmp[x][lv-1]);
        else solve(lv-sz,jmp[x][sz-1]);
    }
    else if(!dir()) solve(lv-1,l[x]);
    else solve(lv-1,r[x]);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    cin >> n >> q;

    for(int i = 0;i < n;i++) cin >> l[i] >> r[i];

    sol(0,0);

    while(q--)
    {
        int x;
        cin >> x >> s >> a >> b;
        solve(x,0);
    }
}
