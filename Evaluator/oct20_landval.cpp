#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 2;

int n,m;
int a[N];

void update(int idx,int val)
{
    while(idx<=n)
    {
        a[idx]+=val;
        idx+=(idx & -idx);
    }
}

int read(int idx)
{
    int val = 0;
    while(idx>0)
    {
        val+=a[idx];
        idx-=(idx & -idx);
    }
    return val;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> m;

    for(int i = 0;i < m;i++)
    {
        int t;
        cin >> t;
        if(t==1)
        {
            int x,y,k;
            cin >> x >> y >> k;
            update(x,k);
            update(y+1,-k);
        }
        else
        {
            int x;
            cin >> x;
            cout << read(x) << '\n';
        }
    }
}
