#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    string s;

    cin >> s;

    int now = 0,ans = 0;

    for(char c : s)
    {
        if(c==')') now--;
        if(now<0) ans++,now = 0;
        if(c=='(') now++;
    }

    ans+=now;

    cout << ans;
}