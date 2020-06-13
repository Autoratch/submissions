#include <bits/stdc++.h>
using namespace std;

const int N = 5001;

int n,ans = INT_MAX,cn;
vector<int> adj[N],tre[N];
queue<int> q;
bool visited[N];
int res[N];

void dfs(int u)
{
    cn++;
    for(int v : tre[u]) dfs(v),res[u]+=res[v];
    res[u]++;
}

void solve(int s)
{
    for(int i = 1;i <= n;i++) tre[i].clear(),visited[i] = false,res[i] = 0;
    q.push(s),visited[s] = true;
    while(!q.empty())
    {
        int u = q.front(); q.pop();
        for(int v : adj[u]) if(!visited[v])
        {
            visited[v] = true;
            tre[u].push_back(v);
            q.push(v);
        }
    }
    cn = 0;
    dfs(s);
    if(cn!=n) return;
    int now = 0;
    for(int i = 1;i <= n;i++) now+=res[i];
    ans = min(ans,now);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n;
    for(int i = 1;i <= n;i++)
    {
        int am;
        cin >> am;
        while(am--)
        {
            int x;
            cin >> x;
            adj[x].push_back(i);
        }
    }
    for(int i = 1;i <= n;i++) solve(i);
    cout << ans;
}
