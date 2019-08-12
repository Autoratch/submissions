#include <bits/stdc++.h>
using namespace std;

const int N = 100;

int t,n,m,k;
int a[N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> t;

    while(t--)
    {
        cin >> n >> m >> k;
        for(int i = 0;i < n;i++) cin >> a[i];
        bool ok = true;
        for(int i = 0;i < n-1;i++)
        {
            if(a[i]>=a[i+1]-k)
            {
                m+=a[i]-max(0,(a[i+1]-k));
            }
            else 
            {
                if(m+a[i]<a[i+1]-k){ ok = false; break; }
                m-=(a[i+1]-k-a[i]);
            }
        }
        if(ok) cout << "YES\n";
        else cout << "NO\n";
    }
}
