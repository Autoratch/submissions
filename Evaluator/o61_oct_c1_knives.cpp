#include <bits/stdc++.h>
using namespace std;

const long long N = 1e6 + 100;

long long n,l,q;
long long a[N],s[N],b[N],t[N],h[N];
bool f[N];

void update(long long idx,long long val,long long *s){ idx++; while(idx<N) s[idx]+=val,idx+=(idx & -idx); }

long long read(long long idx,long long *s){ idx++; long long val = 0; while(idx>0) val+=s[idx],idx-=(idx & -idx); return val; }

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> l >> q;

    for(long long i = 0;i < n;i++) h[i] = l;

    update(l,n,a);
    update(l,n*l,s);

    while(q--)
    {
        char c;
        long long x,y;
        cin >> c;
        if(c=='s')
        {
            cin >> x >> y;
            if(!f[x]) update(h[x],-1LL,a),update(h[x],-h[x],s);
            else update(h[x],-1LL,b),update(h[x],-h[x],t);
            if(!f[x]) h[x]+=y,h[x]%=l;
            else h[x]-=y,h[x]+=l,h[x]%=l;
            if(h[x]==0) h[x] = l;
            if(!f[x]) update(h[x],1LL,a),update(h[x],h[x],s);
            else update(h[x],1LL,b),update(h[x],h[x],t);
        }
        else if(c=='f')
        {
            cin >> x;
            if(!f[x]) update(h[x],-1LL,a),update(h[x],-h[x],s);
            else update(h[x],-1LL,b),update(h[x],-h[x],t);
            h[x] = l-h[x];
            if(!f[x]) update(h[x],1LL,b),update(h[x],h[x],t);
            else update(h[x],1LL,a),update(h[x],h[x],s);
            f[x] = !f[x];
        }
        else 
        {
            cin >> x;
            long long unf = x*read(l,a);
            unf-=read(l,s);
            unf+=(read(l,a)-read(x-1LL,a))*l;
            x = l-x;
            long long fli = x*read(l,b);
            if(x==0) fli-=l*read(0,b);
            fli-=read(l,t);
            fli+=(read(l,b)-read(x-1LL,b))*l;
            long long ans = unf+fli;
            cout << ans << '\n';
        }
    }
}
