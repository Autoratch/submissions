#include <bits/stdc++.h>
using namespace std;

const int N = 30;
const int M = 901;

int m,n,k,cnt[M];
int s[N][N],dp[N][N][N][N];
bool visited[N][N][N][N];
unordered_map<int,int> ma;

int cal(int a,int b,int c,int d)
{
    int ret = 0;
    ma.clear();
    if(a==b) for(int i = c;i <= d;i++) ma[s[a][i]]++;
    else for(int i = a;i <= b;i++) ma[s[i][c]]++;
    for(auto it = ma.begin();it != ma.end();it++) if(cnt[it->first]==it->second) ret++;
    return ret;
}

int solve(int a,int b,int c,int d)
{
    if(visited[a][b][c][d]) return dp[a][b][c][d];
    visited[a][b][c][d] = true;
    if(a==b or c==d) return dp[a][b][c][d] = cal(a,b,c,d);
    for(int i = a;i < b;i++) dp[a][b][c][d] = max(dp[a][b][c][d],solve(a,i,c,d)+solve(i+1,b,c,d));
    for(int i = c;i < d;i++) dp[a][b][c][d] = max(dp[a][b][c][d],solve(a,b,c,i)+solve(a,b,i+1,d));
    return dp[a][b][c][d];
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> m >> n >> k;

    for(int i = 0;i < m;i++) for(int j = 0;j < n;j++) cin >> s[i][j],cnt[s[i][j]]++;

    cout << solve(0,m-1,0,n-1);
}
