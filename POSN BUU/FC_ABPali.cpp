#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n;

    cin >> n;

    for(int i = 0;i < n;i++)
    {
        if(i%4==0 or i%4==1) cout << 'a';
        else cout << 'b';
    }
}