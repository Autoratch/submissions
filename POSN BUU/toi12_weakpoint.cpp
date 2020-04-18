#include <bits/stdc++.h>
using namespace std;

const int N = 5e5 + 1;

int n,s,lst,cnt,ans,id,root; 
vector<int> adj[N],cy;
bool visited[N],incy[N],fi;

void answer(int val,int i)
{
    if(val>ans) ans = val,id = i;
    else if(val==ans) id = min(id,i);
}

bool dfs(int u,int p)
{
    if(visited[u]){ lst = u; return true; }
    visited[u] = true;
    for(int v : adj[u]) if(v!=p)
    {
        if(dfs(v,u)) 
        {
            if(fi) return true;
            if(u==lst) fi = true;
            incy[u] = true;
            cy.push_back(u);
            return true;
        }
    }
    return false;
}

int dfs2(int u,int p)
{
    if(p and incy[u]) return 0;
    int ret = 0;
    for(int v : adj[u]) if(v!=p) ret+=dfs2(v,u);
    if(u!=s) answer(ret,u);
    ret++;
    return ret;
}

int dfs3(int u,int p)
{
    if(visited[u]) return 0;
    visited[u] = true;
    int ret = 0;
    for(int v : adj[u]) if(v!=p) ret+=dfs3(v,u);
    if(u!=s) answer(ret,u);
    ret++;
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> s;

    for(int i = 0;i < n;i++)
    {
        int a,b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs(s,0);    

    if(incy[s]) 
    {
        dfs2(s,0);
        for(int x : cy) dfs2(x,0);
    }
    else
    {
        for(int i = 1;i <= n;i++) visited[i] = false;
        dfs3(s,0);
    }

    cout << id << '\n' << ans;
}
