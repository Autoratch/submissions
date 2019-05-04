#include <bits/stdc++.h>
using namespace std;

const int N = 3e5 + 1;
const int K = 20;

int n,idx[N],dp[K][N],lv[N];
vector<int> adj[N];

int lca(int a,int b)
{
    if(lv[a]<lv[b]) swap(a,b);
    for(int i = K-1;i >= 0;i--) if(lv[dp[i][a]]>=lv[b]) a = dp[i][a];
    if(a==b) return a;
    for(int i = K-1;i >= 0;i--) if(dp[i][a]!=dp[i][b]) a = dp[i][a],b = dp[i][b];
    return dp[0][a];
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n;

    for(int i = 1;i <= n;i++)
    {
        char c;
        cin >> c;
        if(c=='a')
        {
            int x;
            cin >> x;
            x = idx[x];
            adj[x].push_back(i);
            idx[i] = i;
            lv[i] = lv[x]+1;
            dp[0][i] = x;
            for(int j = 1;j < K;j++) dp[j][i] = dp[j-1][dp[j-1][i]];
        }
        else if(c=='b')
        {
            int x;
            cin >> x;
            x = idx[x];
            if(x==0) cout << "-1\n";
            else
            {
                cout << x << '\n';
                idx[i] = dp[0][x];
            }
        }
        else
        {
            int x,y;
            cin >> x >> y;
            x = idx[x],y = idx[y];
            idx[i] = x;
            cout << lv[lca(x,y)] << '\n';
        }
    }
}
