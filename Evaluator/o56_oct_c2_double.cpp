#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 1;

int n;
int a[N],s[N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n;

    for(int i = 1;i <= n;i++){ cin >> a[i]; s[i] = a[i]+s[i-1]; }

    for(int i = 1;i <= n;i++)
    {
        if(s[i]==s[n]-s[i]){ cout << i; return 0; }
    }

    for(int i = 1;i <= n;i++)
    {
        auto it = lower_bound(s+1,s+n+1,(2*s[i]-s[n])/2);
        if(*it==(s[i]*2-s[n])/2){ cout << it-s << ' ' << i; return 0; }
    }

    cout << "NO";
}
