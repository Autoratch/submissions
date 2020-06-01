#include <bits/stdc++.h>
using namespace std;

const int N = 1001;

int t;
string s;
int a[N];

int z(int l,int r)
{
    return r-l+1-a[r]+a[l-1];
}

int o(int l,int r)
{
    return a[r]-a[l-1];
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> t;
    while(t--)
    {
        cin >> s;
        int id = 0;
        int n = s.length();
        for(char c : s) a[++id] = c-'0';
        for(int i = 1;i <= n;i++) a[i]+=a[i-1];
        int ans = min(z(1,n),o(1,n));
        for(int i = 1;i < n;i++)
        {
            ans = min(ans,z(1,i)+o(i+1,n));
            ans = min(ans,o(1,i)+z(i+1,n));
        }
        cout << ans << '\n';
    }
}
