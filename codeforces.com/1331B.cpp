#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    int a; cin >> a;
    for(int i = 2;i <= 998;i++) for(int j = 2;j <= 998;j++)
    {
        bool ok = true;
        for(int k = 2;k < i;k++) if(i%k==0) ok = false;
        for(int k = 2;k < j;k++) if(j%k==0) ok = false;
        if(!ok) continue;
        if(i*j==a){ cout << i << j; return 0; }
    }
}
