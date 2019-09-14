#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n,d;
    int ans = 0;

    cin >> n >> d;

    while(n--)
    {
        int a,b,c;
        cin >> a >> b;
        if(abs(a-b)<=d) ans+=max(a,b);
        else 
        {
            cin >> c;
            ans+=c;
        }
    }

    cout << ans;
}
