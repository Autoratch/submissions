#include "crocodile.h"
#include <bits/stdc++.h>
using namespace std;
#define pii pair<int,int> 

const int N = 1e5 + 1;

vector<pair<int,int> > adj[N];
vector<int> ep;
bool epp[N];
priority_queue<pii,vector<pii>,greater<pii> > q;
int dist[N],dis1[N],dis2[N];
bool visited[N];

int travel_plan(int n,int m,int r[][2],int l[],int k,int p[])
{
    for(int i = 0;i < m;i++)
    {
        int a = r[i][0],b = r[i][1],d = l[i];
        adj[a].push_back({d,b});
        adj[b].push_back({d,a});
    }
    for(int i = 0;i < k;i++) ep.push_back(p[i]);
    for(int i = 0;i < n;i++) dist[i] = dis1[i] = dis2[i] = INT_MAX;
    for(int x : ep) dist[x] = dis1[x] = dis2[x] = 0,q.push({0,x}),epp[x] = true;
    while(!q.empty())
    {
        int u = q.top().second;
        q.pop();
        if(visited[u]) continue;
        visited[u] = true;
        for(auto [d,v] : adj[u]) if(dist[u]+d<dist[v]) dist[v] = dist[u]+d,q.push({dist[v],v});
    }
    for(int i = 0;i < n;i++) visited[i] = false;
    for(int x : ep) q.push({0,x});
    while(!q.empty())
    {
        int u = q.top().second;
        q.pop();
        if(visited[u]) continue;
        visited[u] = true;
        if(dis2[u]==INT_MAX) continue;
        for(auto [d,v] : adj[u])
        {
            if(dis2[u]+d<dis1[v]) dis2[v] = dis1[v],dis1[v] = dis2[u]+d,q.push({dis2[v],v});
            else if(dis2[u]+d<dis2[v]) dis2[v] = dis2[u]+d,q.push({dis2[v],v});
        }
    }
    return dis2[0];
}

