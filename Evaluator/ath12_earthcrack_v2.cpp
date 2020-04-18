#include <bits/stdc++.h>
using namespace std;

const int N = 501;

int t,m,n;
int a[N][N],s[N][N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> t;

    while(t--)
    {
        cin >> m >> n;
        for(int i = 1;i <= m;i++) for(int j = 1;j <= n;j++) cin >> a[i][j];
        for(int i = 1;i <= m;i++) for(int j = 1;j <= n;j++)
        {
            s[i][j] = s[i-1][j];
            if(j>1) s[i][j] = min(s[i][j],s[i-1][j-1]);           
            if(j<n) s[i][j] = min(s[i][j],s[i-1][j+1]);
            s[i][j]+=a[i][j];
        }
        int ans = INT_MAX;
        for(int i = 1;i <= n;i++) ans = min(ans,s[m][i]);
        cout << ans << '\n';
    }
}