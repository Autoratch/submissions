#include <bits/stdc++.h>
using namespace std;

bool ok(char c)
{
    if(c=='C' or c=='c') return true;
    else return false;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    string s;
    int n = 0,k;

    cin >> s >> k;

    for(int i = 0;i < s.length()-1;i++)
    {
        if(ok(s[i]) and ok(s[i+1])) n++;
    }

    if(n<k) cout << "OCOM is not fun";
    else
    {
        cout << "#OCOMisfun ";
        for(int i = 0;i < n-k;i++) cout << "fun ";
    }
}
