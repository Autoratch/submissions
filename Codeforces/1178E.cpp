#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    string s,ans;
    
    cin >> s;

    int i = 0,j = s.length()-1;

    while(j-i>=3)
    {
        if(s[i]==s[j]) ans+=s[i],i++,j--; 
        else if(s[i]==s[j-1]) ans+=s[i],i++,j-=2;
        else 
        {
            ans+=s[i+1];
            if(s[i+1]==s[j]) j--;
            else j-=2;
            i+=2;
        }
    }

    string a = ans;
    string b = a;

    if(j>=i) a.push_back(s[i]);
    reverse(b.begin(),b.end());
    
    cout << a << b;
}
