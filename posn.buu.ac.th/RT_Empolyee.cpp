#include <bits/stdc++.h>
using namespace std;

const int N = 250;

struct data
{
    double t[N][N];
};

int n,t;
double b[N][N];
data m[20],a;
data ans;

data mul(data a,data b,bool x)
{
    data c;
    int an = n;
    if(x) an = 1;
    for(int i = 0;i < n;i++) for(int j = 0;j < an;j++)
    {
        c.t[i][j] = 0;
        for(int k = 0;k < n;k++) c.t[i][j]+=a.t[i][k]*b.t[k][j];
    }
    return c;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> t;

    for(int i = 0;i < n;i++) cin >> a.t[i][0];

    for(int j = 0;j < n;j++) for(int i = 0;i < n;i++) cin >> m[0].t[i][j];

    for(int i = 1;i < 20;i++) m[i] = mul(m[i-1],m[i-1],0);

    int tmp = t,cnt = 0;
    vector<int> tm(20);

    while(tmp) tm[cnt++] = tmp%2,tmp/=2;

    for(int i = 0;i < n;i++) ans.t[i][i] = 1;

    for(int i = 0;i < 20;i++) if(tm[i]) ans = mul(ans,m[i],0);

    ans = mul(ans,a,1);

    cout << fixed;
    for(int i = 0;i < n;i++) cout << setprecision(2) << ans.t[i][0] << '\n';
}
