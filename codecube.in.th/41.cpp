#include <bits/stdc++.h>
using namespace std;

const int N = 1e6;

int n;
long long k,l,r;
long long a[N];

long long solve(long long x)
{
    long long cur = 0,ch = 0;
    for(int i = 0;i < n;i++)
    {
        if(cur<a[i]) cur = x,ch++;
        cur-=a[i];
    }
    return ch;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> k;

    if(k==1LL){ cout << "-1"; return 0; }

    for(int i = 0;i < n;i++)
    {
        cin >> a[i];
        l = max(l,a[i]);
        r+=a[i];
    }

    long long al = l,ar = r;

    while(l<r)
    {
        long long m = (l+r)/2LL;
        long long ch = solve(m);
        if(ch<k) r = m-1LL;
        else if(ch>k) l = m+1LL;
        else r = m;
    }

    long long ll = l;
    l = al,r = ar;

    while(l<r)
    {
        long long m = (l+r)/2LL;
        long long ch = solve(m);
        if(ch<k) r = m-1LL;
        else if(ch>k) l = m+1LL;
        else if(solve(m+1)==k) l = m+1LL;
        else{ l = m; break; }
    }
  
    cout << l-ll+1LL;
}
