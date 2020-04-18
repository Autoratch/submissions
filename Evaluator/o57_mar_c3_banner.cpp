#include <bits/stdc++.h>
using namespace std;

const int N = 301;

int n,m;
vector<int> s[N];
int dp[N][N];
bool visited[N][N];

int solve(int l,int r)
{
    if(visited[l][r]) return dp[l][r];
    visited[l][r] = true;
    auto itl = lower_bound(s[l].begin(),s[l].end(),r);
    auto itr = upper_bound(s[l].begin(),s[l].end(),r);
    dp[l][r] = itr-itl;
    int tmp = 0;
    for(int i = l;i < r;i++) tmp = max(tmp,solve(l,i)+solve(i+1,r));
    dp[l][r]+=tmp;
    return dp[l][r];
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> m;

    for(int i = 0;i < m;i++)
    {
        int a,b;
        cin >> a >> b;
        s[a].push_back(b);
    }
    for(int i = 1;i <= n;i++) sort(s[i].begin(),s[i].end());

    cout << m-solve(1,n);
}
