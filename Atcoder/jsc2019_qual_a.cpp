#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    int x,d;

    cin >> x >> d;

    int ans = 0;

    for(int m = 1;m <= x;m++) for(int i = 1;i <= d;i++) 
    {
        int x = i/10,y = i%10;
        if(x>=2 and y>=2 and x*y==m) ans++;
    }

    cout << ans;
}
