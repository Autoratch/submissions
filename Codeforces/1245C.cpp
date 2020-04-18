#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 1;
const int MOD = 1e9 + 7;

string s;
int a[N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> s;

    a[0] = 1;
    a[1] = 1;

    for(int i = 2;i <= s.length();i++)
    {
        a[i] = a[i-1];
        if(s[i-1]==s[i-2] and (s[i-1]=='u' or s[i-1]=='n')) a[i] = (a[i]+a[i-2])%MOD;
    }

    for(char c : s) if(c=='w' or c=='m'){ cout << "0"; return 0; }

    cout << a[s.length()];
}