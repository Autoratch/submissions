#include <bits/stdc++.h>
using namespace std;

const int N = 801;

int n,s,sx,sy,tx,ty;
char c[N][N];
int bee[N][N];
bool visited[N][N];
queue<pair<pair<int,int>,int> > qb,q;

void flybee()
{
    while(!qb.empty())
    {
        int t = qb.front().second,x = qb.front().first.first,y = qb.front().first.second;
        qb.pop();
        for(int i = -1;i <= 1;i++) for(int j = -1;j <= 1;j++)
        {
            if(i!=0 and j!=0) continue;
            if(i==0 and j==0) continue;
            int ai = x+i,aj = y+j;
            if(ai<1 or ai>n or aj<1 or aj>n) continue;
            if(c[ai][aj]=='D' or c[ai][aj]=='T') continue;
            if(visited[ai][aj]) continue;
            visited[ai][aj] = true;
            bee[ai][aj] = t+1;
            qb.push({{ai,aj},t+1});
        }
    }
}

bool solve(int m)
{
    if(m>=bee[sx][sy]) return false;
    for(int i = 1;i <= n;i++) for(int j = 1;j <= n;j++) visited[i][j] = false;
    while(!q.empty()) q.pop();
    q.push({{sx,sy},0});
    visited[sx][sy] = true;
    while(!q.empty())
    {
        int x = q.front().first.first,y = q.front().first.second,tm = q.front().second;
        q.pop();
        if(x==tx and y==ty) return true;
        for(int i = -1;i <= 1;i++) for(int j = -1;j <= 1;j++)
        {
            if(i!=0 and j!=0) continue;
            if(i==0 and j==0) continue;
            int ai = x+i,aj = y+j;
            if(ai<1 or ai>n or aj<1 or aj>n) continue;
            if(c[ai][aj]=='T') continue;
            if(visited[ai][aj]) continue;
            if(1LL*tm+1>=1LL*(bee[ai][aj]-m)*s) continue;
            q.push({{ai,aj},tm+1});
            visited[ai][aj] = true;
        }
    }
    return false;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> s;
    for(int i = 1;i <= n;i++) for(int j = 1;j <= n;j++) cin >> c[i][j],bee[i][j] = INT_MAX;
    for(int i = 1;i <= n;i++) for(int j = 1;j <= n;j++) 
        if(c[i][j]=='H') qb.push({{i,j},0}),bee[i][j] = 0,visited[i][j] = true; 
        else if(c[i][j]=='M') sx = i,sy = j;
        else if(c[i][j]=='D') tx = i,ty = j;
    flybee();
    int l = 0,r = n*n;
    while(l<r)
    {
        int m = (l+r+1)/2;
        if(solve(m)) l = m;
        else r = m-1;
    }
    if(solve(l)) cout << l;
    else cout << "-1";
}
