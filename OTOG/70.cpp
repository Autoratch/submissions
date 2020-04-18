#include <bits/stdc++.h>
using namespace std;

const int N = 11;

int n;
int a[N],b[N];
pair<string,int> dp[N][N];
bool visited[N][N];

pair<string,int> solve(int l,int r)
{
    if(visited[l][r]) return dp[l][r];
    visited[l][r] = true;
    if(l+1==r)
    {
        dp[l][r].first = "(A";
        dp[l][r].first+=(char)(l+'0');
        dp[l][r].first+=" x A";
        if(r>9) dp[l][r].first+='1';
        dp[l][r].first+=(char)(r%10+'0');
        dp[l][r].first+=")";
        dp[l][r].second = a[l]*a[r]*b[r];
        return dp[l][r];
    }
    if(l==r)
    {
        dp[l][r].first = 'A';
        if(l>9) dp[l][r].first+='1';
        dp[l][r].first+=(char)(r%10+'0');
        return dp[l][r];
    }
    dp[l][r].second = INT_MAX;
    for(int i = l;i < r;i++)
    {
        pair<string,int> x = solve(l,i),y = solve(i+1,r);
        if(x.second+y.second+a[l]*b[i]*b[r]<dp[l][r].second) 
        {
            dp[l][r].first = "(";
            dp[l][r].first+=x.first;
            dp[l][r].first+=" x ";
            dp[l][r].first+=y.first;
            dp[l][r].first+=")";
            dp[l][r].second = x.second+y.second+a[l]*b[i]*b[r];
        }
    }
    return dp[l][r];
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n;

    for(int i = 1;i <= n;i++) cin >> a[i] >> b[i];

    pair<string,int> ans = solve(1,n);

    cout << ans.second << '\n' << ans.first;
}
