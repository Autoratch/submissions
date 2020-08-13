#include <bits/stdc++.h>
using namespace std;
#define pii pair<long long,int> 

const int N = 1e5 + 1;
const int K = 6;

int n,m,k;
vector<pair<int,int> > adj[N];
vector<int> imp;
int idx[N];
bool visited[N],used[K][K],usedd[K][K][K];
long long dist[K][N],dis1[N],dist1[K][K][N],dis2[N],ans = LLONG_MAX;
priority_queue<pii,vector<pii>,greater<pii> > q;

void dijk(int x,long long (&dist)[N])
{
    for(int i = 1;i <= n;i++) visited[i] = false,dist[i] = LLONG_MAX;
    dist[x] = 0;
    q.push({0,x});
    while(!q.empty())
    {
        int u = q.top().second;
        q.pop();
        if(visited[u]) continue;
        visited[u] = true;
        for(auto [w,v] : adj[u]) if(dist[u]+w<dist[v]) dist[v] = dist[u]+w,q.push({dist[v],v});
    }
}

long long cal(int a,int b)
{
    if(idx[a]) return dist[idx[a]][b];
    else return dist[idx[b]][a];
}

void solve2(){ ans = min(ans,cal(imp[0],imp[1])); }

void solve3()
{
    for(int i = 1;i <= n;i++) 
    {
        long long each = 0;
        for(int x : imp) each+=cal(i,x);
        ans = min(ans,each);
    }
}

void dijktwo()
{
    for(int i = 1;i <= n;i++) q.push({dis1[i],i}),visited[i] = false;
    while(!q.empty())
    {
        int u = q.top().second;
        q.pop();
        if(visited[u]) continue;
        visited[u] = true;
        for(auto [w,v] : adj[u]) if(dis1[u]+w<dis1[v]) dis1[v] = dis1[u]+w,q.push({dis1[v],v});
    }
}

void solve4()
{
    long long each = 0;
    for(int i = 0;i < k-1;i++) each+=cal(imp[i],imp[i+1]);
    ans = min(ans,each);
    for(int i = 1;i <= n;i++) ans = min(ans,cal(imp[0],imp[1])+cal(imp[1],i)+cal(imp[2],i)+cal(imp[3],i));
    for(int i = 1;i <= n;i++) dis1[i] = cal(imp[0],i)+cal(imp[1],i),dis2[i] = cal(imp[2],i)+cal(imp[3],i);
    dijktwo();
    for(int i = 1;i <= n;i++) ans = min(ans,dis1[i]+dis2[i]);
}

void solve5s()
{
    for(int i = 1;i <= n;i++) dis1[i] = cal(imp[0],i)+cal(imp[1],i);
    dijktwo();
    for(int i = 1;i <= n;i++) dist1[idx[imp[0]]][idx[imp[1]]][i] = dist1[idx[imp[1]]][idx[imp[0]]][i] = dis1[i];
}

void solve5t()
{
    if(usedd[idx[imp[0]]][idx[imp[1]]][idx[imp[2]]] or usedd[idx[imp[0]]][idx[imp[2]]][idx[imp[1]]]) return;
    usedd[idx[imp[0]]][idx[imp[1]]][idx[imp[2]]] = usedd[idx[imp[0]]][idx[imp[2]]][idx[imp[1]]] = true;
    for(int i = 1;i <= n;i++) ans = min(ans,cal(i,imp[0])+dist1[idx[imp[1]]][idx[imp[2]]][i]+dist1[idx[imp[3]]][idx[imp[4]]][i]);
}

void solve5()
{
    ans = min(ans,cal(imp[0],imp[1])+cal(imp[1],imp[2])+cal(imp[2],imp[3])+cal(imp[3],imp[4]));
    ans = min(ans,cal(imp[0],imp[1])+cal(imp[0],imp[2])+cal(imp[0],imp[3])+cal(imp[3],imp[4]));
    for(int i = 1;i <= n;i++)
    {
        ans = min(ans,cal(imp[0],i)+cal(imp[1],i)+cal(imp[2],i)+cal(imp[3],i)+cal(imp[4],i));

        ans = min(ans,cal(imp[0],i)+cal(imp[1],i)+cal(imp[2],i)+cal(imp[3],i)+cal(imp[3],imp[4]));
        
        ans = min(ans,cal(imp[0],i)+cal(imp[1],i)+cal(imp[2],i)+cal(imp[3],imp[2])+cal(imp[4],imp[1]));
        ans = min(ans,cal(imp[0],i)+cal(imp[1],i)+cal(imp[2],i)+cal(imp[3],imp[2])+cal(imp[4],imp[2]));
        ans = min(ans,cal(imp[0],i)+cal(imp[1],i)+cal(imp[2],i)+cal(imp[3],imp[2])+cal(imp[4],imp[3]));
        
        ans = min(ans,cal(imp[0],imp[1])+cal(imp[1],i)+cal(i,imp[2])+cal(imp[2],imp[3])+cal(imp[4],imp[2]));
        ans = min(ans,cal(imp[0],imp[1])+cal(imp[1],i)+cal(i,imp[2])+cal(imp[2],imp[3])+cal(imp[4],imp[3]));
    }
    if(!used[idx[imp[1]]][idx[imp[0]]] and !used[idx[imp[0]]][idx[imp[1]]]) used[idx[imp[0]]][idx[imp[1]]] = true,solve5s();
    for(int i = 1;i <= n;i++) dis2[i] = cal(imp[2],i)+cal(imp[3],i)+cal(imp[4],i);
    for(int i = 1;i <= n;i++) ans = min(ans,dist1[idx[imp[0]]][idx[imp[1]]][i]+dis2[i]);
    for(int i = 1;i <= n;i++) dis2[i] = cal(imp[2],imp[3])+cal(imp[3],i)+cal(imp[4],i);
    for(int i = 1;i <= n;i++) ans = min(ans,dist1[idx[imp[0]]][idx[imp[1]]][i]+dis2[i]);
}
 
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> k >> m;
    for(int i = 1;i <= k;i++)
    {
        int x;
        cin >> x;
        imp.push_back(x);
        idx[x] = i;
    }
    for(int i = 0;i < m;i++)
    {
        int a,b,d;
        cin >> a >> b >> d;
        adj[a].push_back({d,b});
        adj[b].push_back({d,a});
    }   
    for(int x : imp) dijk(x,dist[idx[x]]);
    sort(imp.begin(),imp.end());
    do
    {
        if(k==2) solve2();
        else if(k==3) solve3();
        else if(k==4) solve4(),solve3();
        else solve5(),solve3();
    }while(next_permutation(imp.begin(),imp.end()));
    if(k==5) 
    {
        sort(imp.begin(),imp.end());
        do
        {
            solve5t();
        }while(next_permutation(imp.begin(),imp.end()));
    }
    cout << ans;
}
