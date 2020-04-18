#include <bits/stdc++.h>
using namespace std;

struct node
{
    int x,y,t;
}res[12];

int m,n,k;
int dp[1 << 12][12];
int ans = INT_MAX;
vector<bool> t;

int dist(int x,int y)
{
    int a = res[x].x-res[y].x;
    a*=a;
    int b = res[x].y-res[y].y;
    b*=b;
    double d = sqrt(a+b);
    return ceil(d);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> m >> n >> k;

    res[0].x = 0; res[0].y = 0; res[0].t = 0;
    for(int i = 1;i <= k;i++) cin >> res[i].x >> res[i].y >> res[i].t;
    res[k+1].x = m-1; res[k+1].y = n-1; res[k+1].t = 0;

    for(int i = 0;i < (1 << (k+2));i++) for(int j = 0;j <= k+1;j++) dp[i][j] = INT_MAX;
    dp[1][0] = 0;

    for(int i = 1;i < (1 << (k+2));i++) for(int j = 0;j <= k+1;j++)
    {
        if(dp[i][j]==INT_MAX) continue;
        if(j==k+1){ ans = min(ans,dp[i][j]); continue; }
        t.assign(k+2,false);
        int cnt = 0,tmp = i;
        while(tmp)
        {
            t[cnt] = tmp%2;
            tmp/=2; cnt++;
        }
        for(int l = 1;l <= k+1;l++)
        {
            if(t[l]) continue;
            dp[i|(1 << l)][l] = min(dp[i|(1 << l)][l],dp[i][j]+dist(j,l)-res[l].t);
        }
    }

    cout << ans;
}
