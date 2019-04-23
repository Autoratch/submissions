#include <bits/stdc++.h>
using namespace std;

int n;
string s;
int a8;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> s;

    for(int i = 0;i < n-11;i++) 
    {
        if(s[i]=='8') a8++;
    }
    if(s[n-11]=='8') a8++;

    if(a8>(n-11)/2) cout << "YES";
    else cout << "NO";
}
