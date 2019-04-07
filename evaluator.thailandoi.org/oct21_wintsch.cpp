#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 1;

int n,s[N],e[N],v[N],dp[N],bf[N];
int mx,id,cnt;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n;

    for(int i = 1;i <= n;i++) cin >> s[i] >> e[i] >> v[i];

    for(int i = 1;i <= n;i++) for(int j = 0;j < i;j++)
    {
        if(s[i]<e[j]) continue;
        if(dp[j]+1>dp[i]){ dp[i] = dp[j]+v[i]; bf[i] = j; }
        if(dp[i]>mx){ mx = dp[i]; id = i; }
    }

    cout << mx << '\n';
    for(int i = id;i != 0;i = bf[i]) cnt++;
    cout << cnt << '\n';
    for(int i = id;i != 0;i = bf[i]) cout << i << ' ';
}
