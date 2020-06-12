#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    int t;
    string s;
    cin >> t;
    while(t--)
    {
        cin >> s;
        int used = 0,ans = 0;
        char l = s[0];
        for(char c : s)
        {
            if(c!=l and !used) used = 1,ans++;
            else used = 0;
            l = c;
        }
        cout << ans << '\n'; 
    }
}
