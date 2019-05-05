#include <bits/stdc++.h>
using namespace std;

const int N = 3000;

int n,a[N],ans;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n;

    for(int i = 0;i < n;i++) cin >> a[i];

    for(int i = 0;i < n;i++) 
    {
        int mn = INT_MAX,mx = INT_MIN;
        for(int j = i;j < n;j++) 
        {
            mn = min(mn,a[j]),mx = max(mx,a[j]);
            if(mx-mn==j-i) ans++;
        }
    }

    cout << ans;
}
