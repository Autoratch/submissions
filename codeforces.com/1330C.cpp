#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 1;

int m,n;
int a[N],ans[N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> m >> n;
    for(int i = 1;i <= n;i++) cin >> a[i];
    for(int i = 1;i <= n;i++){ ans[i] = i; if(ans[i]+a[i]-1>m){ cout << "-1"; return 0; } }
    for(int i = n;i >= 1;i--)
    {
        if(i==n and ans[i]+a[i]-1<m) ans[i] = m-a[i]+1;
        else if(i!=n and ans[i]+a[i]-1<ans[i+1]) ans[i] = ans[i+1]-a[i];
        else break;
    }
    if(ans[1]!=1) cout << "-1";
    else for(int i = 1;i <= n;i++) cout << ans[i] << ' ';
}
