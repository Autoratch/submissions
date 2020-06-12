#include <bits/stdc++.h>
using namespace std;

const int N = 51;

int m,n;
int s[N][N],dp[N][N][N][N];
bool visited[N][N][N][N];

int solve(int a,int b,int c,int d)
{
    if(visited[a][b][c][d]) return dp[a][b][c][d];
    visited[a][b][c][d] = true;
    if(a==b and c==d) return 0;
    dp[a][b][c][d] = INT_MAX;
    for(int i = a;i < b;i++) dp[a][b][c][d] = min(dp[a][b][c][d],solve(a,i,c,d)+solve(i+1,b,c,d));
    for(int i = c;i < d;i++) dp[a][b][c][d] = min(dp[a][b][c][d],solve(a,b,c,i)+solve(a,b,i+1,d));
    return dp[a][b][c][d]+=s[b][d]-s[a-1][d]-s[b][c-1]+s[a-1][c-1];
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> m >> n;
    for(int i = 1;i <= m;i++) for(int j = 1;j <= n;j++) cin >> s[i][j],s[i][j]+=s[i-1][j]+s[i][j-1]-s[i-1][j-1];
    cout << solve(1,m,1,n);
}
