#include "boxes.h"
#include <bits/stdc++.h>
using namespace std;

const int N = 1e7 + 2;

long long dp[N],dr[N],ans = LLONG_MAX;

long long delivery(int n,int k,int l,int p[]) 
{
    for(int i = 1;i <= n;i++)
    {
        dp[i] = dp[max(i-k,0)]+p[i-1]+min(p[i-1],l-p[i-1]);
    }
    for(int i = n;i >= 1;i--)
    {
        dr[i] = dr[min(i+k,n+1)]+l-p[i-1]+min(p[i-1],l-p[i-1]);
    }
    for(int i = 0;i <= n;i++) ans = min(ans,dp[i]+dr[i+1]);
    return ans;
}
