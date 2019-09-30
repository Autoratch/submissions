#include <bits/stdc++.h>
using namespace std;

const int N = 1e3;
const int MOD = 1e9 + 7;

int m,n,a[N],b[N],cnt;
long long ans = 1;
bool an[N][N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    cin >> m >> n;
    
    for(int i = 0;i < m;i++) cin >> a[i];
    for(int i = 0;i < n;i++) cin >> b[i];

    for(int i = 0;i < m;i++) for(int j = 0;j < n;j++) if(i<b[j] or j<a[i]) an[i][j] = true;

    for(int i = 0;i < m;i++) 
    {
        int x = 0;
        for(int j = 0;j < n;j++) if(an[i][j]) x++; else break;
        if(x!=a[i]){ cout << "0"; return 0; }
    }

    for(int i = 0;i < n;i++)
    {
        int x = 0;
        for(int j = 0;j < m;j++) if(an[j][i]) x++; else break;
        if(x!=b[i]){ cout << "0"; return 0; }
    }

    for(int i = 0;i < m;i++) for(int j = 0;j < n;j++)
    {
        if(i>b[j] and j>a[i]) cnt++;
    }

    while(cnt--) ans = (ans*2)%MOD;

    cout << ans;
}
