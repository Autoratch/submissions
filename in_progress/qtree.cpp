#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 1;

int t,n;
vector<tuple<int,int,int> > adj[N];
int sz[N],chr[N],idxst[N];
int dp[20][N],pa[N],lv[N];
int st[N],curst;
int res[N];
struct node{ int val; friend node operator+(const node &a,const node &b){ if(a.val>b.val) return a; else return b; } }tree[N << 4];
int edj[N];
map<pair<int,int>,int> edjval;
tuple<int,int,int> edge[N];

void dfs_sz(int u,int p)
{
    sz[u] = 1;
    for(auto [d,v,id] : adj[u]) if(v!=p) dfs_sz(v,u),sz[u]+=sz[v];
}

void dfs_hld(int root,int u,int p)
{
    st[++curst] = u;
    idxst[u] = curst;
    chr[u] = root;
    int mx = 0,idx,ed,idd,chh = 0;
    for(auto [d,v,id] : adj[u]) if(v!=p and sz[v]>mx) mx = sz[v],idx = v,ed = d,idd = id,chh++;
    if(!chh) return;
    res[curst] = ed,edj[idd] = curst;
    dfs_hld(root,idx,u);
    for(auto [d,v,id] : adj[u]) if(v!=p and v!=idx) dfs_hld(v,v,u);
}

void dfs_lca(int u,int p,int l)
{
    dp[0][u] = p,pa[u] = p,lv[u] = l;
    for(auto [d,v,id] : adj[u]) if(v!=p) dfs_lca(v,u,l+1);
}

int lca(int a,int b)
{
    if(lv[a]<lv[b]) swap(a,b);
    for(int i = 19;i >= 0;i--) if(lv[dp[i][a]]>=lv[b]) a = dp[i][a];
    if(a==b) return a;
    for(int i = 19;i >= 0;i--) if(dp[i][a]!=dp[i][b]) a = dp[i][a],b = dp[i][b];
    return dp[0][a];
}

void build(int l,int r,int idx)
{
    if(l==r){ tree[idx] = {res[l]}; return ; }
    int m = (l+r)/2;
    build(l,m,idx*2),build(m+1,r,idx*2+1);
    tree[idx] = tree[idx*2]+tree[idx*2+1];
}

void update(int l,int r,int idx,int x,int k)
{
    if(x>r or x<l) return;
    if(l==r){ tree[idx].val = k; return; }
    int m = (l+r)/2;
    update(l,m,idx*2,x,k),update(m+1,r,idx*2+1,x,k);
    tree[idx] = tree[idx*2]+tree[idx*2+1];
}

int read(int l,int r,int idx,int x,int y)
{
    if(x>y or x>r or y<l) return 0;
    if(x<=l and y>=r) return tree[idx].val;
    int m = (l+r)/2;
    return max(read(l,m,idx*2,x,y),read(m+1,r,idx*2+1,x,y));
}

int queryup(int x,int y)
{
    if(x==y) return 0;
    int ret = 0;
    while(true)
    {
        if(chr[x]==chr[y]){ ret = max(ret,read(1,n,1,idxst[y],idxst[x]-1)); break; }
        if(x!=chr[x]) ret = max(ret,read(1,n,1,idxst[chr[x]],idxst[x]-1));
        ret = max(ret,edjval[{chr[x],dp[0][chr[x]]}]);
        x = dp[0][chr[x]];
    }
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> t;
    while(t--)
    {
        cin >> n;
        for(int i = 1;i <= n;i++) adj[i].clear();
        for(int i = 0;i < n-1;i++)
        {
            int a,b,d;
            cin >> a >> b >> d;
            adj[a].push_back({d,b,i+1});
            adj[b].push_back({d,a,i+1});
            edjval[{a,b}] = d;
            edjval[{b,a}] = d;
            edge[i+1] = {a,b,d};
        }
        curst = 0;
        dfs_sz(1,0);
        dfs_hld(1,1,0);
        dfs_lca(1,0,1);
        for(int i = 1;i < 20;i++) for(int j = 1;j <= n;j++) dp[i][j] = dp[i-1][dp[i-1][j]];
        build(1,n,1);
        while(true)
        {
            string inp;
            cin >> inp;
            if(inp=="DONE") break;
            int x,y;
            cin >> x >> y;
            if(inp=="CHANGE")
            {
                update(1,n,1,edj[x],y);
                auto [a,b,d] = edge[x];
                edjval[{a,b}] = edjval[{b,a}] = y;
            }
            else
            {
                int lc = lca(x,y);
                cout << max(queryup(x,lc),queryup(y,lc)) << '\n';
            }
        }
    }
}
