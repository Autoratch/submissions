#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n;
    cin >> n;
    int ans = 0;
    while(n--)
    {
        string s;
        cin >> s;
        for(char c : s) 
        {
            if(c=='A') ans+=4;
            else if(c=='K') ans+=3;
            else if(c=='Q') ans+=2;
            else if(c=='J') ans++;
        }
    }
    cout << ans;
}
