#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n;

    cin >> n;

    vector<int> a(21);

    int i = 0;

    while(n)
    {
        a[i] = n%3;
        n/=3;
        i++;
    }

    int ans = 0,cnt = 0,m = 1;

    for(int i = 0;i < 21;i++)
    {
        if(a[i]==0 or a[i]==1) continue;
        if(a[i]==2){ cnt++; a[i] = 0; a[i+1]++; }
        if(a[i]==3){ a[i] = 0; a[i+1]++; }
    }

    for(int i = 0;i < 21;i++) 
    {
        ans+=a[i]*m;
        cnt+=a[i];
        m*=3;
    }

    cout << cnt << ' ' << ans;
}
