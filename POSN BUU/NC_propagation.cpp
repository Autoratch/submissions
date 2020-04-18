#include <bits/stdc++.h>
using namespace std;

const int N = 201;
const int MOD = 1e4 + 7;

struct data
{
    int t[N][N];
};

int n,e,k;
data m[32],ans;

data mul(data *a,data *b)
{
    data c;
    for(int i = 0;i < n;i++) for(int j = 0;j < n;j++)
    { 
        c.t[i][j] = 0;
        for(int k = 0;k < n;k++) c.t[i][j]+=a->t[i][k]*b->t[k][j],c.t[i][j]%=MOD; 
    }
    return c;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> e >> k;

    for(int i = 0;i < e;i++)
    {
        int a,b;
        cin >> a >> b;
        a--,b--;
        m[0].t[a][b] = m[0].t[b][a] = 1;
    }

    for(int i = 0;i < n;i++) m[0].t[i][i] = 1;

    for(int i = 1;i < 30;i++) m[i] = mul(&m[i-1],&m[i-1]);

    for(int i = 0;i < n;i++) ans.t[i][i] = 1;

    for(int i = 0;i < 30;i++) 
    {
        if((1LL<<i)&k) ans = mul(&m[i],&ans);
    }

    for(int i = 0;i < n;i++) cout << ans.t[0][i] << ' ';
}
