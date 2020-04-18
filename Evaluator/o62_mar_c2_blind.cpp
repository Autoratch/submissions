#include <bits/stdc++.h>
using namespace std;

const int N = 2e4 + 1;

int n,m;
int pa[N];
vector<int> adj[N];
vector<tuple<int,int,int,int> > qe;
int deg[N];
queue<int> q;
vector<int> idx[N];
vector<int> ans;

int root(int x){ if(pa[x]==x) return x; else return pa[x] = root(pa[x]); }

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> m;

    for(int i = 1;i <= n;i++) pa[i] = i;

    for(int i = 0;i < m;i++)
    {
        int t,a,b,c;
        cin >> t >> a >> b >> c;
        if(t==3)
        {
            if(root(a)!=root(b)) pa[root(a)] = root(b);
            if(root(a)!=root(c)) pa[root(a)] = root(c);
        }
        else qe.push_back({t,a,b,c});
    }

    for(int i = 1;i <= n;i++) idx[root(i)].push_back(i);

    for(auto x : qe)
    {
        int t,a,b,c; tie(t,a,b,c) = x;
        a = root(a),b = root(b),c = root(c);
        if(t==1) adj[b].push_back(a),adj[c].push_back(a),deg[a]+=2;
        else adj[a].push_back(b),adj[a].push_back(c),deg[b]++,deg[c]++;
    }

    for(int i = 1;i <= n;i++) if(root(i)==i)
    {
        if(deg[i]==0) q.push(i),deg[i] = -1;
    }

    while(!q.empty())
    {
        int p = q.front();
        q.pop();
        ans.push_back(p);
        for(int x : adj[p])
        {
            if(deg[x]==-1) continue;
            deg[x]--;
            if(deg[x]==0) q.push(x),deg[x]--;
        }
    }

    cout << ans.size() << '\n';
    for(int x : ans)
    {
        cout << idx[x].size() << ' ';
        sort(idx[x].begin(),idx[x].end());
        for(int y : idx[x]) cout << y << ' ';
        cout << '\n';
    }
}
