#include <bits/stdc++.h>
using namespace std;

string s;
map<char,int> o;
map<string,int> t;
int i;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> s;

    while(true)
    {
        if(i==s.length()-1){ o[s[i]]++; i++; }
        else if(s[i+1]<='Z'){ o[s[i]]++; i++; }
        else{ t[s.substr(i,2)]++; i+=2; }
        if(i>=s.length()) break;
    }

    cout << o.size() << '\n';
    for(auto it : o) cout << it.first << ' ' << it.second << endl;
    cout << t.size() << '\n';
    for(auto it : t) cout << it.first << ' ' << it.second << endl;
}
