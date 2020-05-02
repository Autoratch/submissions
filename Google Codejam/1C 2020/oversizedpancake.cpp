#include <bits/stdc++.h>
using namespace std;

const int N = 301;

int t,n,d;
long long a[N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> t;
    for(int i = 1;i <= t;i++) 
    {
        cin >> n >> d;
        for(int j = 1;j <= n;j++) cin >> a[j];
        cout << "Case #" << i << ": ";
        if(d==2)
        {
            bool ok = false;
            for(int j = 1;j <= n;j++) for(int k = j+1;k <= n;k++) if(a[j]==a[k]) ok = true;
            if(ok) cout << "0\n";
            else cout << "1\n";
        }
        else
        {
            bool ok = false;
            long long mx = LLONG_MIN;
            for(int j = 1;j <= n;j++) mx = max(mx,a[j]);
            for(int j = 1;j <= n;j++) for(int k = j+1;k <= n;k++) for(int l = k+1;l <= n;l++) if(a[j]==a[k] and a[k]==a[l]) ok = true;
            if(ok){ cout << "0\n"; continue; }
            for(int j = 1;j <= n;j++) for(int k = j+1;k <= n;k++) if((a[j]==a[k] and mx>a[j]) or a[j]*2LL==a[k] or a[k]*2LL==a[j]) ok = true;
            if(ok){ cout << "1\n"; continue; }
            cout << "2\n";
        }
    }
}
