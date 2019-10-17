#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 1;

int n;
int a[N],b[N],s[N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n;

    for(int i = 0;i < n;i++) cin >> a[i];

    for(int i = 0;i < n;i++) s[a[i]] = i+1;

    for(int i = 0;i < n;i++) cin >> b[i],b[i] = s[b[i]];

    int mn = INT_MAX;
    int ans = 0;

    for(int i = n-1;i >= 0;i--){ if(mn<b[i]) ans++; mn = min(mn,b[i]); }

    cout << ans;
}
