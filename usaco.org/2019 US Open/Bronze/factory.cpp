#include <bits/stdc++.h>
using namespace std;

const int N = 101;

int n,ans;
int res[N];
vector<int> adj[N];

void dfs(int u)
{
    res[u]++;
    for(int v : adj[u]) dfs(v);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    freopen("factory.in","r",stdin);
    freopen("factory.out","w",stdout);

    cin >> n;

    for(int i = 0;i < n-1;i++)
    {
        int a,b;
        cin >> a >> b;
        adj[a].push_back(b);
    }

    for(int i = 1;i <= n;i++) dfs(i);

    for(int i = 1;i <= n;i++) if(res[i]==n){ cout << i; return 0; }

    cout << "-1";
}
