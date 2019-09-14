#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n;

    cin >> n;

    while(n--)
    {
        string s;
        cin >> s;
        int ans = 0;
        for(char c : s)
        {
            if(c=='J') ans++;
            else if(c=='Q') ans+=2;
            else if(c=='K') ans+=3;
            else if(c=='A') ans+=4;
        }
        cout << ans << '\n';
    }
}
