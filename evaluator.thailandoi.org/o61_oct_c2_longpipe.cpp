#include <bits/stdc++.h>
using namespace std;

const int N = 3;
const int K = 31;
const int MOD = 1e9 + 7;

struct data
{
    long long t[N][N];
    friend data operator*(const data &a,const data &b)
    {
        data c;
        for(int i = 0;i < N;i++) for(int j = 0;j < 3;j++)
        {
            c.t[i][j] = 0;
            for(int k = 0;k < N;k++) c.t[i][j] = (c.t[i][j]+(a.t[i][k]*b.t[k][j])%MOD)%MOD;
        }
        return c;
    }
};

int k;
data m[K],ans,tmp;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> k;

    for(int i = 0;i < N;i++) ans.t[i][i] = 1;
    m[0].t[0][0] = m[0].t[0][1] = m[0].t[0][2] = m[0].t[1][1] = m[0].t[2][2] = m[0].t[2][0] = 1;
    m[0].t[1][0] = 2;

    for(int i = 1;i < K;i++) m[i] = m[i-1]*m[i-1];

    for(int i = 0;i < K;i++) if((1 << i)&k) ans = ans*m[i];

    tmp.t[0][0] = tmp.t[1][0] = 1;
    ans = ans*tmp;

    int a = ans.t[0][0],b = ans.t[1][0];

    cout << ((a*2)%MOD+b)%MOD;
}
