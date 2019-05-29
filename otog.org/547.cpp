#include <bits/stdc++.h>
using namespace std;

string t,p;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    while(cin >> t >> p)
    {
        int ans = 0;
        for(int i = 0;i < t.length();i++)
        {
            bool ok = true;
            for(int j = 0;j < p.length();j++)
            {
                if(i+j>=t.length()){ ok = false; break; }
                if(p[j]!=t[i+j]) ok = false;
            }
            if(ok) ans++;
        }
        cout << ans << '\n';
    }
}
