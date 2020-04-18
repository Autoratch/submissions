#include <bits/stdc++.h>
using namespace std;

const int K = 20;
const int N = 100;
const int MOD = 2009;

int k,n;
int a[N];
int dp[N][N][K];
bool visited[N][N][K];
vector<pair<int,int> > mul[K];

int solve(int l,int r,int x)
{
    if(l==r) return a[l]==x;
    if(visited[l][r][x]) return dp[l][r][x];
    visited[l][r][x] = true;
    for(int i = l;i < r;i++)
    {
        for(int j = 0;j < mul[x].size();j++)
        {
            int a = mul[x][j].first,b = mul[x][j].second;
            int res = solve(l,i,a)*solve(i+1,r,b);
            dp[l][r][x] = (dp[l][r][x]+res%MOD)%MOD;
        }
    }
    return dp[l][r][x];
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> k;
    for(int i = 0;i < k;i++) for(int j = 0;j < k;j++){ int x; cin >> x; mul[x].push_back({i,j}); }
    cin >> n;
    for(int i = 0;i < n;i++) cin >> a[i];

    for(int i = 0;i < k;i++) cout << solve(0,n-1,i) << '\n'; 
}
