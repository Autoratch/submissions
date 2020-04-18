#include <bits/stdc++.h>
using namespace std;

const int N = 20;
const int M = 1 << 16;

int k,l,q;
vector<int> res;    
vector<pair<int,int> > ed;
int dist[N][N],dst[M];
vector<int> s;
int f[M];
int disa[N],disb[N];

struct node
{
    int a;
    friend node operator+(const node &a,const node &b)
    {
        if(a.a<b.a) return a;
        else return b;
    }
}tree[M << 2];

void dfs(int u)
{
    s.push_back(u);
    for(int v = u*2;v <= u*2+1 and v<(1 << k);v++) dst[v] = dst[u]+1,dfs(v),s.push_back(u);
}

void build(int l,int r,int idx)
{
    if(l==r){ tree[idx].a = f[s[l]]; return; } 
    int m = (l+r)/2;
    build(l,m,idx*2),build(m+1,r,idx*2+1);
    tree[idx] = tree[idx*2]+tree[idx*2+1];
}

node read(int l,int r,int idx,int x,int y)
{
    if(x>r or y<l){ node ret; ret.a = INT_MAX; return ret; }
    if(x<=l and y>=r) return tree[idx];
    int m = (l+r)/2;
    return read(l,m,idx*2,x,y)+read(m+1,r,idx*2+1,x,y);
}

int dis(int a,int b)
{
    bool x = a<(1 << k),y = b<(1 << k);
    if(x!=y) return INT_MAX;
    if(!x) a-=(1 << k),b-=(1 << k);
    if(f[a]>f[b]) swap(a,b);
    int tmp = read(0,s.size()-1,1,f[a],f[b]).a;
    tmp = s[tmp];
    return dst[a]+dst[b]-dst[tmp]*2;
}

int main()
{
   ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> k >> l >> q;

    dfs(1);

    for(int i = 0;i < (1 << k);i++) f[i] = -1;
    for(int i = 0;i < s.size();i++) if(f[s[i]]==-1) f[s[i]] = i;

    build(0,s.size()-1,1);

    for(int i = 0;i < l;i++)
    {
        int a,b;
        cin >> a >> b;
        res.push_back(a),res.push_back(b);
        ed.push_back({res.size()-2,res.size()-1});
    }

    int n = res.size();

    for(int i = 0;i < n;i++) for(int j = 0;j < n;j++) dist[i][j] = dis(res[i],res[j]);

    for(int i = 0;i < ed.size();i++) dist[ed[i].first][ed[i].second] = dist[ed[i].second][ed[i].first] = 1;

    for(int k = 0;k < n;k++) for(int i = 0;i < n;i++) for(int j = 0;j < n;j++) if(dist[i][k]!=INT_MAX and dist[k][j]!=INT_MAX)
        dist[i][j] = min(dist[i][j],dist[i][k]+dist[k][j]);

    while(q--)
    {
        int a,b;
        cin >> a >> b;
        int ans = dis(a,b);
        for(int i = 0;i < n;i++) disa[i] = dis(res[i],a),disb[i] = dis(res[i],b);
        for(int i = 0;i < n;i++) for(int j = 0;j < n;j++) if(dist[i][j]!=INT_MAX and disa[i]!=INT_MAX and disb[j]!=INT_MAX)
            ans = min(ans,dist[i][j]+disa[i]+disb[j]);
        cout << ans << '\n';
    }
}
