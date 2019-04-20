#include <bits/stdc++.h>
using namespace std;

const int N = 2e5;

int n,a[N],ans = INT_MAX;
string s;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> s;

    for(int i = 0;i < n;i++) if(s[i]=='.') a[i] = a[i-1]+1; else a[i] = a[i-1];

    for(int i = 0;i < n;i++)
    {
        int tmp = 0;
        if(i) tmp = i-a[i-1];
        if(i) tmp+=a[n-1]-a[i-1];
        else tmp = a[n-1];
        ans = min(ans,tmp);
    }
    ans = min(ans,n-a[n-1]);

    cout << ans;
}
