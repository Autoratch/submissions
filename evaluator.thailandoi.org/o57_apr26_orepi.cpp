#include <bits/stdc++.h>
using namespace std;

const int N = 4e4 + 1;

int n,m;
long long s[N],dp[2][N];

void compute(int l,int r,int optl,int optr,int f)
{
    if(l>r) return;
    int mid = (l+r)/2;
    long long val = LLONG_MAX,opt;
    for(int i = optl;i <= min(optr,mid);i++)
    {
        long long now = dp[f^1][i]+(s[mid]-s[i])*(mid-i);
        if(now<val) val = now,opt = i;
    }
    dp[f][mid] = val;
    compute(l,mid-1,optl,opt,f);
    compute(mid+1,r,opt,optr,f);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> m; m++;
    for(int i = 1;i <= n;i++) cin >> s[i],s[i]+=s[i-1];
    for(int i = 1;i <= n;i++) dp[1%2][i] = s[i]*i;
    for(int i = 2;i <= m;i++) compute(1,n,1,n,i%2);
    cout << dp[m%2][n];
}
