#include <bits/stdc++.h>
using namespace std;

const int N = 1 << 18;

int n,dp[N][4],s[N << 1],ans,m;
vector<int> adj[N],cy;
bool visited[N],incy[N];
struct node
{
    int pre,suf,mxa,sum;  
    friend node operator+(const node &a,const node &b)
    {
        node ret;
        ret.pre = max(a.pre,a.sum+b.pre);
        ret.suf = max(b.suf,a.suf+b.sum);
        ret.mxa = max(max(a.mxa,b.mxa),a.suf+b.pre);
        ret.sum = a.sum+b.sum;
        return ret;
    }
}tree[N << 1];

int findcy(int u,int p)
{
    if(visited[u]){ incy[u] = true; cy.push_back(u); return u; }
    visited[u] = true;
    for(int v : adj[u]) if(v!=p)
    {
        int ret = findcy(v,u);
        if(ret>=0 and ret!=u){ incy[u] = true; cy.push_back(u); return ret; }
        else if(ret>=0) return -1;
    }
    return -1;
}

void dfs(int u,int p)
{
    if(visited[u]) return;
    visited[u] = true;
    vector<int> res;
    for(int v : adj[u]) if(v!=p and !incy[v])
    {
        dfs(v,u);
        res.push_back(max(dp[v][0],max(dp[v][1],dp[v][2])));
    }
    sort(res.begin(),res.end());
    if(!res.empty()) dp[u][1] = dp[u][0]+res.back(),res.pop_back();
    if(!res.empty()) dp[u][2] = dp[u][1]+res.back(),res.pop_back();
    if(!res.empty()) dp[u][3] = dp[u][2]+res.back();
    for(int i = 1;i < 4;i++) dp[u][i] = max(dp[u][i],dp[u][i-1]),ans = max(ans,dp[u][i]);
}

void build(int l,int r,int idx)
{
    if(l==r)
    {
        tree[idx] = {dp[s[l]][2],dp[s[l]][2],dp[s[l]][2],dp[s[l]][1]};
        return;
    }
    int m = (l+r)/2;
    build(l,m,idx*2),build(m+1,r,idx*2+1);
    tree[idx] = tree[idx*2]+tree[idx*2+1];
}

node read(int l,int r,int idx,int x,int y)
{
    if(x>r or y<l) return {INT_MIN,INT_MIN,INT_MIN,0};
    if(x<=l and y>=r) return tree[idx];
    int m = (l+r)/2;
    return read(l,m,idx*2,x,y)+read(m+1,r,idx*2+1,x,y);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n;
    for(int i = 0;i < n;i++) cin >> dp[i][0];
    for(int i = 0;i < n;i++) 
    {
        int a,b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    findcy(0,0);
    for(int i = 0;i < n;i++) visited[i] = false;
    for(int x : cy) dfs(x,x);
    for(int i = 0;i < n;i++) for(int j = 1;j < 4;j++) dp[i][j] = max(dp[i][j],dp[i][j-1]),ans = max(ans,dp[i][j]);
    int id = 0;
    for(int x : cy) s[++id] = x;
    m = id;
    for(int i = 1;i <= m;i++) s[i+m] = s[i];
    build(1,m*2,1);
    for(int i = 1;i <= m;i++) ans = max(ans,read(1,m*2,1,i,i+m-1).mxa);
    ans = max(ans,read(1,m*2,1,1,m).sum);
    cout << ans;
}
