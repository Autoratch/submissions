#include <bits/stdc++.h>
using namespace std;

struct node
{
    int sz,val,prio;
    node *l,*r;
};

using pnode = node*;

int sz(pnode t){ if(t) return t->sz; return 0; }

void upd(pnode t){ if(t) t->sz = sz(t->l)+sz(t->r)+1; }

void split(pnode t,pnode &l,pnode &r,int key)
{
    if(!t) return void(l = r = NULL);
    if(key>=t->val) split(t->r,t->r,r,key),l = t;
    else split(t->l,l,t->l,key),r = t;
    upd(t);
}

void merge(pnode &t,pnode l,pnode r)
{
    if(!l) return void(t = r);
    if(!r) return void(t = l);
    if(l->prio>r->prio) merge(l->r,l->r,r),t = l;
    else merge(r->l,l,r->l),t = r;
    upd(t);
}

void insert(pnode &t,pnode it)
{
    if(!t) return void(t = it);
    if(it->prio>t->prio) split(t,it->l,it->r,it->val),t = it;
    else if(it->val>t->val) insert(t->r,it);
    else insert(t->l,it);
    upd(t);
}

pnode init(int val)
{
    pnode res = new node;
    *res = {1,val,rand(),NULL,NULL};
    return res;
}

int count(pnode t,int x)
{
    if(!t) return 0;
    if(x>t->val) return count(t->r,x);
    else return count(t->l,x)+1+sz(t->r);
}

void print(pnode t)
{
    if(!t) return;
    cout << "x " << t->val << '\n';
    print(t->l),print(t->r);
}

const int N = 1e5 + 1;
const int K = 18;

pnode treap[N],same[N];

int n,q;
vector<int> adj[N];
int pa[N],res[N];
bool blocked[N];
int lv[N],dp[K][N];

void getsz(int u,int p){ res[u] = 1; for(int v : adj[u]) if(v!=p and !blocked[v]) getsz(v,u),res[u]+=res[v]; }

void build(int u,int c)
{
    getsz(u,c);
    int cen = u,prev = c;
    while(true)
    {
        int mx = -1,id;
        for(int v : adj[cen]) if(!blocked[v] and v!=prev) if(res[v]>mx) mx = res[v],id = v;
        if(mx*2>res[u]) prev = cen,cen = id;
        else break;
    }
    pa[cen] = c,blocked[cen] = true;
    for(int v : adj[cen]) if(!blocked[v]) build(v,cen);
}

void dfs(int u,int p){ lv[u] = lv[p]+1,dp[0][u] = p; for(int v : adj[u]) if(v!=p) dfs(v,u); }

int lca(int a,int b)
{
    if(lv[a]<lv[b]) swap(a,b);
    for(int i = K-1;i >= 0;i--) if(lv[dp[i][a]]>=lv[b]) a = dp[i][a];
    if(a==b) return a;
    for(int i = K-1;i >= 0;i--) if(dp[i][a]!=dp[i][b]) a = dp[i][a],b = dp[i][b];
    return dp[0][a];
}

int dist(int a,int b){ int l = lca(a,b); return lv[a]-lv[l]+lv[b]-lv[l]; }

void update(int x,int k)
{
    int prev = 0;
    for(int i = x;i;i = pa[i])
    {
        if(k>=dist(i,x)) 
        {
            insert(treap[i],init(k-dist(i,x)));
            if(prev) insert(same[prev],init(k-dist(i,x)));
        }
        prev = i;
    }
}

int read(int x)
{
    int prev = 0,ans = 0;
    for(int i = x;i;i = pa[i])
    {
        ans+=count(treap[i],dist(i,x));
        if(prev) ans-=count(same[prev],dist(i,x));
        prev = i;
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    srand(time(NULL));
   
    cin >> n >> q;
    for(int i = 1;i <= n-1;i++)
    {
        int a,b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(1,0);
    for(int i = 1;i < K;i++) for(int j = 1;j <= n;j++) dp[i][j] = dp[i-1][dp[i-1][j]];
    build(1,0);
    while(q--)
    {
        int t,x,y;
        cin >> t;
        if(t==1) cin >> x >> y,update(x,y);
        else cin >> x,cout << read(x) << '\n';
    }
}
