#include <bits/stdc++.h>
using namespace std;

const int N = 1001;

int n,k,ans = INT_MIN;
int s[N][3],dp[N][N][3][3][3];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> k;
    for(int i = 1;i <= n;i++) for(int j = 0;j < 3;j++) cin >> s[i][j];
    for(int x = 0;x <= k;x++) for(int a = 0;a < 3;a++) for(int b = 0;b < 3;b++) for(int c = 0;c < 3;c++) dp[0][x][a][b][c] = INT_MIN;
    dp[0][0][0][0][0] = 0;
    for(int i = 1;i <= n;i++) for(int j = 0;j <= k;j++) 
    {
        for(int a = 0;a < 3;a++) for(int b = 0;b < 3;b++) for(int c = 0;c < 3;c++)
        {
            dp[i][j][a][b][c] = INT_MIN;
            if(a==2 and b!=2) continue;
            else if(b==2 and a!=2 and c!=2) continue;// dp[i][j][a][b][c] = INT_MIN;
            else if(c==2 and b!=2) continue; //dp[i][j][a][b][c] = INT_MIN;
            else if(a==2 and b==2 and c==2) continue; //dp[i][j][a][b][c] = INT_MIN;
            else if(i==1 and (a==1 or b==1 or c==1)) continue; // dp[i][j][a][b][c] = INT_MIN;
            else
            {
                int cnt = 0,add = 0;
                if(a==2) add+=s[i][0];
                else if(a==1) add+=s[i][0]+s[i-1][0];
                if(b==2) add+=s[i][1];
                else if(b==1) add+=s[i][1]+s[i-1][1];
                if(c==2) add+=s[i][2];
                else if(c==1) add+=s[i][2]+s[i-1][2];
                if(a==2 or b==2 or c==2) cnt++;
                if(a==1) cnt++;
                if(b==1) cnt++;
                if(c==1) cnt++;
                if(j<cnt) continue;
                int d = 3,e = 3,f = 3;
                if(a==1) d = 1;
                if(b==1) e = 1;
                if(c==1) f = 1;
                for(int x = 0;x < d;x++) for(int y = 0;y < e;y++) for(int z = 0;z < f;z++)
                {
                    if(dp[i-1][j-cnt][x][y][z]==INT_MIN) continue;
                    dp[i][j][a][b][c] = max(dp[i][j][a][b][c],dp[i-1][j-cnt][x][y][z]+add);
                }
            }
            //cout << i << ' ' << j << ' ' << a << ' ' << b << ' ' << c << ' ' << dp[i][j][a][b][c] <<  endl;
            if(j==k) ans = max(ans,dp[i][j][a][b][c]);
        }
    }
    cout << ans;
}
