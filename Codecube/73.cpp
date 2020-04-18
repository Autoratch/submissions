#include <bits/stdc++.h>
using namespace std;

const int N = 201;

int m,n;
int a[N][N],mx[N][N],mn[N][N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> m >> n;

    for(int i = m;i >= 1;i--) for(int j = 1;j <= n;j++) cin >> a[i][j];

    for(int i = 1;i <= m;i++) mn[i][0] = INT_MAX,mx[i][0] = INT_MIN;
    for(int i = 1;i <= n;i++) mx[0][i] = INT_MIN,mn[0][i] = INT_MAX;
    for(int i = 1;i <= m;i++) for(int j = 1;j <= n;j++) 
    {
        if(i==1 and j==1) mx[i][j] = mn[i][j] = a[i][j];
        else
        {
            mx[i][j] = a[i][j]+max(mx[i][j-1],mx[i-1][j]);
            mn[i][j] = a[i][j]+min(mn[i][j-1],mn[i-1][j]);
        }
    }

    cout << mx[m][n]-mn[m][n];
}
