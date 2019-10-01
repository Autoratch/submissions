#include <bits/stdc++.h>
using namespace std;

const int N = 1 << 7;
const int K = 28;

struct data
{
    long long t[N][N];
    friend data operator+(const data &a,const data &b)  
    {
        data c;
        for(int i = 0;i < N;i++) for(int j = 0;j < N;j++)
        {
            c.t[i][j] = 0;
            for(int k = 0;k < N;k++) c.t[i][j] = max(c.t[i][j],a.t[i][k]+b.t[k][j]);
        }
        return c;
    }
};

int k,n;
data m[K],tmp,ans;
long long an;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> k >> n;

    for(int i = 0;i < (1 << n);i++) cin >> tmp.t[i][0];

    for(int i = 0;i < (1 << n);i++) for(int j = 0;j < (1 << n);j++) m[0].t[i][j] = LLONG_MIN;

    for(int i = 0;i < (1 << n);i++) m[0].t[i][i/2] = m[0].t[i][i/2+(1 << (n-1))] = tmp.t[i][0];

    for(int i = 1;i < K;i++) m[i] = m[i-1]+m[i-1];

    for(int i = 0;i < K;i++) if((1 << i)&(k-n)) ans = ans+m[i];

    ans = ans+tmp;

    for(int i = 0;i < N;i++) an = max(an,ans.t[i][0]);

    cout << an;
}
