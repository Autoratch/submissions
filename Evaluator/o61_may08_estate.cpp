#include <bits/stdc++.h>
using namespace std;

const int N = 1 << 17;
const int K = 20;

int n,k,t;
vector<int> adj[N];
int sz[N],pa[N],nx[N],in[N];
struct node
{
    int res[K];
    friend node operator+(const node &a,const node &b)
    {
        node ret;
        for(int i = 0;i < k;i++) ret.res[i] = a.res[i]+b.res[i];
        return ret;
    }
}tree[N << 1];
int lazy[N << 1];

void dfs(int u,int p)
{
    sz[u] = 1;
    for(int &v : adj[u]) if(v!=p)
    {
        dfs(v,u);
        sz[u]+=sz[v];
        if(sz[v]>sz[adj[u][0]]) swap(v,adj[u][0]);
    }
}

void hld(int u,int p)
{
    in[u] = ++t;
    for(int v : adj[u]) if(v!=p)
    {
        if(v==adj[u][0]) nx[v] = nx[u];
        else nx[v] = v;
        hld(v,u);
    }
}

void pushlz(int l,int r,int idx)
{
    if(!lazy[idx]) return;
    int sum = 0;
    for(int i = 0;i < k;i++) sum+=tree[idx].res[i];
    sum = r-l+1-sum;
    for(int j = 0;j < lazy[idx];j++)
    {
        int tmp = tree[idx].res[k-1];
        for(int i = k-1;i >= 1;i--) tree[idx].res[i] = tree[idx].res[i-1];
        tree[idx].res[0] = tmp;
    }
    tree[idx].res[lazy[idx]%k]+=sum;
    if(l!=r) lazy[idx*2]+=lazy[idx],lazy[idx*2+1]+=lazy[idx];
    lazy[idx] = 0;
}

void update(int l,int r,int idx,int x,int y)
{
    pushlz(l,r,idx);
    if(x>r or y<l) return;
    if(x<=l and y>=r)
    {
        lazy[idx]++;
        pushlz(l,r,idx);
        return;
    }
    int m = (l+r)/2;
    update(l,m,idx*2,x,y),update(m+1,r,idx*2+1,x,y);
    tree[idx] = tree[idx*2]+tree[idx*2+1];
}

node read(int l,int r,int idx)
{
    pushlz(l,r,idx);
    return tree[idx];
}

void query(int u)
{
    while(u)
    {
        update(1,n,1,in[nx[u]],in[u]);
        u = pa[nx[u]];
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> k;
    for(int i = 2;i <= n;i++) cin >> pa[i],adj[pa[i]].push_back(i);
    nx[1] = 1;
    dfs(1,0);
    hld(1,0);
    for(int i = 1;i <= n;i++)
    {
        query(i);
        if(i>1)
        {
            if(read(1,n,1).res[0]*k==i) cout << "YES\n";
            else cout << "NO\n";
        }
    }
}
