#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 1;

int n,x;
int a[N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n;

    for(int i = 0;i < n;i++){ cin >> a[i]; if(a[i]==n) x = i; }

    int t = x;

    t--;
    while(t>=0)
    {
        if(a[t]>a[t+1]){ cout << "NO"; return 0;}
        t--;
    }

    t = x;
    t++;

    while(t<n)
    {
        if(a[t]>a[t-1]){ cout << "NO"; return 0; }
        t++;
    }

    cout << "YES";
}
