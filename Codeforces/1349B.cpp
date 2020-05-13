#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 2;

int t,n,k;
int a[N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> t;
    while(t--)
    {
        cin >> n >> k;
        for(int i = 1;i <= n;i++) cin >> a[i];
        a[n+1] = 0;
        bool ok = false,me = false,ha = false;
        if(n==1 and a[1]==k) ok = true;
        for(int i = 1;i <= n;i++) 
        {
            if(a[i]==k) ha = true;
            if(a[i]==k and a[i+1]>=k) ok = true;
            if(a[i]==k and a[i-1]>=k) ok = true;
            if(a[i]>=k and a[i+1]>=k) me = true;
            if((a[i-1]==k or a[i+1]==k) and a[i-1]>=k and a[i+1]>=k) ok = true;
            if(a[i-1]>=k and a[i+1]>=k) me = true;
        }
        if(ok or (ha and me)) cout << "YES\n";
        else cout << "NO\n";
    }
}
