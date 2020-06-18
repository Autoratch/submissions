#include <bits/stdc++.h>
using namespace std;

const int N = 1501;

int m,n,ans = INT_MAX;
int a[N][N],ul[N][N],ur[N][N],ll[N][N],lr[N][N];
int l[N][N],r[N][N],u[N][N],d[N][N];
int ltor[N][N],utod[N][N],slr[N][N],sud[N][N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> m >> n;
    for(int i = 1;i <= m;i++) for(int j = 1;j <= n;j++) cin >> a[i][j];
    for(int i = 1;i <= m;i++) for(int j = 1;j <= n;j++) slr[i][j] = a[i][j]+slr[i][j-1],sud[i][j] = a[i][j]+sud[i-1][j];
    for(int i = 1;i <= m;i++) for(int j = 1;j <= n;j++)
    {
        ul[i][j] = INT_MAX;
        if(i>1) ul[i][j] = min(ul[i][j],a[i][j]+ul[i-1][j]);
        if(j>1) ul[i][j] = min(ul[i][j],a[i][j]+ul[i][j-1]);
        if(i==1 and j==1) ul[i][j] = a[i][j];
    }
    for(int i = 1;i <= m;i++) for(int j = n;j >= 1;j--)
    {
        ur[i][j] = INT_MAX;
        if(i>1) ur[i][j] = min(ur[i][j],a[i][j]+ur[i-1][j]);
        if(j<n) ur[i][j] = min(ur[i][j],a[i][j]+ur[i][j+1]);
        if(i==1 and j==n) ur[i][j] = a[i][j];
    }
    for(int i = m;i >= 1;i--) for(int j = 1;j <= n;j++)
    {
        ll[i][j] = INT_MAX;
        if(i<m) ll[i][j] = min(ll[i][j],a[i][j]+ll[i+1][j]);
        if(j>1) ll[i][j] = min(ll[i][j],a[i][j]+ll[i][j-1]);
        if(i==m and j==1) ll[i][j] = a[i][j];
    }
    for(int i = m;i >= 1;i--) for(int j = n;j >= 1;j--)
    {
        lr[i][j] = INT_MAX;
        if(i<m) lr[i][j] = min(lr[i][j],a[i][j]+lr[i+1][j]);
        if(j<n) lr[i][j] = min(lr[i][j],a[i][j]+lr[i][j+1]);
        if(i==m and j==n) lr[i][j] = a[i][j];
    }
    for(int i = 1;i <= m;i++) for(int j = 1;j <= n;j++)
    {
        l[i][j] = ul[i][j]+ll[i][j]-a[i][j];
        if(j>1) l[i][j] = min(l[i][j],l[i][j-1]+a[i][j]);
        u[i][j] = ul[i][j]+ur[i][j]-a[i][j];
        if(i>1) u[i][j] = min(u[i][j],u[i-1][j]+a[i][j]);
    }
    for(int i = m;i >= 1;i--) for(int j = n;j >= 1;j--) 
    {
        r[i][j] = ur[i][j]+lr[i][j]-a[i][j];
        if(j<n) r[i][j] = min(r[i][j],r[i][j+1]+a[i][j]);
        d[i][j] = ll[i][j]+lr[i][j]-a[i][j];
        if(i<m) d[i][j] = min(d[i][j],d[i+1][j]+a[i][j]);
    }
    for(int i = 1;i <= m;i++) for(int j = 1;j <= n;j++)
    {
        ans = min(ans,l[i][j]+r[i][j]-a[i][j]);
        ans = min(ans,u[i][j]+d[i][j]-a[i][j]);
    }
    cout << ans;
}
