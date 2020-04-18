#include <bits/stdc++.h>
using namespace std;

const int N = 5e5;

int n,a[6];
int b[43];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n;

    b[4] = 0,b[8] = 1,b[15] = 2,b[16] = 3,b[23] = 4,b[42] = 5;

    for(int i = 0;i < n;i++) 
    {
        int x;
        cin >> x;
        if(b[x]==0 or a[b[x]-1]>a[b[x]]) a[b[x]]++;
    }

    cout << n-a[5]*6;
}
