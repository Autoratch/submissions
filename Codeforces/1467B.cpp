#include <bits/stdc++.h>
using namespace std;

const int N = 3e5 + 1;

int t,n;
int a[N];

int cal(int l,int r)
{
    l = max(l,0),r = min(r,n-1);
    int cnt = 0;
    for(int i = l+1;i <= r-1;i++) cnt+=(int)((a[i-1]>a[i] and a[i+1]>a[i])or(a[i-1]<a[i] and a[i+1]<a[i]));
    return cnt;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> t;
    while(t--)
    {
        cin >> n;
        for(int i = 0;i < n;i++) cin >> a[i];
        int cnt = cal(0,n-1);
        int mx = 0;
        for(int i = 1;i < n-1;i++) if(a[i]!=a[i-1] or a[i]!=a[i+1])
        {
            int old = cal(i-2,i+2);
            int st = a[i];
            a[i] = INT_MIN;
            int new1 = cal(i-2,i+2);
            a[i] = INT_MAX;
            int new2 = cal(i-2,i+2);
            a[i] = a[i-1];
            int new3 = cal(i-2,i+2);
            a[i] = a[i+1];
            int new4 = cal(i-2,i+2);
            a[i] = st;
            mx = max(mx,old-new1);
            mx = max(mx,old-new2);
            mx = max(mx,old-new3);
            mx = max(mx,old-new4);
        }
        cout << cnt-mx << '\n';
    }
}