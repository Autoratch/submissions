#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 1;

int n,a,ma,b,mb;
bool s[N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> b >> a;
    ma = a,mb = b;

    for(int i = 1;i <= n;i++) cin >> s[i];
    for(int i = 1;i <= n;i++)
    {
        if(s[i])
        {
            if(b and a<ma) b--,a++;
            else a--;
        }
        else
        {
            if(a) a--;
            else b--;
        }
        if(a==0 and b==0){ cout << i; return 0; }
    }

    cout << n;
}
