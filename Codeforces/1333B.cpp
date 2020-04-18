#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 1;

int t,n;
int a[N],b[N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> t;
    while(t--)
    {
        cin >> n;
        bool ok = true;
        for(int i = 1;i <= n;i++) cin >> a[i];
        for(int i = 1;i <= n;i++) cin >> b[i];
        bool mo = 0,le = 0;
        for(int i = 1;i <= n;i++)
        {
            if(b[i]>a[i] and !mo) ok = false;
            if(b[i]<a[i] and !le) ok = false;
            if(a[i]==-1) le = true;
            if(a[i]==1) mo = true;
        }
        if(ok) cout << "YES\n";
        else cout << "NO\n";

    }
}
