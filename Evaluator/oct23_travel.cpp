#include <bits/stdc++.h>
using namespace std;

const int N = 3e4 + 1;
const int M = 1 << 16;

int n,q,sz,lst = 1,ans;
vector<int> adj[N],s;
int f[N],dist[N];

struct node
{
    int fi,val;
    friend node operator+(const node &a,const node &b)
    {
        if(a.fi<b.fi) return a;
        else return b;
    }
}tree[M << 1];

void dfs(int u,int p)
{
    s.push_back(u);
    f[u] = s.size();
    for(int v : adj[u])
    {
        if(v==p) continue;
        dist[v] = dist[u]+1;
        dfs(v,u);
        s.push_back(u);
    }
}

void build(int l,int r,int idx)
{
    if(l==r){ tree[idx].fi = f[s[l]]; tree[idx].val = s[l]; return; }
    int m = (l+r)/2;
    build(l,m,idx*2);
    build(m+1,r,idx*2+1);
    tree[idx] = tree[idx*2]+tree[idx*2+1];
}

node read(int l,int r,int idx,int x,int y)
{
    if(x>r or y<l){ node ret; ret.fi = INT_MAX; return ret; }
    if(x<=l and y>=r) return tree[idx];
    int m = (l+r)/2;
    return read(l,m,idx*2,x,y)+read(m+1,r,idx*2+1,x,y);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n;

    for(int i = 0;i < n-1;i++)
    {
        int a,b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs(1,1);
    sz = s.size();
    build(0,sz-1,1);

    cin >> q;

    while(q--)
    {
        int a,b = lst;
        cin >> a;
        lst = a;
        if(f[a]>f[b]) swap(a,b);
        int lca = read(0,sz-1,1,f[a]-1,f[b]-1).val;
        ans+=dist[a]+dist[b]-dist[lca]*2;
    }

    cout << ans;
}
