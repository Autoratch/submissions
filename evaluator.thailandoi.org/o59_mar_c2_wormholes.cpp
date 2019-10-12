#include <bits/stdc++.h>
using namespace std;

const int N = 61;

int k,m,n,idx;
vector<pair<int,int> > va;
int dist[N][N];

int solve(pair<int,int> a,pair<int,int> b){ return abs(a.first-b.first)+abs(a.second-b.second); }

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    cin >> k >> m;

    for(int i = 0;i < N;i++) for(int j = 0;j < N;j++) dist[i][j] = INT_MAX;

    for(int i = 0;i < k;i++)
    {
        pair<int,int> a,b;
        cin >> a.first >> a.second >> b.first >> b.second;
        int xa,xb;
        xa = i*2,xb = i*2+1;
        va.push_back(a),va.push_back(b);
        dist[xa][xb] = dist[xb][xa] = 0;
    }

    n = k*2;

    for(int i = 0;i < n;i++) for(int j = 0;j < n;j++) if(dist[i][j]==INT_MAX) dist[i][j] = solve(va[i],va[j]);

    for(int k = 0;k < n;k++) for(int i = 0;i < n;i++) for(int j = 0;j < n;j++) 
        if(dist[i][k]!=INT_MAX and dist[k][j]!=INT_MAX) dist[i][j] = min(dist[i][j],dist[i][k]+dist[k][j]);

    while(m--)
    {
        pair<int,int> a,b;
        cin >> a.first >> a.second >> b.first >> b.second;
        int ans = solve(a,b);
        for(int i = 0;i < n;i++) for(int j = 0;j < n;j++) if(dist[i][j]!=INT_MAX) ans = min(ans,dist[i][j]+solve(va[i],a)+solve(va[j],b));
        cout << ans << '\n';
    }
}
