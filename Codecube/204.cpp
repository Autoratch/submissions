#include <bits/stdc++.h>
using namespace std;
#define ti tuple<long long,int,int>

const int N = 5e4 + 5;

int n,m;
string s,res;
vector<pair<long long,int> > adj[N];
long long dist[N][1 << 4];
bool visited[N][1 << 4];
priority_queue<ti,vector<ti>,greater<ti> > q;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> m >> s >> res;
    res = "**"+res;
    for(int i = 0;i < m;i++)
    {
        int a,b,d;
        cin >> a >> b >> d;
        adj[a].push_back({d,b});
        adj[b].push_back({d,a});
    }
    for(int i = 1;i <= n;i++) for(int j = 0;j < 16;j++) dist[i][j] = LLONG_MAX;
    int st = 0;
    string t = "XMAS";
    for(int i = 0;i < 4;i++) if(s[i]!='_' or res[n]==t[i]) st+=(1 << i);
    s = "XMAS";
    dist[n][st] = 0;
    q.push({0,n,st});
    while(!q.empty())
    {
        auto [wi,u,lv] = q.top();
        q.pop();
        if(visited[u][lv]) continue;
        visited[u][lv] = true;
        for(auto [w,v] : adj[u])
        {
            int nlv = lv;
            for(int i = 0;i < 4;i++) if(res[v]==s[i]) nlv|=(1 << i);
            if(dist[u][lv]+w<dist[v][nlv])
            {
                dist[v][nlv] = dist[u][lv]+w;
                q.push({dist[v][nlv],v,nlv});
            }        
        }
    }
    cout << dist[1][15];
}
