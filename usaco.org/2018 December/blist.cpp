#include <bits/stdc++.h>
using namespace std;

const int N = 1002;

int n,a[N],mx;

int main()
{
    freopen("blist.in","r",stdin);
    freopen("blist.out","w",stdout);

    cin >> n;

    for(int i = 0;i < n;i++)
    {
        int x,y,z;
        cin >> x >> y >> z;
        a[x]+=z;
        a[y+1]-=z;
    }
    
    for(int i = 1;i <= 1000;i++) a[i]+=a[i-1],mx = max(mx,a[i]);

    cout << mx;
}
