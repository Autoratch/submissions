#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    int t,n;
    cin >> t;
    while(t--)
    {
        cin >> n;
        int x = 0,y = 0;
        bool ok = true;
        for(int i = 0;i < n;i++)
        {
            int a,b;
            cin >> a >> b;
            if(a<x or b<y or b-y>a-x) ok = false;
            x = a,y = b;
        }
        if(ok) cout << "YES\n";
        else cout << "NO\n";
    }
}
