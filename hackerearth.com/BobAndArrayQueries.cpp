#include <bits/stdc++.h>
using namespace std;

const int N = 5e5 + 1;

int n,m,a[N];

void update(int idx,int val){ while(idx<N) a[idx]+=val,idx+=(idx & -idx); }
int read(int idx){ int val = 0; while(idx>0) val+=a[idx],idx-=(idx & -idx); return val; }

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> m;

    while(m--)
    {
        int t,x,y;
        cin >> t;
        if(t==1)    
        {
            cin >> x;
            update(x,1);
        }
        else if(t==2)
        {
            cin >> x;
            if(read(x)-read(x-1)) update(x,-1);
        }
        else
        {
            cin >> x >> y;
            cout << read(y)-read(x-1) << '\n';
        }
    }
} 
