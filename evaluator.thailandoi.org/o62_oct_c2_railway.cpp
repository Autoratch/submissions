#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 1;

int n,m;
vector<pair<int,int> > adj[N];
vector<tuple<int,int,int> > nm;
int pa[N],lv[N],va[N];
vector<int> y;
vector<pair<int,int> > x;
int ans[N << 1];

void dfs(int u,int p,int l)
{
    pa[u] = p,lv[u] = l;
    for(auto [d,v] : adj[u]) if(v!=p) dfs(v,u,l+1); else va[u] = d;
}

int solve(int a,int b)
{
    int ret = 0;
    if(lv[a]<lv[b]) swap(a,b);
    while(lv[a]!=lv[b]) ret = max(ret,va[a]),a = pa[a];
    while(a!=b) ret = max(ret,max(va[a],va[b])),a = pa[a],b = pa[b];
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> m;
    for(int i = 1;i <= m;i++)
    {
        int a,b,d;
        cin >> a >> b >> d;
        if(i<=n-1) adj[a].push_back({d,b}),adj[b].push_back({d,a});
        else nm.push_back({a,b,d});
    }
    dfs(1,0,1);
    for(int i = 0;i < nm.size();i++)
    {
        auto [a,b,d] = nm[i];
        int res = solve(a,b);
        x.push_back({res,i});
        y.push_back(d);
    }
    sort(x.begin(),x.end());
    sort(y.begin(),y.end());
    for(int i = 0;i < nm.size();i++) if(x[i].first>=y[i]){ cout << "0"; return 0; }
    cout << "1\n";
    for(int i = 0;i < nm.size();i++) ans[x[i].second] = y[i];
    for(int i = 0;i < nm.size();i++) cout << ans[i] << '\n';
}
