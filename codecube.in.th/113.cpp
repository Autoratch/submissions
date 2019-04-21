#include <bits/stdc++.h>
using namespace std;

int k,a[10],d,mn = INT_MAX;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> k;
    for(int i = 0;i < 10;i++)
    { 
        cin >> a[i];
        mn = min(mn,a[i]);
    }
    d = k/mn;
    if(!d){ cout << "-1"; return 0; }
    int cnt = 0;
    if(a[0]==mn) d--;
    while(true)
    {
        d--;
        cnt++;
        if(d<0) return 0;
        for(int i = 9;i >= 0;i--) if(k-a[i]>=mn*d)
        {
            if(cnt==1 and i==0){ cout << "-1"; return 0; }
            cout << i;
            k-=a[i];
        }
    }
}
