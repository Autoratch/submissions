#include <bits/stdc++.h>
using namespace std;

const int N = 101;

int n,k;
int a[N];
int dp[N][N][N],ds[N][N];
bool visited[N][N][N],vi[N][N];

int sol(int l,int r);
int solve(int l,int r,int x);

int cal(int x)
{
    if(x>=k) return 0;
    else return k-x;
}

int sol(int l,int r)
{
    if(vi[l][r]) return ds[l][r];
    vi[l][r] = true;
    int tmp = INT_MAX;
    for(int i = 1;i <= 100;i++) tmp = min(tmp,solve(l,r,i));
    return ds[l][r] = tmp;
}


int solve(int l,int r,int x)
{
    if(visited[l][r][x]) return dp[l][r][x];
    visited[l][r][x] = true;
    
    int cur = -1,ls,am = 0,as = 0;
    for(int i = l;i <= r;i++)
    {
        if(a[i]==x) cur = i+1;
        else if(i==r or a[i+1]==x) dp[l][r][x]+=sol(max(cur,l),i),ls = i,cur = max(cur,l),am+=ls-cur+1,as++;
    }

    if(cur==-1) return dp[l][r][x] = 1;
    if(ls==r and cur==l) return dp[l][r][x] = 1e9;

    dp[l][r][x]+=cal(r-l+1-am);
    if(as==1 and (cur==l or ls==r) and cal(r-l+1-am)==0) dp[l][r][x]++;

    return dp[l][r][x];
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> k;

    for(int i = 0;i < n;i++) cin >> a[i];

    cout << sol(0,n-1);
}
