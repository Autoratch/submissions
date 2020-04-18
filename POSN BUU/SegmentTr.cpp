#include <bits/stdc++.h>
using namespace std;

const int N = 1e5;

int n,m,k;
int a[N],b[400];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> m;
    k = sqrt(n);

    while(m--)
    {
        char c;
        int x,y;
        cin >> c >> x >> y;
        if(c=='U')
        {
            x--;
            a[x] = y;
            b[x/k] = INT_MIN;
            for(int i = x/k*k;i < min(n,x/k*k+k);i++) b[x/k] = max(b[x/k],a[i]);
        }
        else 
        {
            int ans = INT_MIN;
            x--,y--;
            for(int i = x;i <= y;)
            {
                if(i%k!=0) ans = max(ans,a[i]),i++;
                else if(i+k-1<=y) ans = max(ans,b[i/k]),i+=k;
                else ans = max(ans,a[i]),i++;
            }
            cout << ans << '\n';
        }
    }
}
