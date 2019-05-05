#include <bits/stdc++.h>
using namespace std;

const int N = 3e5 + 1;

int n,m,k,mu,md,ans[N];
vector<int> adj[N],rev[N],eq[N];
bool visited[N];
vector<int> tmp;

void dfs(int u,int val,int lv)
{
    if(visited[u]) return;
    visited[u] = true;
    tmp.push_back(u);
    md = max(md,lv),mu = min(mu,lv);
    if(val!=-1) ans[u] = val;
    for(int v : rev[u]){ int va = val; if(va!=-1) va--; dfs(v,va,lv-1); }
    for(int v : adj[u]){ int va = val; if(va!=-1) va++; dfs(v,va,lv+1); } 
    for(int v : eq[u]) dfs(v,val,lv);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> m >> k;

    for(int i = 0;i < k;i++)
    {
        string s;
        cin >> s;
        int a = 0,b = 0;
        int x = 0;
        while(s[x]>='0' and s[x]<='9') a = (a*10)+s[x]-'0',x++;
        char c;
        c = s[x];
        x++;
        while(x<s.length()) b = (b*10)+s[x]-'0',x++;
        if(c=='<') adj[a].push_back(b),rev[b].push_back(a);
        else if(c=='>') adj[b].push_back(a),rev[a].push_back(b);
        else
        {
            eq[a].push_back(b);
            eq[b].push_back(a);
        }
    }

    for(int i = 1;i <= m;i++)
    {
        if(visited[i]) continue;
        mu = 0,md = 0;
        dfs(i,-1,0);
        for(int x : tmp) visited[x] = false;
        tmp.clear();
        if(mu+md+1==n) dfs(i,mu+1,0);
        for(int x : tmp) visited[x] = true;
        tmp.clear();
    }

    for(int i = 1;i <= m;i++) 
    {
        if(ans[i]) cout << "K" << ans[i] << '\n';
        else cout << "?\n";
    }
}
