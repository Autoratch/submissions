#include <bits/stdc++.h>
using namespace std;

const int N = 1000;

struct data
{
    int a,b,c,d;
    friend int operator+(const data &a,const data &b)
    {
        return !(a.a>=b.c or b.a>=a.c or a.b>=b.d or b.b>=a.d);
    }
};

int m,n,ans[N];
data a[N],b[N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> m >> n;

    for(int i = 0;i < m;i++) cin >> a[i].a >> a[i].d >> a[i].c >> a[i].b;

    for(int i = 0;i < n;i++) cin >> b[i].a >> b[i].d >> b[i].c >> b[i].b;

    for(int i = 0;i < m;i++) for(int j = 0;j < n;j++) ans[j]+=a[i]+b[j];

    for(int i = 0;i < n;i++) cout << ans[i] << '\n';
}
