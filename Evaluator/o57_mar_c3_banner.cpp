#include <bits/stdc++.h>
using namespace std;

const int N = 301;

int n,m;
int a[N][N],dp[N][N];
bool visited[N][N];

int solve(int l,int r)
{
    if(visited[l][r]) return dp[l][r];
    visited[l][r] = true;
    if(l==r) return dp[l][r] = a[l][r];
    for(int i = l;i < r;i++)
    {
        dp[l][r] = max(dp[l][r],solve(l,i)+solve(i+1,r));   
    }
    dp[l][r]+=a[l][r];
    return dp[l][r];
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> m;
    for(int i = 0;i < m;i++)
    {
        int x,y;
        cin >> x >> y;
        a[x][y]++;
    }
    cout << m-solve(1,n);
}
