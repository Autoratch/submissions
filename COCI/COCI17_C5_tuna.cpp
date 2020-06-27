#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,x;
    cin >> n >> x;
    int ans = 0;
    while(n--)
    {
        int a,b;
        cin >> a >> b;
        if(abs(a-b)<=x) ans+=max(a,b);
        else cin >> a,ans+=a;
    }
    cout << ans;
}
