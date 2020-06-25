#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 1;

int n;
int a[N];
double mnl[N],mxr[N];

bool solve(double x)
{
    double s = 0;
    for(int i = 1;i <= n;i++)
    {
        s+=a[i];
        mnl[i] = s-x*(double)i;
        if(i>1) mnl[i] = min(mnl[i],mnl[i-1]);
    }
    s = 0;
    for(int i = n;i >= 1;i--)
    {
        s+=a[i];
        mxr[i] = x*(double)(n-i+1)-s;
        if(i<n) mxr[i] = max(mxr[i],mxr[i+1]);
    }
    for(int i = 2;i < n;i++) if(mnl[i-1]<mxr[i+1]) return true;
    return false;
}

int main()
{
    freopen("sabotage.in","r",stdin);
    freopen("sabotage.out","w",stdout);
    cin >> n;
    for(int i = 1;i <= n;i++) cin >> a[i];
    double l = 1,r = 1e4;
    for(int i = 0;i < 50;i++)
    {
        double m = (l+r)/2.0;
        if(solve(m)) r = m;
        else l = m;
    }
    cout << fixed << setprecision(3) << l;
}
