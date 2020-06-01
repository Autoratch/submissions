#include <bits/stdc++.h>
using namespace std;

int t,n,x;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> t;
    while(t--)
    {
        cin >> n >> x;
        int deg = 0;
        for(int i = 0;i < n-1;i++)
        {
            int a,b;
            cin >> a >> b;
            if(a==x) deg++;
            else if(b==x) deg++;
        }
        if(deg==1)
        {
            cout << "Ayush\n";
            continue;
        }
        n-=2;
        if(n%2==1) cout << "Ashish\n";
        else cout << "Ayush\n";
    }
}
