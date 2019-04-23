#include <bits/stdc++.h>
using namespace std;

const int N = 3e5;

int n,m;
long long a[N],b[N],g;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> m;
bool f = false;
    for(int i = 0;i < n;i++)
    {
        cin >> a[i];
        if(i) 
        {
            if(a[i]==a[i-1]) continue;
            if(!f){ g = a[i]-a[i-1]; f = true; }
            g = __gcd(g,a[i]-a[i-1]);
        }
    }

    for(int i = 0;i < m;i++)
    {
        cin >> b[i];
        if(g%b[i]==0)
        {
            cout << "YES\n";
            cout << a[0] << ' ' << i+1;
            return 0;
        }
    }
    
    cout << "NO";
}
