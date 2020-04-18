#include <bits/stdc++.h>
using namespace  std;

const int N = 300;

int n;
int a[N][N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n;

    for(int i = 0;i < n;i++) for(int j = 0;j < n;j++)
    {
        a[j][i] = i*n+j+1;
    }

    for(int i = 0;i < n;i++) 
    {
        int l = 0,r = n-1;
        if(i%2==0) continue;
        while(l<r) swap(a[l][i],a[r][i]),l++,r--;
    }

    for(int i = 0;i < n;i++)
    {
        for(int j = 0;j < n;j++) cout << a[i][j] << ' ';
        cout << '\n';
    }
}
