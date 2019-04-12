#include <bits/stdc++.h>
using namespace std;

const int N = 2e5;

int n,m,k;
int l[N],r[N];
vector<int> ch[N];

int solve(int lv,int s,int a,int b,int u)
{
    if(lv==k) return u;
    if(l[u]==-1 and r[u]==-1) return u;
    if(l[u]!=-1 and r[u]!=-1) 
    {
        int res = ((s & 8) >> 3);
        s = (s*a + b)%40507;
        if(!res) return solve(lv+1,s,a,b,l[u]);
        else return solve(lv+1,s,a,b,r[u]);
    }
    return solve(min(lv+(int)ch[u].size(),k),s,a,b,ch[u][min((int)ch[u].size()-1,k-lv-1)]);
}

void dfs(int u,int p)
{
    if(u!=p) ch[p].push_back(u);
    if(l[u]==-1 and r[u]==-1) return;
    if(l[u]==-1 or r[u]==-1)
    {
        if(l[u]==-1) dfs(r[u],p);
        if(r[u]==-1) dfs(l[u],p);
        return;
    }
    dfs(l[u],l[u]);
    dfs(r[u],r[u]);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> m;

    for(int i = 0;i < n;i++) cin >> l[i] >> r[i];

    dfs(0,0);

    for(int i = 0;i < m;i++)
    {
        int s,a,b;
        cin >> k >> s >> a >> b;
        cout << solve(0,s,a,b,0) << '\n';
    }
}
