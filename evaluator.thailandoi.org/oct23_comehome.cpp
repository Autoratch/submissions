#include <bits/stdc++.h>
using namespace std;
#define pii pair<int,int>

const int N = 52;

int n,ans,mn = INT_MAX;
vector<pair<int,int> > adj[N];
int dist[N];
bool visited[N];
priority_queue<pii,vector<pii>,greater<pii> > q;

int ctoi(char c)
{
    if(c<='Z') return (int)(c-'A');
    else return (int)(c-'a')+26;
}

char itoc(int i)
{
    if(i<26) return (char)(i+'A');
    else return (char)(i-26+'a');
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n;

    for(int i = 0;i < n;i++)
    {
        char a,b;
        int d;
        cin >> a >> b >> d;
        adj[ctoi(a)].push_back({d,ctoi(b)});
        adj[ctoi(b)].push_back({d,ctoi(a)});
    }

    for(int i = 0;i < 52;i++) dist[i] = INT_MAX;

    dist[ctoi('Z')] = 0;
    q.push({0,ctoi('Z')});

    while(!q.empty())
    {
        int p = q.top().second;
        q.pop();
        if(visited[p]) continue;
        visited[p] = true;
        for(int i = 0;i < adj[p].size();i++)
        {
            if(dist[p]+adj[p][i].first<dist[adj[p][i].second])
            {
                dist[adj[p][i].second] = dist[p]+adj[p][i].first;
                q.push({dist[adj[p][i].second],adj[p][i].second});
            }
        }
    }

    for(int i = 0;i < 25;i++)
    {
        if(mn>dist[i]){ mn = dist[i]; ans = i; }
    }

    cout << itoc(ans) << ' ' << mn;
}
