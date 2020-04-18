#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 1;
const int K = 201;

int n,k;
int a[N],op[K][N];
long long s[N],dp[2][N];
vector<int> ans;

void compute(int l,int r,int optl,int optr,int f,int id)
{
    if(l>r) return;
    int mid = (l+r)/2;
    long long val = -1;
    int opt = 1;
    for(int k = optl;k <= min(mid-1,optr);k++)
    {
        long long now = dp[f^1][k]+(s[mid]-s[k])*(s[k]);
        if(now>val) val = now,opt = k;
    }
    op[id][mid] = opt,dp[f][mid] = val;
    compute(l,mid-1,optl,opt,f,id);
    compute(mid+1,r,opt,optr,f,id);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> k;
    for(int i = 1;i <= n;i++) cin >> a[i],s[i] = s[i-1]+a[i];
    for(int i = 1;i <= k;i++) compute(1,n,1,n,i%2,i);
    cout << dp[k%2][n] << '\n';
    for(int i = k,x = n;i >= 1;i--) ans.push_back(x = op[i][x]);
    reverse(ans.begin(),ans.end());
    for(int x : ans) cout << x << ' ';
}
