#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 1;

int n;
int deg[N];
vector<pair<int,int> > adj[N];
int ans[N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n;
    for(int i = 0;i < n-1;i++)
    {
        int a,b;
        cin >> a >> b;
        adj[a].push_back({b,i});
        adj[b].push_back({a,i});
        deg[a]++,deg[b]++;
    }
    for(int i = 1;i <= n;i++)
    {
        if(deg[i]>=3)
        {
            for(int j = 0;j < 3;j++) ans[adj[i][j].second] = j+1;
            int cur = 3;
            for(int j = 1;j <= n;j++) for(int k = 0;k < adj[j].size();k++) if(ans[adj[j][k].second]==0) ans[adj[j][k].second] = ++cur;
            for(int j = 0;j < n-1;j++) cout << ans[j]-1 << '\n';
            return 0;
        }
    }
    for(int i = 0;i < n-1;i++) cout << i << '\n';
}
