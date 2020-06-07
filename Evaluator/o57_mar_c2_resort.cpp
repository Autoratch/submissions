#include <bits/stdc++.h>
using namespace std;

const int N = 1001;

int m,n,k;
int a[N][N],ans = INT_MAX;

bool solve(int x,int y,int z){ return (a[z][y]-a[z][x-1])>=k; }

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> m >> n >> k;
    for(int i = 0;i < m;i++)
    {
        int x,y;
        cin >> x >> y;
        a[x+1][y+1]++;
    }
    for(int i = 1;i <= n;i++) for(int j = 1;j <= n;j++) a[i][j]+=a[i-1][j]+a[i][j-1]-a[i-1][j-1];
    for(int i = 1;i <= n;i++) for(int j = i;j <= n;j++)
    {
        int l = 1,r = n;
        while(l<r)
        {
            int m = (l+r)/2;
            if(solve(i,j,m)) r = m;
            else l = m+1;
        }
        if(solve(i,j,l)) ans = min(ans,(j-i+1)*l);
    }
    cout << ans;
}
