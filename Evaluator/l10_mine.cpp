#include <bits/stdc++.h>
using namespace std;

const int N = 1001;

int n,k,ans;
int a[3][N][N],s[3][N][N],b[3][N][N],x[3][N][N],y[3][N][N];
deque<pair<int,int> > q;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> k;

    for(int c = 0;c < 3;c++) for(int i = 1;i <= n;i++) for(int j = 1;j <= n;j++)
    {
        cin >> a[c][i][j];
        s[c][i][j] = a[c][i][j]+s[c][i-1][j]+s[c][i][j-1]-s[c][i-1][j-1];    
    }
    for(int c = 0;c < 3;c++) for(int i = 1;i <= n-k+1;i++) for(int j = 1;j <= n-k+1;j++)
        b[c][i][j] = s[c][i+k-1][j+k-1]-s[c][i-1][j+k-1]-s[c][i+k-1][j-1]+s[c][i-1][j-1];

    for(int c = 0;c < 3;c++)
    {
        for(int i = 1;i <= n-k+1;i++)
        {
            while(!q.empty()) q.pop_front();
            for(int j = 1;j <= n;j++)
            {
                while(!q.empty() and q.front().second<j-k+1) q.pop_front();
                if(j<=n-k+1) 
                {
                    while(!q.empty() and q.back().first<b[c][i][j]) q.pop_back();
                    q.push_back({b[c][i][j],j});
                }
                x[c][i][j] = q.front().first;
            }
        }
        for(int j = 1;j <= n;j++) 
        {
            while(!q.empty()) q.pop_front();
            for(int i = 1;i <= n;i++)
            {
                while(!q.empty() and q.front().second<i-k+1) q.pop_front();
                if(i<=n-k+1) 
                {
                    while(!q.empty() and q.back().first<x[c][i][j]) q.pop_back();
                    q.push_back({x[c][i][j],i});
                }
                y[c][i][j] = q.front().first;
            }
        }   
    }

    for(int i = 1;i <= n;i++) for(int j = 1;j <= n;j++)
    {
        int res = 0;
        for(int k = 0;k < 3;k++) res+=y[k][i][j];
        ans = max(ans,res);
    }

    cout << ans;
}
