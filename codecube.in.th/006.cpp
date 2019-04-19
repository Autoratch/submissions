#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 1;

int n;
long long a[N],s[N],ans;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n;

    for(int i = 1;i <= n;i++)
    {
        cin >> a[i];
        s[i] = s[i-1];
        if(i%2==0) s[i]+=a[i];
        else s[i]-=a[i];
    }

    ans = s[n];

    for(int i = 1;i <= n;i++) ans = min(ans,s[i-1]-s[n]+s[i-1]);

    long long mxs = 0,mxp = 0;
    for(int i = 1;i <= n;i++) 
    {
        if(i%2==1) a[i] = -a[i];
        mxp+=a[i];
        mxs = max(mxs,mxp);
        if(mxp<0) mxp = 0;
    }
    
    ans = min(ans,s[n]-mxs-mxs);

    cout << ans;
}
