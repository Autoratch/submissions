#include <bits/stdc++.h>
using namespace std;

const int N = 1e6;

string s;
long long l[N],r[N];
long long ans;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> s;

    for(int i = 0;i < s.length();i++)
    {
        if(s[i]=='v' and s[i-1]=='v') l[i] = l[i-1]+1;
        else if(i) l[i] = l[i-1];
    }

    for(int i = s.length()-1;i >= 0;i--)
    {
        if(s[i]=='v' and s[i+1]=='v') r[i] = r[i+1]+1;
        else if(i<s.length()-1) r[i] = r[i+1];
    }

    for(int i = 0;i < s.length();i++) if(s[i]=='o') ans+=l[i]*r[i];

    cout << ans;
}
