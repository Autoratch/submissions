#include <bits/stdc++.h>
using namespace std;

const int N = 1e5;

int n,s;
int a[N];
bool f[N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n;

    for(int i = 0;i < n;i++)
    {
        double x;
        cin >> x;
        a[i] = floor(x);
        if(a[i]==x) f[i] = true;
        s+=a[i];
    }

    for(int i = 0;i < n;i++) if(!f[i] and s<0) a[i]++,s++;

    for(int i = 0;i < n;i++) cout << a[i] << '\n';
}
