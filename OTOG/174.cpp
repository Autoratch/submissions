#include <bits/stdc++.h>
using namespace std;

int n;
string s;

string solve(string s)
{
    if(s.length()==1) return s;
    reverse(s.begin(),s.end());
    s = solve(s.substr(0,(s.length()+1)/2))+solve(s.substr((s.length()+1)/2,s.length()-s.length()/2));
    return s;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> s;

    cout << solve(s);
}
