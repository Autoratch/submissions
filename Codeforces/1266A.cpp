#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    int t;
    cin >> t;
    while(t--)  
    {
        string s;
        cin >> s;
        sort(s.begin(),s.end());
        if(s[0]!='0'){ cout << "cyan\n"; continue; }
        int x = 0;
        for(char c : s) x+=(c-'0');
        if(x%3){ cout << "cyan\n"; continue; }
        bool o = false;
        for(int i = 1;i < s.length();i++){ int x = s[i]-'0'; if(x%2==0) o = true; }
        if(o) cout << "red\n";
        else cout << "cyan\n";
    }
}
