#include <bits/stdc++.h>
using namespace std;

const long long N = 3e5 + 1;

long long n,ans;
string s;
long long a[N],b[N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> s;

    for(long long i = 1;i <= n;i++)
    {
        if(s[i-1]=='A') a[i] = a[i-1]+1,ans+=b[i-1];
        else b[i] = b[i-1]+1,ans+=a[i-1];
    }

    reverse(s.begin(),s.end());

    for(long long i = 1;i <= n;i++) a[i] = b[i] = 0;

    for(long long i = 1;i <= n;i++)
    {
        if(s[i-1]=='A') a[i] = a[i-1]+1,ans+=b[i-1];
        else b[i] = b[i-1]+1,ans+=a[i-1];
    }

    for(long long i = 0;i < n-1;i++) if(s[i]!=s[i+1]) ans--;

    cout << n*(n-1)/2-ans;
}

