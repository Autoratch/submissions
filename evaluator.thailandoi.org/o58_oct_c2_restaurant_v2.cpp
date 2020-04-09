#include <bits/stdc++.h>
using namespace std;

const int N = 301;

int n,t;
long long dist[N][N],deg[N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> t;

    for(int i = 1;i <= n;i++) for(int j = 1;j <= n;j++) cin >> dist[i][j];

    for(int i = 1;i <= n;i++) for(int j = 1;j <= n;j++)
    {
        if(i==j) continue;
        bool f = true;
        for(int k = 1;k <= n;k++) if(i!=k and j!=k and dist[i][k]+dist[k][j]==dist[i][j]) f = false;
        if(f) deg[i]++,deg[j]++; 
    }

    for(int i = 1;i <= n;i++) if(deg[i]>=6)
    {
        cout << i << '\n';
        if(t==2) cout << deg[i]/2;
        return 0;
    }
}
