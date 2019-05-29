#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 1;

int t,n,m;
vector<int> adj[N];
int lv[N];
bool ok;

void solve(int x,int k)
{
    if(lv[x]){ if(ok) ok = lv[x]==k; return; }
    lv[x] = k;
    for(int v : adj[x]) solve(v,3-k);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> t;

    while(t--)
    {
        cin >> n >> m;
        for(int i = 1;i <= n;i++) adj[i].clear(),lv[i] = 0;
        for(int i = 0;i < m;i++)
        {
            int a,b;
            cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        ok = true;
        solve(1,1);
        if(ok) cout << "yes";
        else cout << "no";
        cout << '\n';
    }

}
