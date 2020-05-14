#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    int t,n,k;
    cin >> t;
    while(t--)
    {
        cin >> n >> k;
        if(n%2==1 and k%2==0){ cout << "NO\n"; continue; }
        int od = -1,ev = -1;
        od = n-(k-1),ev = n-(k-1)*2;
        if(od%2==1 and od>0)
        {
            cout << "YES\n";
            for(int i = 0;i < k-1;i++) cout << "1 ";
            cout << od << '\n';
        }
        else if(ev%2==0 and ev>0)
        {
            cout << "YES\n";
            for(int i = 0;i < k-1;i++) cout << "2 ";
            cout << ev << '\n';
        }
        else cout << "NO\n";
    }
}
