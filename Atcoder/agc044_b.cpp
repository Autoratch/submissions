#include <bits/stdc++.h>
using namespace std;

const int N = 3e5;

int n;
int a[N],h[N],x[N],y[N],g[N];
int ans;

void upd(int x)
{
    int nx = h[x];
    if(!g[x]) nx++;
    if(x-n>=1) if(h[x-n]>nx) h[x-n] = nx,upd(x-n);
    if(x+n<=n*n) if(h[x+n]>nx) h[x+n] = nx,upd(x+n);
    if(x%n!=1) if(h[x-1]>nx) h[x-1] = nx,upd(x-1);
    if(x%n!=0) if(h[x+1]>nx) h[x+1] = nx,upd(x+1);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n;
    for(int i = 1;i <= n;i++) for(int j = 1;j <= n;j++) x[(i-1)*n+j] = i,y[(i-1)*n+j] = j;
    for(int i = 1;i <= n*n;i++) cin >> a[i],h[i] = min(min(n-x[i],x[i]-1),min(n-y[i],y[i]-1));
    for(int i = 1;i <= n*n;i++)
    {
        int x = a[i];
        ans+=h[x];
        g[x] = true;
        upd(x);
    }
    cout << ans;
}
