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
        if(s[i]=='_'){ res.push_back(s.substr(l,i-l)); l = i+1; }
    }

    for(int i = res.size()-1;i >= 0;i--)
    {
        cout << res[i];
        if(i) cout << "_";
    }
}
