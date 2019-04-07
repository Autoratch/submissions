#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n;

    cin >> n;

    vector<int> a(n);

    for(int i = 0;i < n;i++) cin >> a[i];

    sort(a.begin(),a.end());
    reverse(a.begin(),a.end());

    int ans = 0,l = 0,r = n-1;

    while(true)
    {
        if(l+1<r-2)
        {
            ans+=a[l]+a[r]+a[r-1]+a[r-2];
            if(l+1+1==r-2) break;
            l+=2;
            r-=3;
        }
        else
        {
            for(int i = l;i <= r;i++) ans+=a[i];
            break;
        }
    }
    

    cout << ans;
}
