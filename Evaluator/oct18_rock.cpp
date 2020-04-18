#include <bits/stdc++.h>
using namespace std;

const int N = 100;

int n;
int a[N],dp[N][N];
bool visited[N][N];

int solve(int l,int r)
{
    if(visited[l][r]) return dp[l][r];
    visited[l][r] = true;
    if(l==r) dp[l][r] = a[l]; 
    else if(l+1==r) dp[l][r] = max(a[l],a[r]);
    else
    {   
        dp[l][r] = max(dp[l][r],a[l]+max(solve(l+1,r-1),solve(l+2,r)));
        dp[l][r] = max(dp[l][r],a[r]+max(solve(l+1,r-1),solve(l,r-2)));
    }
    return dp[l][r];
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n;

    for(int i = 0;i < n*2;i++) cin >> a[i];

    cout << solve(0,n*2-1);
}
