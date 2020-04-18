#include <bits/stdc++.h>
using namespace std;

const int N = 28;

int m;
vector<int> dis[N][N];
vector<pair<int,int> > adj[N];
priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > q;
int dist[N];
bool visited[N];
stack<pair<int,pair<int,int> > > a,ans;

void solve(int x)
{
    if(visited[x]) return;
    visited[x] = true;
    if(x==26)
    {
        ans = a;
        return;
    }
    for(int i = 0;i < adj[x].size();i++) if(dist[adj[x][i].second]+adj[x][i].first==dist[x]) 
    {
        a.push({adj[x][i].first,{adj[x][i].second,x}});
        solve(adj[x][i].second);
    }
    a.pop();
}

char ch(int x)
{
    if(x==26) return 'X';
    else if(x==27) return 'Y';
    else return x+'a';
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> m;

    for(int i = 0;i < m;i++)
    {
        char a,b;
        int d;
        cin >> a >> b >> d;
        int x,y;
        if(a=='X') x = 26;
        else if(a=='Y') x = 27;
        else x = a-'a';
        if(b=='X') y = 26;
        else if(b=='Y') y = 27;
        else y = b-'a';
        dis[x][y].push_back(d);
        dis[y][x].push_back(d);
    }

    for(int i = 0;i < N;i++) for(int j = 0;j < N;j++)
    {
        int dist;
        if(dis[i][j].size()==0) continue;
        sort(dis[i][j].begin(),dis[i][j].end());
        if(dis[i][j].size()%2==1) dist = dis[i][j][dis[i][j].size()/2]*2;
        else dist = (dis[i][j][dis[i][j].size()/2]+dis[i][j][dis[i][j].size()/2-1]);
        adj[i].push_back({dist,j});
    }

    for(int i = 0;i < N;i++) dist[i] = INT_MAX;
    dist[26] = 0;
    q.push({0,26});

    while(!q.empty())
    {
        int p = q.top().second;
        q.pop();
        if(visited[p]) continue;
        visited[p] = true;
        for(int i = 0;i < adj[p].size();i++) if(dist[p]+adj[p][i].first<dist[adj[p][i].second])
        {
            dist[adj[p][i].second] = dist[p]+adj[p][i].first;
            q.push({dist[adj[p][i].second],adj[p][i].second});
        }
    }

    if(dist[27]==INT_MAX){ cout << "broken"; return 0; }

    for(int i = 0;i < N;i++) visited[i] = false;

    solve(27);

    while(!ans.empty())
    {
        auto a = ans.top();
        ans.pop();
        cout << ch(a.second.first) << ' ' << ch(a.second.second) << ' ';
        double tmp = a.first/2.0;
        cout << fixed;
        cout << setprecision(1) << tmp << '\n';
    }

    double tmp = dist[27]/2.0;
    cout << fixed;
    cout << setprecision(1) << tmp << '\n';
}
