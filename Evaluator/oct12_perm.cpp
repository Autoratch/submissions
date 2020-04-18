#include <bits/stdc++.h>
using namespace std;

int n,k,l;
int f[12];
bool used[12];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> k >> l;

    f[0] = 1;
    for(int i = 1;i <= n;i++) f[i] = f[i-1]*i;

    for(int i = 0;i < k;i++)
    {
        int tmp = f[n-i-1]/f[n-k],res = 0;
        for(int j = 1;j <= n;j++)
        {
            if(used[j]) continue;
            res+=tmp;
            if(res>=l)
            {
                cout << j << ' ';
                used[j] = true;
                l-=res-tmp;
                break;
            }
        }
    }
    cout << '\n';
}
