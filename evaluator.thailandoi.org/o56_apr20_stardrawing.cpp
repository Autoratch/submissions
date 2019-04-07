#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

const int N = 1e5;

int n,m;
vector<int> adj[N];
vector<pair<int,int> > res[N];
int cnt;
bool visited[N],visit,fin;
int deg[N];
int root[N];
queue<int> q;
queue<pair<int,int> > pq;
bool s1,s2;
int cy;
set<int> s2c,s2n;
set<pair<int,int> > s3c;
set<pair<int,pair<int,int> > > s3n;

void solve(int x)
{
    visited[x] = true;
    q.push(x);
    int mx = 0;
    while(!q.empty())
    {
        int p = q.front();
        q.pop();
        if(deg[p]>mx){ mx = deg[p]; root[cnt] = p; }
        res[cnt].push_back({deg[p],p});
        for(int i = 0;i < adj[p].size();i++)
        {
            if(visited[adj[p][i]]) continue;
            visited[adj[p][i]] = true;
            q.push(adj[p][i]);
        }
    }
    cnt++;
}

int ltor(int x,int r)
{
    while(!pq.empty()) pq.pop();
    pq.push({x,x});
    int cnt = 0;
    while(!pq.empty())
    {
        int p = pq.front().first,pr = pq.front().second;
        pq.pop();
        cnt++;
        if(p==r) return cnt;
        for(int i = 0;i < adj[p].size();i++) if(adj[p][i]!=pr) pq.push({adj[p][i],p});
    }
}

bool dfs(int x,int p,int r)
{
    if(fin) return false;
    if(x==r)
    {
        if(visit) return true;
        visit = true;
    }
    for(int i = 0;i < adj[x].size();i++)
    {
        if(adj[x][i]==p) continue;
        if(dfs(adj[x][i],x,r))
        {
            if(x==r){ fin = true; return false; }
            cy++; return true;
        }
        else if(fin) return false;
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> m;

    for(int i = 0;i < m;i++)
    {
        int a,b;
        cin >> a >> b;
        a--; b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
        deg[a]++;
        deg[b]++;
    }

    for(int i = 0;i < n;i++) if(!visited[i]) solve(i);

    for(int i = 0;i < cnt;i++) sort(res[i].begin(),res[i].end());

    for(int i = 0;i < cnt;i++)
    {
        if(res[i].size()==1) s1 = true;
        else if(res[i].size()==2) s2 = true;
        else if(res[i][res[i].size()-1].first==2)
        {
            if(res[i][0].first==1)
            {
                s2n.insert(res[i].size());
            }
            else
            {
                s2c.insert(res[i].size());
            }
        }
        else
        {
            if(res[i][1].first==1)
            {
                int t[3];
                for(int j = 0;j < 3;j++) t[j] = ltor(res[i][j].second,res[i][res[i].size()-1].second);
                sort(t,t+3);
                s3n.insert({t[0],{t[1],t[2]}});
            }
            else
            {
                int t = ltor(res[i][0].second,res[i][res[i].size()-1].second);
                cy = 0;
                visit = false; fin = false;
                dfs(res[i][res[i].size()-1].second,res[i][res[i].size()-1].second,res[i][res[i].size()-1].second);
                s3c.insert({t,cy});
            }
        }
    }

    cout << s1+s2+s2c.size()+s2n.size()+s3c.size()+s3n.size();
}
