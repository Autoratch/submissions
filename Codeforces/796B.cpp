#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 1;

int n,m,k;
bool h[N],a[N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> m >> k;

    for(int i = 0;i < m;i++){ int x; cin >> x; h[x] = true; }
    
    a[1] = 1;

    if(!h[1]) while(k--)
    {
        int x,y;
        cin >> x >> y;
        swap(a[x],a[y]);
        if(a[x] and h[x]) break;
        if(a[y] and h[y]) break;
    }   

    for(int i = 1;i <= n;i++) if(a[i]){ cout << i; return 0; }
}
