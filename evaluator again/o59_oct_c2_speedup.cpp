#include <bits/stdc++.h>
using namespace std;
#define pii pair<pair<int,int>,pair<int,int> > 

const int N = 8e4 + 1;
const int K = 9;

int n,m,l,k,ans = INT_MAX;
bool sp[N];
vector<pair<int,int> > adj[N];
int dist[N][K];
bool visited[N][K];
priority_queue<pii,vector<pii>,greater<pii> > q;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> m >> l >> k;
    
    for(int i = 0;i < m;i++)
    {
        int a,b,d;
        cin >> a >> b >> d;
        adj[a].push_back({d,b});
    }

    for(int i = 0;i < l;i++)
    {
        int x;
        cin >> x;
        sp[x] = true;
    }

    for(int i = 1;i <= n;i++) for(int j = 0;j <= k;j++) dist[i][j] = INT_MAX;
    dist[1][0] = 0;

    q.push({{0,0},{1,0}});

    while(!q.empty())
    {
        int p = q.top().second.first,lv = q.top().second.second,lst = q.top().first.second;
        q.pop();
        if(visited[p][lv]) continue;
        visited[p][lv] = true;
        if(p==n) ans = min(ans,dist[p][lv]);
        for(int i = 0;i < adj[p].size();i++)
        {
            int w = adj[p][i].first,v = adj[p][i].second;
            if(lv==k or !sp[p] or lst==p)
            {
                if(dist[p][lv]+w/(1 << lv)<dist[v][lv]) 
                {
                    dist[v][lv] = dist[p][lv]+w/(1 << lv);
                    q.push({{dist[v][lv],lst},{v,lv}});
                }
            }
            else
            {
                if(dist[p][lv]+w/(1 << (lv+1))<dist[v][lv+1])
                {
                    dist[v][lv+1] = dist[p][lv]+w/(1 << (lv+1));
                    q.push({{dist[v][lv+1],p},{v,lv+1}});
                }
            }    
        }
    }

    cout << ans;
}

