#include <bits/stdc++.h>
using namespace std;

int t,n;
string s;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> t;

    while(t--)
    {
        cin >> n >> s;
        int l = -1,r = -1;
        for(int i = 0;i < s.length();i++) if(s[i]=='1'){ l = i; break; }
        if(l==-1){ cout << n << '\n'; continue; }
        for(int i = 0;i < s.length();i++) if(s[i]=='1') r = s.length()-1-i;
        cout << max(n,max((n-l)*2,(n-r)*2)) << '\n';
    }
}
