#include <bits/stdc++.h>
using namespace std;

const int N = 1 << 19;

int n,k;
double a[N],s[N];

bool solve(double x)
{
    double mn = 1e9,ans = INT_MIN;
    for(int i = 1;i <= n;i++)
    {
        s[i] = a[i]-x+s[i-1];
        if(i>=k) mn = min(mn,s[i-k]);
        ans = max(ans,s[i]-mn);
    }
    return ans>=0;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> k;
    for(int i = 1;i <= n;i++) cin >> a[i];
    double l = 1,r = 1e6;
    for(int i = 0;i < 50;i++)
    {
        double m = (l+r)/2;
        if(solve(m)) l = m;
        else r = m;
    }
    cout << fixed << setprecision(6) << l;
}
