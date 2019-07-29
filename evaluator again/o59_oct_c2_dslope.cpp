#include <bits/stdc++.h>
using namespace std;

const int N = 8e4 + 1;
const int K = 41;
const int MOD = 1e9 - 1;

int n,k;
int a[N],s[N][K];

void update(int idx,int j,int val){ while(idx<=n) s[idx][j] = (s[idx][j]+val)%MOD,idx+=(idx & -idx); }
int read(int idx,int j){ int val = 0; while(idx>0) val = (val+s[idx][j])%MOD,idx-=(idx & -idx); return val; }

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> k;

    for(int i = 1;i <= n;i++) cin >> a[i];

    for(int i = 1;i <= n;i++) for(int j = 1;j <= k;j++)
    {
        int x = ((read(n,j-1)-read(a[i],j-1))%MOD+MOD)%MOD;
        if(j==1) x = 1;
        update(a[i],j,x);
    }

    cout << read(n,k);
}
