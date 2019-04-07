#include <bits/stdc++.h>
using namespace std;
#define pii pair<double,pair<int,int> >

const int N = 1e3;

int n,m;
double cnt;
vector<pii> adj[N];
priority_queue<pii,vector<pii>,greater<pii> > q;
vector<int> ans;
bool visited[N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> m;

    for(int i = 0;i < m;i++)
    {
        int a,b;
        double d;
        cin >> a >> b >> d;
        adj[a].push_back({d,{b,i}});
        adj[b].push_back({d,{a,i}});
    }

    q.push({0.0,{0,-1}});

    while(!q.empty())
    {
        int p = q.top().second.first,id = q.top().second.second;
        double w = q.top().first;
        q.pop();
        if(visited[p]) continue;
        visited[p] = true;
        cnt+=w;
        if(id!=-1) ans.push_back(id);
        for(int i = 0;i < adj[p].size();i++) if(!visited[adj[p][i].second.first]) q.push(adj[p][i]);
    }

    cout << fixed;
    cout << cnt << '\n';

    sort(ans.begin(),ans.end());

    for(int i = 0;i < ans.size();i++) cout << ans[i] << '\n';
}
