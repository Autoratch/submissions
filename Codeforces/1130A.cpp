#include <bits/stdc++.h>
using namespace std;

int n,p,z,m;
int a[100];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n;

    for(int i = 0;i < n;i++) cin >> a[i];

    for(int i = 0;i < n;i++)
    {
        if(a[i]>0) p++;
        else if(a[i]==0) z++;
        else m++;
    }

    if(p*2>=n) cout << "1";
    else if(m*2>=n) cout << "-1";
    else cout << "0";
}
