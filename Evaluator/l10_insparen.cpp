#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    string s;

    cin >> s;

    int ans = 0,cnt = 0;

    for(int i = 0;i < s.length();i++)
    {
        if(s[i]=='(')
        {
            cnt++;
        }
        else
        {
            if(cnt) cnt--;
            else ans++;
        }
    }

    ans+=cnt;

    cout << ans;
}
