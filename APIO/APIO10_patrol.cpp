#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 1;

int n,k,ans1,ans2;
vector<int> adj[N];
int a[N],b[N],d[N];
vector<pair<int,int> > sa,sd;

void dfs(int u,int p)
{
    for(int v : adj[u]) if(v!=p) dfs(v,u);
    sa.clear(),sd.clear();
    for(int v : adj[u]) if(v!=p)
    {
        d[u] = max(d[u],max(d[v],a[u]+a[v]+1));
        a[u] = max(a[u],a[v]+1);
        b[u] = max(b[u],b[v]+1);
        sa.push_back({a[v],v}),sd.push_back({d[v],v});
    }
    sort(sa.begin(),sa.end()),reverse(sa.begin(),sa.end());
    sort(sd.begin(),sd.end()),reverse(sd.begin(),sd.end());
    int cnt = 0,a3 = 0;
    for(auto [x,y] : sa){ a3+=x+1; if((++cnt)>=3) break; }
    b[u] = max(b[u],a3);
    for(int v : adj[u]) if(v!=p)
    {
        int aa = 0;
        for(auto [x,y] : sa) if(y!=v){ aa = x+1; break; }
        b[u] = max(b[u],d[v]+aa);
    }
    ans1 = max(d[u],ans1);
    ans2 = max(d[u],ans2);
    if(k==1) return;
    int tmp = 0,cn = 0;
    if(sa.size()>4) sa.erase(sa.begin()+4,sa.end());
    for(auto [x,y] : sa) tmp+=x+1;
    for(int v : adj[u]) if(v!=p)
    {
        int cnt = 0,aa = 0,dd = 0;
        for(auto [x,y] : sa) if(y!=v){ aa+=x+1; if((++cnt)>=2) break; }
        for(auto [x,y] : sd) if(y!=v){ dd = x; break; }
        tmp = max(tmp,d[v]+max(aa,dd));
    }
    for(int v : adj[u]) if(v!=p)
    {
        int aa = 0;
        for(auto [x,y] : sa) if(y!=v){ aa = x+1; break; }
        tmp = max(tmp,b[v]+aa+1);
    }
    ans2 = max(ans2,tmp);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> k;
    for(int i = 1;i < n;i++)
    {
        int a,b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(1,0);
    if(k==1) cout << 2*(n-1)-ans1+1;
    else cout << 2*(n-1)-max(ans1,ans2)+2;
}
