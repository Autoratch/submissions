#include <bits/stdc++.h>
using namespace std;
 
int n,dp[2][4][4][4][4],a[100000],then = 0,now = 1,ans;
string s;
 
int uni(int x,int y,int z)
{
    int val = 0;
    if(x==1 or y==1 or z==1) val++;
    if(x==2 or y==2 or z==2) val++;
    if(x==3 or y==3 or z==3) val++;
    return val;
}
 
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
 
    cin >> n >> s;
 
    for(int i = 0;i < n;i++)
    {
        if(s[i]=='M') a[i] = 1;
        else if(s[i]=='F') a[i] = 2;
        else a[i] = 3;
    }
 
    for(int xl = 0;xl < 4;xl++) for(int xr = 0;xr < 4;xr++) for(int yl = 0;yl < 4;yl++) for(int yr = 0;yr < 4;yr++)
    {
        dp[then][xl][xr][yl][yr] = INT_MIN;
        dp[now][xl][xr][yl][yr] = INT_MIN;
    }
 
    dp[then][0][a[0]][0][0] = 1;
    dp[then][0][0][0][a[0]] = 1;
 
    for(int i = 1;i < n;i++)
    {
        for(int xl = 0;xl < 4;xl++) for(int xr = 0;xr < 4;xr++) for(int yl = 0;yl < 4;yl++) for(int k = 0;k < 4;k++)
            dp[now][xl][xr][yl][a[i]] = max(dp[now][xl][xr][yl][a[i]],dp[then][xl][xr][k][yl]+uni(a[i],yl,k));
        for(int yl = 0;yl < 4;yl++) for(int yr = 0;yr < 4;yr++) for(int xl = 0;xl < 4;xl++) for(int k = 0;k < 4;k++)
            dp[now][xl][a[i]][yl][yr] = max(dp[now][xl][a[i]][yl][yr],dp[then][k][xl][yl][yr]+uni(a[i],xl,k));
        swap(then,now);
    }
 
    for(int xl = 0;xl < 4;xl++) for(int xr = 0;xr < 4;xr++) for(int yl = 0;yl < 4;yl++) for(int yr = 0;yr < 4;yr++)
        ans = max(ans,dp[then][xl][xr][yl][yr]);
 
    cout << ans;
}
