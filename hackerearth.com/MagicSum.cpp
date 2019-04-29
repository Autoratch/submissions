#include <bits/stdc++.h>
using namespace std;

const int N = 1 << 9;

int t,n,a[N],res[N],ans;
vector<int> path[N];

void dfs(int u,int p)
{
    res[u] = a[u]+res[p];
    path[u] = path[p];
    path[u].push_back(u);
    for(int v = u*2;v <= u*2+1;v++)
    {
        if(v>n) break;
        dfs(v,u);
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> t;

    while(t--)
    {
        cin >> n;
        for(int i = 1;i <= n;i++) cin >> a[i],res[i] = 0;
        dfs(1,0);
        ans = INT_MIN;
        for(int i = n/2+1;i <= n;i++) for(int j = n/2+1;j <= n;j++)
        {
            for(int k = path[i].size()-1;k >= 0;k--)
            {
                if(path[i][k]!=path[j][k]) continue;
                ans = max(ans,res[i]+res[j]-res[path[i][k]]*2+a[path[i][k]]);
                break;
            }
        }
        cout << ans << '\n';
    }
}
