#include <bits/stdc++.h>
using namespace std;

const int N = 1501;
const int K = 51;

int n,k;
int a[N];
int dp[N][K],res[N][N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> k;

    for(int i = 1;i <= n;i++) cin >> a[i];

    for(int i = 1;i <= n;i++)
    {
        priority_queue<int> ql;
        priority_queue<int,vector<int>,greater<int> > qr;
        int sl = 0,sr = 0;
        for(int j = i;j <= n;j++)
        {
            qr.push(a[j]),sr+=a[j];
            if(ql.size()>=1 and ql.top()>qr.top())
            {
                int a = ql.top(),b = qr.top();
                ql.pop(),qr.pop();
                sl+=a,sr-=b;
                ql.push(b),sl-=b;
                qr.push(a),sr+=a;
            }
            if(ql.size()+1<qr.size())
            {
                int a = qr.top(); qr.pop();
                sr-=a,sl-=a;
                ql.push(a);
            }
            res[i][j] = sl+sr+qr.top()*(ql.size()-qr.size());
        }
    }
    
    for(int i = 1;i <= n;i++) for(int j = 1;j <= k;j++)
    {
        if(j>=i) continue;
        dp[i][j] = INT_MAX;
        for(int x = 0;x < i;x++){ if(x and j==1) continue; dp[i][j] = min(dp[i][j],dp[x][j-1]+res[x+1][i]); }
    }

    cout << dp[n][k];
}
