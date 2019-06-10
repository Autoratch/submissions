#include <bits/stdc++.h>
using namespace std;

const int N = 1e4 + 1;

int n,x,y,c;
int a[N << 1];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> x >> y >> c;

    for(int i = 1;i <= n;i++) for(int j = 1;j <= n;j++) a[abs(i-x)+abs(j-y)]++;

    int cnt = 0;

    for(int i = 0;;i++)
    {
        cnt+=a[i];
        if(cnt>=c){ cout << i; return 0; }
    }
}
