#include <bits/stdc++.h>
using namespace std;

const int N = 1 << 17;

int n,m,t;
vector<int> adj[N];
int sz[N],nxt[N],in[N],pa[N];
struct node{ int val; friend node operator+(const node &a,const node &b){ if(b.val) return b; return a; } }tree[N << 1];

void dfs(int u,int p)
{
    sz[u] = 1;
    for(int i = 0;i < adj[u].size();i++)
    {
        int v = adj[u][i];
        dfs(v,u);
        sz[u]+=sz[v];
        if(sz[v]>sz[adj[u][0]]) swap(adj[u][0],adj[u][i]);
    }
}

void hld(int u)
{
    in[u] = ++t;
    for(int v : adj[u])
    {
        if(v==adj[u][0]) nxt[v] = nxt[u];
        else nxt[v] = v;
        hld(v);
    }
}

void update(int l,int r,int idx,int x,int k)
{
    if(x<l or x>r) return;
    if(l==r) return void(tree[idx] = {k});
    int m = (l+r)/2;
    update(l,m,idx*2,x,k),update(m+1,r,idx*2+1,x,k);
    tree[idx] = tree[idx*2]+tree[idx*2+1];
}

node read(int l,int r,int idx,int x,int y)
{
    if(x>r or y<l) return {0};
    if(x<=l and y>=r) return tree[idx];
    int m = (l+r)/2;
    return read(l,m,idx*2,x,y)+read(m+1,r,idx*2+1,x,y);
}

int query(int u)
{
    while(true)
    {
        if(u==0) return 1;
        int tmp = read(1,n,1,in[nxt[u]],in[u]).val;
        if(tmp) return tmp;
        u = pa[nxt[u]];     
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> m;
    for(int i = 2;i <= n;i++)
    {
        int x;
        cin >> x;
        pa[i] = x;
        adj[x].push_back(i);
    }
    dfs(1,0);
    hld(1);
    update(1,n,1,1,1);
    for(int i = 0;i < m;i++)
    {
        int x,y;
        cin >> x >> y;
        if(x==1) update(1,n,1,in[y],y);
        else if(x==2) update(1,n,1,in[y],0);
        else cout << query(y) << '\n';
    }
}
