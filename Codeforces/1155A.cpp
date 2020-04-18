#include <bits/stdc++.h>
using namespace std;

int n;
string s;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> s;

    for(int i = 0;i < n-1;i++) if(s[i]>s[i+1]){ cout << "YES\n" << i+1 << ' ' << i+2; return 0; }
    cout << "NO";
}
