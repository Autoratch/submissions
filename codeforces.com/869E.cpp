#include <bits/stdc++.h>
using namespace std;

const int N = 2512;
const long long MOD = 1e9 + 7;

int m,n,q;
int a[N][N];

void update(int x,int y,int val){ for(int i = x;i < N;i+=(i & -i)) for(int j = y;j < N;j+=(j & -j)) a[i][j] = (a[i][j]+val)%MOD; }

int read(int x,int y){ int val = 0; for(int i = x;i > 0;i-=(i & -i)) for(int j = y;j > 0;j-=(j & -j)) val = (val+a[i][j])%MOD; return val; }

int ran(long long x,long long y){ return (x+1)*(y+2); }

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> m >> n >> q;
    while(q--)
    {
        int t,a,b,c,d;
        cin >> t >> a >> b >> c >> d;
        if(t<3)
        {
            int k = ran(a,b);
            if(t==2) k = -k;
            update(a,b,k),update(a,d+1,-k),update(c+1,b,-k),update(c+1,d+1,k);
        }
        else if(read(a,b)==read(c,d)) cout << "Yes\n";
        else cout << "No\n";
    }
}
