#include <bits/stdc++.h>
using namespace std;

int n,k,l;
int f[12],lst;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> k >> l;

    f[0] = 1;
    for(int i = 1;i <= n;i++) f[i] = f[i-1]*i;

    for(int i = 0;i < k;i++)
    {
        int res = 0;
        for(int j = lst+1;j <= n;j++)
        {
            int tmp = f[n-j]/(f[k-i-1]*f[n-j-k+i+1]);
            res+=tmp;
            if(res>=l)
            {
                cout << j << ' ';
                lst = j;
                l-=res-tmp;
                break;
            }
        }
    }
    cout << '\n';
}
