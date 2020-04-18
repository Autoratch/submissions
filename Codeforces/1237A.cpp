#include <bits/stdc++.h>
using namespace std;

const int N = 13845;

int n;
int a[N],x = 1;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n;

    for(int i = 0;i < n;i++) cin >> a[i];

    for(int i = 0;i < n;i++)
    {
        if(a[i]%2==0) a[i]/=2;
        else a[i] = floor(a[i]/2.0)+x,x = 1-x;
        cout << a[i] << '\n';
    }
}   
