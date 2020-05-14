#include <bits/stdc++.h>
using namespace std;

const int N = 8001;

int t,n;
int a[N],b[N],c[N],s[N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> t;
    while(t--)
    {
        cin >> n;
        for(int i = 1;i <= n;i++) cin >> a[i],b[i] = 0,c[i] = 0;
        for(int i = 1;i <= n;i++) b[a[i]] = 1,s[i] = s[i-1]+a[i];
        for(int i = 1;i <= n;i++) for(int j = i+1;j <= n;j++)
        {
            if(s[j]-s[i-1]>n) break;
            c[s[j]-s[i-1]] = 1;
        }
        int ans = 0;
        for(int i = 1;i <= n;i++) if(c[a[i]]) ans++;
        cout << ans << '\n';
    }
}
