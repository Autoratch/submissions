#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 1;

int n,m,ans,anr;
vector<int> adj[N],rev[N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> m;

    for(int i = 0;i < m;i++)
    {
        int a,b;
        cin >> a >> b;
        adj[a].push_back(b);
        rev[b].push_back(a);
    }

    for(int i = 1;i <= n;i++) if(!adj[i].size()) ans++;
    for(int i = 1;i <= n;i++) if(!rev[i].size()) anr++;

    cout << max(ans,anr);
}
