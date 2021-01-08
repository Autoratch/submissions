#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        int a[n];
        for(int i = 0;i < n;i++) a[i] = 0;
        a[0] = 9;
        int j = 8;
        for(int i = 1;i < n;i++)
        {
            a[i] = j;
            j++;
            if(j==10) j = 0;
        }
        for(int i = 0;i < n;i++) cout << a[i];
        cout << '\n';
    }
}