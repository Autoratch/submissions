#include <bits/stdc++.h>
using namespace std;

int n,dp[2][4][4][4][4],now,pre = 1,ans;
string s;

int cal(int a,int b,int c)
{
    int ret = 0;
    if(a==1 or b==1 or c==1) ret++;
    if(a==2 or b==2 or c==2) ret++;
    if(a==3 or b==3 or c==3) ret++;
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> s;

    for(int i = 0;i <= 3;i++) for(int j = 0;j <= 3;j++) for(int k = 0;k <= 3;k++) for(int l = 0;l <= 3;l++) 
        for(int x = 0;x < 2;x++) dp[x][i][j][k][l] = INT_MIN;
    
    dp[pre][0][0][0][0] = 0;

    for(int i = 0;i < n;i++)
    {
        int x;
        if(s[i]=='M') x = 1;
        else if(s[i]=='B') x = 2;
        else x = 3;
        for(int a = 0;a <= 3;a++) for(int b = 0;b <= 3;b++) for(int c = 0;c <= 3;c++) for(int k = 0;k <= 3;k++)
            dp[now][a][b][c][x] = max(dp[now][a][b][c][x],dp[pre][a][b][k][c]+cal(x,k,c)),ans = max(ans,dp[now][a][b][c][x]);
        for(int a = 0;a <= 3;a++) for(int c = 0;c <= 3;c++) for(int d = 0;d <= 3;d++) for(int k = 0;k <= 3;k++)
            dp[now][a][x][c][d] = max(dp[now][a][x][c][d],dp[pre][k][a][c][d]+cal(x,k,a)),ans = max(ans,dp[now][a][x][c][d]);
        swap(pre,now); 
    }

    cout << ans;
}
