#include <bits/stdc++.h>
using namespace std;

int t;
string s;

bool solve(int l,int r)
{
    while(l<r){ if(s[l]!=s[r]) return false; l++,r--; }
    return true;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> t;
    while(t--)
    {
        cin >> s;
        int l = 0,r = s.length()-1;
        while(l<r)
        {
            if(s[l]!=s[r]) break;
            l++,r--;
        }
        if(l>=r){ cout << s << '\n'; continue; }
        int mx = 0,x,y;
        for(int i = l;i <= r;i++)
        {
            if(solve(l,i)){ if(i-l+1>mx) mx = i-l+1,x = l,y = i; }
            if(solve(i,r)){ if(r-i+1>mx) mx = r-i+1,x = i,y = r; }
        }
        for(int i = 0;i < l;i++) cout << s[i];
        for(int i = x;i <= y;i++) cout << s[i];
        for(int i = r+1;i < s.length();i++) cout << s[i];
        cout << '\n';
    }
}
