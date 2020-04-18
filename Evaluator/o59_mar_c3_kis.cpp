#include <bits/stdc++.h>
using namespace std;

const int N = 101;

int n,m,a[N];
long long k,dp[N][N],sum[N][N];
bool used[N];
vector<int> bck[N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> m >> k; k+=2LL;
    for(int i = 0;i < n;i++) cin >> a[i];
    for(int i = 0;i < n;i++) for(int j = i+1;j < n;j++) bck[a[i]].push_back(a[j]);
    for(int i = n-1;i >= 0;i--) for(int j = 0;j <= m;j++)
    {
        if(j==0) dp[a[i]][j] = 1;
        for(int l = n-1;l > i;l--)
        {
            if(a[l]<a[i]){ if(j) dp[a[i]][j]+=dp[a[l]][j-1]; }
            else dp[a[i]][j]+=dp[a[l]][j];
        }
        sum[a[i]][j] = dp[a[i]][j];
        if(j) sum[a[i]][j] = sum[a[i]][j-1]+dp[a[i]][j];
    }
    for(int i = 0;i < n;i++) bck[100].push_back(i);
    for(int i = 0;i < n;i++) sort(bck[i].begin(),bck[i].end());
    int lst = 100;
    for(int i = 0;i < n;i++)
    {
        long long tmp = 0;
        int cur = -1;
        k--;
        if(k==0) return 0;
        for(int x : bck[lst])
        {
            if(m==0 and lst!=100 and x<lst) continue;
            if(sum[x][m]>=k-tmp){ cur = x; break; }
            tmp+=sum[x][m];
        }
        if(cur==-1){ cout << "-1"; return 0; }
        k-=tmp;
        if(lst!=100 and lst>cur) m--;
        lst = cur;
        cout << cur << ' ';
    }
}
