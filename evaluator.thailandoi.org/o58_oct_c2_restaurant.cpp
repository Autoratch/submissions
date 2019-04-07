#include <bits/stdc++.h>
using namespace std;

const int N = 300;

int n,t;
int a[N][N],deg[N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    cin >> n >> t;

    for(int i = 0;i < n;i++) for(int j = 0;j < n;j++) cin >> a[i][j];

    for(int i = 0;i < n;i++) for(int j = i+1;j < n;j++)
    {
        bool cn = true;
        for(int k = 0;k < n;k++)
        {
            if(k==i or k==j) continue;
            if(a[i][k]+a[k][j]<=a[i][j]) cn = false;
        }
        if(cn){ deg[i]++; deg[j]++; }
    }

    for(int i = 0;i < n;i++) if(deg[i]>2)
    {
        cout << i+1 << '\n';
        if(t==2) cout << deg[i];
        return 0;
    }
}
