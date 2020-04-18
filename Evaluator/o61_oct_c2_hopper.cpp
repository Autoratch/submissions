#include <bits/stdc++.h>
using namespace std;

const int N = 3e3 + 1;

int n,k;
int res[N],deg[N];
vector<pair<int,int> > adj[N];
queue<int> q;
vector<int> topo,cnt;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> k;

    for(int i = 1;i <= n;i++) cin >> res[i];

    for(int i = 1;i <= n;i++) for(int j = 1;j <= n;j++)
    {
        if(i==j) continue;
        if(res[i]>=res[j]) continue;
        adj[i].push_back({(j-i+n)%n,j});
        deg[j]++;
    }

    for(int i = 1;i <= n;i++) if(deg[i]==0) q.push(i),deg[i] = -1;

    while(!q.empty())
    {
        int p = q.front();
        q.pop();
        topo.push_back(p);
        for(int i = 0;i < adj[p].size();i++)
        {
            int v = adj[p][i].second;
            if(deg[v]==-1) continue;
            deg[v]--;
            if(deg[v]==0) q.push(v),deg[v] = -1;
        }
    }

    int l = 0,r = 1e6;

    while(l<r)
    {
        int m = (l+r)/2;
        cnt.assign(n+1,0);
        for(int x : topo)
        {
            for(int i = 0;i < adj[x].size();i++) if(adj[x][i].first<=m) cnt[adj[x][i].second] = max(cnt[adj[x][i].second],cnt[x]+1);
        }
        bool f = false;
        for(int i = 1;i <= n;i++) if(cnt[i]>=k) f = true;
        if(f) r = m;
        else l = m+1;
    }

    cout << l;
}
