#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 3;

int n;
long long k,l,r,sol;
long long a[N];
vector<long long> b;
int fw[N];

void update(int idx,int val){ while(idx<N) fw[idx]+=val,idx+=(idx & -idx); }

int read(int idx){ int val = 0; while(idx>0) val+=fw[idx],idx-=(idx & -idx); return val; }

bool solve(long long x)
{   
    for(int i = 0;i < N;i++) fw[i] = 0;
    long long ret = 0;
    for(int i = 1;i <= n;i++)
    {
        update(lower_bound(b.begin(),b.end(),a[i-1])-b.begin()+1,1);
        ret+=read(upper_bound(b.begin(),b.end(),a[i]-x)-b.begin());
    }
    return ret>=k;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> k;
    for(int i = 1;i <= n;i++) cin >> a[i],a[i]+=a[i-1],b.push_back(a[i]);
    b.push_back(0);
    sort(b.begin(),b.end());
    r = 100000000005LL,l = -r;
    while(l<=r)
    {
        long long m = (l+r)/2LL;
        bool ok = solve(m);
        if(ok) sol = m,l = m+1LL;
        else r = m-1LL;
    }
    cout << sol;
}
