#include <bits/stdc++.h>
using namespace std;

long long n,m,l,r;
vector<long long> a;

int solve(long long x)
{
    long long cnt = 0,res = 0;
    for(long long i = 0;i < n;i++)
    {
        if(res+a[i]>x)
        {
            cnt++;
            res = a[i];
        }
        else res+=a[i];
    }
    if(res>0) cnt++;
    if(cnt>m) return 1;
    if(cnt<m) return 2;
    else return 0;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> m;

    a.resize(n);

    for(long long i = 0;i < n;i++){ cin >> a[i]; l = max(l,a[i]); }

    r = 2000000000;

    while(l<r)
    {
        long long m = (l+r)/2;
        int ok = solve(m);
        if(ok==0)
        {
            if(solve(m+1)==0) l = m+1;
            else{ cout << m; return 0; }
        }
        else if(ok==2) r = m-1;
        else l = m+1;
    }

    if(solve(l)==0) cout << l;
    else cout << "IMPOSSIBLE";
}
