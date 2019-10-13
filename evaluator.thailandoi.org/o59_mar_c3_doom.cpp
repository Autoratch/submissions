#include <bits/stdc++.h>
using namespace std;
#define pi pair<pair<int,int>,int> 

const int M = 102;
const int N = 32;
const int K = 15;

int r,c,k,n;
char s[M][M];
vector<pair<int,int> > adj[N];
pair<int,int> lc[N];
queue<pair<int,pair<int,int> > > q;
bool visit[M][M];
bool visited[N][1 << K];
int dist[N][1 << K];
priority_queue<pi,vector<pi>,greater<pi> > pq;
int ans = INT_MAX;

int hsh(char c)
{
    if(c>'Z' and c<'z') return c-'a';
    else if(c=='z') return k;
    else if(c<'Z') return c-'A'+k+1;
    else return k*2+1;
}

char val(int x)
{
    if(x==k) return 'z';
    else if(x==k*2+1) return 'Z';
    else if(x<k) return x+'a';
    else return x-1-k+'A';
}

int run(pair<int,int> x,pair<int,int> y)
{
    while(!q.empty()) q.pop();
    q.push({0,x});
    for(int i = 0;i < r;i++) for(int j = 0;j < c;j++) visit[i][j] = false;
    visit[x.first][x.second] = true;
    while(!q.empty()) 
    {
        int w = q.front().first,a = q.front().second.first,b = q.front().second.second;
        q.pop();
        if(make_pair(a,b)==y) return w;
        for(int i = -1;i <= 1;i++) for(int j = -1;j <= 1;j++)
        {
            if(i==0 and j==0) continue;
            if(i!=0 and j!=0) continue;
            int ai = a+i,aj = b+j;
            if(ai<0 or ai>=r or aj<0 or aj>=c) continue;
            if(visit[ai][aj]) continue;
            if(s[ai][aj]=='#') continue;
            if(s[ai][aj]>='A' and s[ai][aj]<'Z' and make_pair(ai,aj)!=y) continue;
            visit[ai][aj] = true;
            q.push({w+1,{ai,aj}});
        }
    }
    return INT_MAX;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> r >> c >> k;
    k = K;
    n = (k+1)*2;
    for(int i = 0;i < r;i++) cin >> s[i];
    for(int i = 0;i < r;i++) for(int j = 0;j < c;j++)
        if(s[i][j]!='.' and s[i][j]!='#') lc[hsh(s[i][j])] = {i,j};
    for(int i = 0;i < n;i++) for(int j = 0;j < n;j++){ int dis = run(lc[i],lc[j]); if(dis!=INT_MAX) adj[i].push_back({dis,j}); }
    for(int i = 0;i < n;i++) for(int j = 0;j < (1 << k);j++) dist[i][j] = INT_MAX;
    pq.push({{0,0},hsh('z')});
    dist[hsh('z')][0] = 0;
    while(!pq.empty())
    {
        int lv = pq.top().first.second,p = pq.top().second;
        pq.pop();
        if(visited[p][lv]) continue;
        visited[p][lv] = true;
        if(val(p)=='Z'){ ans = min(ans,dist[p][lv]); continue; }
        for(int i = 0;i < adj[p].size();i++)
        {
            int w = adj[p][i].first,v = adj[p][i].second;
            if(val(v)<'Z' and !(lv & (1 << (val(v)-'A')))) continue;
            int nlv = lv;
            if(val(v)>='a' and val(v)<'z') nlv|=(1 << (val(v)-'a'));
            if(dist[p][lv]+w<dist[v][nlv])
            {
                dist[v][nlv] = dist[p][lv]+w;
                pq.push({{dist[v][nlv],nlv},v});
            }
        }
    }
    if(ans==INT_MAX) ans = -1;
    cout << ans;
}
