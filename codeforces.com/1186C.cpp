#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    string a,b;

    cin >> a >> b;

    int x = 0,y = 0;

    for(char c : b) x+=c-'0';
    for(int i = 0;i < b.length();i++) y+=a[i]-'0';

    int ans = 0;

    ans+=x%2==y%2;

    for(int i = b.length();i < a.length();i++)
    {
        y+=a[i]-'0';
        y-=a[i-b.length()]-'0';
        ans+=x%2==y%2;
    }

    cout << ans;
}
