#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 1;

int n,m,t;
vector<pair<long long,pair<int,int> > > adj[N];
priority_queue<pair<long long,pair<int,int> > > q;
vector<int> ans;
vector<long long> ed;
bool er[N];
long long mx;
bool visited[N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> m;

    ed.push_back(0);
    for(int i = 1;i <= m;i++)
    {
        int a,b,d;
        cin >> a >> b >> d;
        adj[a].push_back({d,{b,i}});
        adj[b].push_back({d,{a,i}});
        ed.push_back(d);
    }

    cin >> t;

    q.push({0,{1,0}});

    while(!q.empty())
    {
        long long w = q.top().first;
        int p = q.top().second.first,lv = q.top().second.second;
        q.pop();
        if(visited[p]) continue;
        visited[p] = true;
        if(lv) ans.push_back(lv),er[lv] = true,mx+=w;
        for(int i = 0;i < adj[p].size();i++) q.push(adj[p][i]);
    }

    if(ans.size()<n-1 or m<n){ cout << "-1"; return 0; }

    long long tmp = 0,id;

    for(int i = 1;i <= m;i++) if(!er[i]) if(ed[i]>tmp) tmp = ed[i],id = i;

    ans.push_back(id);
    mx+=tmp;

    cout << mx;

    if(t==1) return 0;

    cout << '\n';
    for(int x : ans) cout << x << ' ';
}
