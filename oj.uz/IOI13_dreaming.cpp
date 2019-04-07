#include <bits/stdc++.h>
#include "dreaming.h"
using namespace std;
 
vector<vector<pair<int,int> > > adj;
vector<bool> visited;
vector<int> cmp,s,e;
queue<pair<int,pair<int,int> > > q;
 
pair<int,int> solve(int x,int n)
{
    int sz = 0;
    q.push({0,{x,x}});
    int mx = 0,st = x,en = x;
    while(!q.empty())
    {
        int w = q.front().first,p = q.front().second.first,pr = q.front().second.second;
        q.pop();
        visited[p] = true;
        if(w>mx){ mx = w; st = p; }
        for(int i = 0;i < adj[p].size();i++) if(adj[p][i].second!=pr) q.push({adj[p][i].first+w,{adj[p][i].second,p}});
    }
    q.push({0,{st,st}});
    mx = 0;
    int rad = INT_MAX,dia;
    while(!q.empty())
    {
        int w = q.front().first,p = q.front().second.first,pr = q.front().second.second;
        q.pop();
        s[p] = w;
        if(w>mx){ mx = w; en = p; }
        for(int i = 0;i < adj[p].size();i++) if(adj[p][i].second!=pr) q.push({adj[p][i].first+w,{adj[p][i].second,p}});
    }
    q.push({0,{en,en}});
    while(!q.empty())
    {
        int w = q.front().first,p = q.front().second.first,pr = q.front().second.second;
        q.pop();
        e[p] = w;
        for(int i = 0;i < adj[p].size();i++) if(adj[p][i].second!=pr) q.push({adj[p][i].first+w,{adj[p][i].second,p}});
    }
    dia = mx;
    q.push({0,{st,st}});
    while(!q.empty())
    {
        int w = q.front().first,p = q.front().second.first,pr = q.front().second.second;
        q.pop();
        rad = min(rad,max(s[p],e[p]));
        for(int i = 0;i < adj[p].size();i++) if(adj[p][i].second!=pr) q.push({adj[p][i].first+w,{adj[p][i].second,p}});
    }
    return {rad,dia};
}
 
 
int travelTime(int n,int m,int l,int a[],int b[],int t[])
{
    s.resize(n);
    e.resize(n);
    adj.resize(n);
    visited.resize(n);
    for(int i = 0;i < m;i++)
    {
        adj[a[i]].push_back({t[i],b[i]});
        adj[b[i]].push_back({t[i],a[i]});
    }
    int ans = 0;
    for(int i = 0;i < n;i++)
    {
        if(visited[i]) continue;
        pair<int,int> tmp = solve(i,n);
        cmp.push_back(tmp.first);
        ans = max(ans,tmp.second);
    }
    sort(cmp.begin(),cmp.end());
    reverse(cmp.begin(),cmp.end());
    if(cmp.size()==1) ans = max(ans,cmp[0]);
    else if(cmp.size()==2) ans = max(ans,cmp[0]+cmp[1]+l);
    else ans = max(ans,max(cmp[0]+cmp[1]+l,cmp[1]+cmp[2]+l+l));
    return ans;
}
