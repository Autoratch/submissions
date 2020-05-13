#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 1;

int n;
long long a[N],f[N],w[N],g;
vector<long long> b;

long long lcm(long long x,long long y)
{
    long long g = __gcd(x,y);
    return x*y/g;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    cin >> n;
    for(int i = 1;i <= n;i++) cin >> a[i];
    for(int i = 1;i <= n;i++)
    {
        if(i==1) f[i] = a[i];
        else f[i] = __gcd(a[i],f[i-1]);
    }
    for(int i = n;i >= 1;i--)
    {
        if(i==n) w[i] = a[i];
        else w[i] = __gcd(a[i],w[i+1]);
    }
    for(int i = 1;i <= n;i++)
    {
        long long tmp;
        if(i==1) tmp = w[i+1];
        else if(i==n) tmp = f[i-1];
        else tmp = __gcd(f[i-1],w[i+1]);
        b.push_back(tmp);
    }
    for(long long x : b)
    {
        if(!g) g = x;
        else g = lcm(x,g);
    }
    cout << g;
}
