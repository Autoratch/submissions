#include <bits/stdc++.h>
using namespace std;

const int N = 30;

struct node
{
    int a[3];
};

int a[3][3],x[3],y[3];
int t;
string dp[N][N][N];
bool visited[N][N][N];
queue<node> q;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    for(int i = 0;i < 3;i++) for(int j = 0;j < 3;j++) cin >> a[i][j];

    cin >> t;

    while(t--)
    {
        for(int i = 0;i < 3;i++) cin >> x[i];
        for(int i = 0;i < 3;i++) cin >> y[i]; 
        for(int i = 0;i < N;i++) for(int j = 0;j < N;j++) for(int k = 0;k < N;k++) visited[i][j][k] = false,dp[i][j][k] = "NO SOLUTION";
        dp[x[0]][x[1]][x[2]] = "";
        visited[x[0]][x[1]][x[2]] = true;
        node res;
        for(int i = 0;i < 3;i++) res.a[i] = x[i];
        q.push(res);
        while(!q.empty())
        {
            node res = q.front();
            q.pop();
            for(int i = 0;i < 3;i++)
            {
                node ret;
                if(ret.a[i]==0) continue;
                for(int j = 0;j < 3;j++) ret.a[j] = res.a[j]+a[i][j];
                ret.a[i]--;
                if(ret.a[0]>=N or ret.a[1]>=N or ret.a[2]>=N) continue;
                if(ret.a[0]<0 or ret.a[1]<0 or ret.a[2]<0) continue;
                if(visited[ret.a[0]][ret.a[1]][ret.a[2]]) continue;
                visited[ret.a[0]][ret.a[1]][ret.a[2]] = true;
                dp[ret.a[0]][ret.a[1]][ret.a[2]] = dp[res.a[0]][res.a[1]][res.a[2]]+(char)('A'+i);
                q.push(ret);
            }
            for(int i = 0;i < 3;i++)
            {
                node ret;
                for(int j = 0;j < 3;j++) ret.a[j] = res.a[j]-a[i][j];
                if(ret.a[0]<0 or ret.a[1]<0 or ret.a[2]<0) continue;
                ret.a[i]++;
                if(ret.a[0]>=N or ret.a[1]>=N or ret.a[2]>=N) continue;
                if(ret.a[0]<0 or ret.a[1]<0 or ret.a[2]<0) continue;
                if(visited[ret.a[0]][ret.a[1]][ret.a[2]]) continue;
                visited[ret.a[0]][ret.a[1]][ret.a[2]] = true;
                dp[ret.a[0]][ret.a[1]][ret.a[2]] = dp[res.a[0]][res.a[1]][res.a[2]]+(char)('a'+i);
                q.push(ret);
            }
        }
        if(dp[y[0]][y[1]][y[2]][0]!='N') cout << dp[y[0]][y[1]][y[2]].length() << ' ';
        cout << dp[y[0]][y[1]][y[2]] << '\n';
    }
}
