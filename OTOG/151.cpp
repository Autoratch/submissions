#include <bits/stdc++.h>
using namespace std;

int n,a[13];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n;

    while(n--)
    {
        int x;
        string s;
        cin >> x >> s;
        int i = 0;
        while(s[i]!='/') i++;
        i++;
        x = 0;
        while(s[i]!='/') x = (x*10+s[i]-'0'),i++;
        a[x]++;
    }

    for(int i = 1;i <= 12;i++) cout << i << ' ' << a[i] << '\n';
}
