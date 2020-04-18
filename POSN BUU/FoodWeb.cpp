#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 1;
const int M = 1 << 18;

int n,q,root;
set<int> eaten;
vector<int> adj[N],s;
int f[N],sz;

struct node
{
    int fi,val;
    friend node operator+(const node &a,const node &b)
    {
        if(a.fi<b.fi) return a;
        else return b;
    }
}tree[M << 1];

void dfs(int u)
{
    s.push_back(u);
    f[u] = s.size();
    for(int v : adj[u]) dfs(v),s.push_back(u);
}

void build(int l,int r,int idx)
{
    if(l==r){ tree[idx].val = s[l],tree[idx].fi = f[s[l]]; return; }
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

    for(int i = 1;i <= n;i++) eaten.insert(i);
    for(int i = 0;i < n-1;i++)
    {
        int a,b;
        cin >> a >> b;
        adj[a].push_back(b);
    }

    root = *eaten.begin();
    dfs(root);
    sz = s.size();

    build(0,sz-1,1);

    cin >> q;

    while(q--)
    {
        int l,r;
        cin >> l >> r;
        if(f[l]>f[r]) swap(l,r);
        int ans = read(0,sz-1,1,f[l]-1,f[r]-1).val;
        cout << ans << '\n';
    }
}
