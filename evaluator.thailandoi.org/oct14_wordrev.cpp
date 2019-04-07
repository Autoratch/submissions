#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    string s;
    
    cin >> s;
    
    s+='_';

    int l = 0;

    vector<string> res;

    for(int i = 0;i < s.length()+1;i++)
    {
        if(s[i]=='_'){ for(int j = i-1;j >= l;j--) cout << s[j]; if(i<s.length()-1) cout << "_"; l = i+1; }
    }
}
