#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 1;

int n,q;
int a[N],b[N];

void update(int idx,int val,int *a){ while(idx<N) a[idx]+=val,idx+=(idx & -idx); }

int read(int idx,int *a){ int val = 0; if(idx==0) return 0; while(idx>0) val+=a[idx],idx-=(idx & -idx); return val; }

int get(int idx)
{
    int l = 1,r = n;
    while(l<r)
    {
        int m = (l+r)/2;
        int x = read(m,a);
        int y = read(m,b);
        if(x==idx) return m;
        else if(x+read(m,b-1)<idx and x+y>=idx) return -m;
        else if(x+y>idx) r = m-1;
        else l = m+1;
    }
    if(read(l,a)==idx) return l;
    else return -l;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> q;

    for(int i = 1;i <= n;i++) update(i,1,a);

    while(q--)
    {
        char c;
        cin >> c;
        if(c=='d')
        {
            int x;
            cin >> x;
            x++;
            x = get(x);
            if(x<0) update(-x,-1,b);
            else update(x,-1,a);
        }
        else if(c=='g')
        {
            int x;
            cin >> x;
            x++;
            x = get(x);
            if(x<0) update(-x,1,b);
            else update(x,1,b);
        }
        else
        {
            int x,y;
            cin >> x >> y;
            cout << (y-x+1)-(read(y,a)-read(x-1,a))+read(y,b)-read(x-1,b) << '\n';
        }
    }
}
