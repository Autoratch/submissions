#include <bits/stdc++.h>
using namespace std;

const int N = 101;

int n,m;
int a[N],b[N];
int ans;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n;
    for(int i = 0;i < n;i++) cin >> a[i];
    cin >> m;
    for(int i = 0;i < m;i++) cin >> b[i];
    
    sort(a,a+n);
    sort(b,b+m);

    int x = 0,y = 0;
    while(x<n and y<m)
    {
        if(abs(a[x]-b[y])<=1) ans++,x++,y++;
        else if(a[x]<b[y]) x++;
        else y++;
    }
    
    cout << ans;
}
