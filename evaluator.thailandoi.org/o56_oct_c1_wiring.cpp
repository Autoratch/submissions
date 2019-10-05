#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 1;

int t,n;
int a[N],b[N],nxt[N];
int now;
bool ans,visited[N];

void dfs(int u)
{
    if(u==0) return;
    if(u==now){ ans = true; return; }
    if(visited[u]) return;
    visited[u] = true;
    dfs(nxt[u]);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> t;

    while(t--)
    {
        cin >> n;
        for(int i = 0;i < n;i++) cin >> a[i];
        for(int i = 0;i < n;i++) cin >> b[i];
        for(int i = 0;i < n;i++) if(a[i] and a[i]!=b[i]) nxt[a[i]] = b[i];
        ans = false;
        for(int i = 1;i <= n;i++) visited[i] = false;
        for(int i = 1;i <= n;i++) now = i,dfs(nxt[i]);
        if(ans) cout << "NO\n";
        else cout << "YES\n";
    }
}
