#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;

int n,m;
int a[N];

void update(int idx,int val)
{
    while(idx<N)
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

    while(m--)
    {
        int t;
        cin >> t;
        if(t==1)
        {
            int idx,val;
            cin >> val >> idx;
            update(idx,val);
        }
        else
        {
            int l,r;
            cin >> l >> r;
            cout << read(r)-read(l-1) << '\n';
        }
    }
}
