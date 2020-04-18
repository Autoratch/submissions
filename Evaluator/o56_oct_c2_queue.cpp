#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 1;

int a[N],b[N],m,n,s[N];

void update(int idx,int val)
{
    while(idx<N)
    {
        s[idx]+=val;
        idx+=(idx & -idx);
    }
}

int read(int idx)
{
    int val = 0;
    while(idx>0)
    {
        val+=s[idx];
        idx-=(idx & -idx);
    }
    return val;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> m;
    
    while(m--)
    {
        int c;
        cin >> c;
        if(c==1)
        {
            int x;
            cin >> x;
            a[x] = n+1;
            b[n+1] = x;
            update(x,1);
            n++;
        }
        else if(c==2)
        {
            if(read(N)==0){ cout << "0\n"; continue; }
            int l = 1,r = N;
            while(l<r)
            {
                int m = (l+r)/2;
                if(read(m)==1) r = m;
                else if(read(m)==0) l = m+1;
                else r = m-1;
            }
            update(l,-1);
            cout << a[l] << '\n';
        }
        else
        {
            int x;
            cin >> x;
            cout << read(b[x])-1 << '\n';
        }
    }
}
