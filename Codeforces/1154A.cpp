#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    int s[4],a,b,c,d;
    
    for(int i = 0;i < 4;i++) cin >> s[i];
    sort(s,s+4);

    a = s[0],b = s[1],c = s[2],d = s[3];

    cout << d-c << ' ' << d-b << ' ' << d-a;
}
