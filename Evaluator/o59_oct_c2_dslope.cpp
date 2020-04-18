#include <bits/stdc++.h>
using namespace std;

const int N = 8e4 + 1;
const int K = 41;
const int MOD = 1e9 - 1;

int n,k;
int a[N];
long long dp[N][K],s[N][K];

void update(int x,int idx,long long val)
{ 
    while(idx<=n)
    { 
        s[idx][x] = (s[idx][x]+val)%MOD; 
        idx+=(idx & -idx); 
    } 
}

long long read(int x,int idx)
{ 
    long long val = 0; 
    while(idx>0)
    { 
        val = (val+s[idx][x])%MOD; 
        idx-=(idx & -idx);
    } 
    return val; 
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> k;

    for(int i = 1;i <= n;i++){ cin >> a[i]; a[i] = n+1-a[i]; }

    for(int i = 1;i <= n;i++) for(int j = 1;j <= k;j++)
    {
        if(j==1) dp[i][j] = 1;
        else dp[i][j] = (dp[i][j]+read(j-1,a[i]-1))%MOD;
        update(j,a[i],dp[i][j]);
    }

    cout << read(k,n);
}
