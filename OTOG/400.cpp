#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    int t;

    cin >> t;

    while(t--)
    {
        int a,b;
        cin >> a >> b;
        int x = (21*60-a*60-b-15);
        if(x<=0) cout << "0 0"; 
        else cout << x << ' ' << (x+1)/2;
        cout << '\n';
    }
}
