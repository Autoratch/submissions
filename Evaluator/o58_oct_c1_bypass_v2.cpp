#include <bits/stdc++.h>
using namespace std;

const long long N = 1e5 + 1;

long long n;
vector<long long> adj[N];
long long sum[N],pa[N],mxc[N];
long long ans;

void dfs(long long u,long long p){ pa[u] = p; sum[u] = 1; for(long long v : adj[u]) if(v!=p) dfs(v,u),sum[u]+=sum[v],mxc[u] = max(mxc[u],sum[v]); }

void sol(long long u,long long p,long long lv)
{
    if(lv>=3)
    {
        long long x = pa[pa[u]];
        long long a = n-sum[x];
        long long b = sum[u];
        ans = max(ans,a*b);
    }
    long long mxa = 0,mxb = 0,ca = 0,cb = 0,mxx = 0,mxy = 0,ida,idb;
    for(long long v : adj[u]) if(v!=p)
    {
        if(sum[v]>mxa) mxx = mxa,mxa = sum[v],ca = 1,ida = v;
        else if(sum[v]==mxa) ca++;
        else mxx = max(mxx,sum[v]);
        if(mxc[v]>mxb) mxy = mxb,mxb = mxc[v],cb = 1,idb = v;
        else if(mxc[v]==mxb) cb++;
        else mxy = max(mxy,mxc[v]);
    }
    if(ida==idb and ca==1 and cb==1)
    {
        if(mxx*mxb>mxa*mxy) mxa = mxx;
        else mxb = mxy;
    }
    ans = max(ans,mxa*mxb);
    for(long long v : adj[u]) if(v!=p) sol(v,u,lv+1);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n;

    for(long long i = 0;i < n-1;i++)
    {
        long long a,b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs(1,0);

    sol(1,0,0);

    cout << ans;
}
