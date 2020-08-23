#include <bits/stdc++.h>
using namespace std;

const int N = 2001;

int n,p,q;
int a[N];
long long l = 1,r = 1e9;
int dp[N][N],sm[N],bg[N];

bool solve(int x)
{
    int now = 1;
    for(int i = 1;i <= n;i++) 
    {
        while(now<n and a[now+1]-a[i]+1<=x) now++;
        sm[i] = now;
    }
    now = 1;
    for(int i = 1;i <= n;i++)
    {
        while(now<n and a[now+1]-a[i]+1<=x*2) now++;
        bg[i] = now;
    }
    for(int i = 0;i <= n;i++) for(int j = 0;j <= n;j++)
    {
        dp[i][j] = 0;
        if(i) dp[i][j] = max(dp[i][j],sm[dp[i-1][j]+1]);
        if(j) dp[i][j] = max(dp[i][j],bg[dp[i][j-1]+1]);
        if(dp[i][j]==n and i<=p and j<=q) return true;
    }
    return false;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> p >> q;
    for(int i = 1;i <= n;i++) cin >> a[i];
    sort(a+1,a+n+1);
    while(l<r)
    {
        long long m = (l+r)/2LL;
        if(solve(m)) r = m;
        else l = m+1;
    }
    cout << l;
}
