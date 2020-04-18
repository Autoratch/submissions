#include <bits/stdc++.h>
using namespace std;

const int N = 5e4 + 1;
const int K = 501;

int n,k;
vector<int> adj[N];
int res[N][K];
int ans;

void dfs(int u,int p)
{
    res[u][0] = 1;
    int del = 0;
    for(int v : adj[u]) if(v!=p)
    {
        dfs(v,u);
        for(int i = 1;i <= k;i++) res[u][i]+=res[v][i-1],del+=res[v][i-1]*res[v][k-i-1];
//        del+=res[v][k/2-1]*res[v][k/2-1];
    }
    for(int i = 0;i < k-i;i++) ans+=res[u][i]*res[u][k-i];
    ans-=del;
    if(k%2==0) 
    {
       // while(true);
        int tmp = res[u][k/2];
        ans+=(tmp*tmp-del)/2;
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> k;

    for(int i = 0;i < n-1;i++) 
    {
        int a,b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs(1,0);

    cout << ans;
}
