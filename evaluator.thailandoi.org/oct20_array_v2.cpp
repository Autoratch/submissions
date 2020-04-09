#include <bits/stdc++.h>
using namespace std;

const long long N = 1 << 18;

tuple<long long,long long,long long,long long> inp[N];
long long l,m,n,idx;
set<long long> s;
//map<long long,long long> id,va;
long long va[N];
/*struct node
{
    long long l,r,val,sum;
}tree[N << 1LL];*/
long long lazy[N << 1LL];
long long tree[N << 1LL];

void pushlz(long long l,long long r,long long idx)
{
    if(lazy[idx]==LLONG_MAX) return;
    tree[idx] = (va[r+1LL]-va[l])*lazy[idx];
    if(l!=r) lazy[idx*2LL] = lazy[idx*2LL+1LL] = lazy[idx];
    lazy[idx] = LLONG_MAX;
}

void build(long long l,long long r,long long idx)
{
    lazy[idx] = LLONG_MAX;
    if(l==r) return;
    long long m = (l+r)/2LL;
    build(l,m,idx*2LL),build(m+1LL,r,idx*2LL+1LL);
}

void update(long long l,long long r,long long idx,long long x,long long y,long long k)
{
    pushlz(l,r,idx);
    if(x>=va[r+1] or y<va[l]) return;
    if(x<=va[l] and y>=va[r+1]-1)
    {
        lazy[idx] = k;
//        cout << va[l] << ' ' << va[r] << endl;
        pushlz(l,r,idx);
        return;
    }
    long long m = (l+r)/2LL;
    update(l,m,idx*2LL,x,y,k),update(m+1LL,r,idx*2LL+1LL,x,y,k);
    tree[idx] = tree[idx*2LL]+tree[idx*2LL+1LL];
}   

long long read(long long l,long long r,long long idx,long long x,long long y)
{
    pushlz(l,r,idx);
    if(x>=va[r+1] or y<va[l]) return 0;
    if(x<=va[l] and y>=va[r+1]-1) return tree[idx];
    if(l==r){ x = max(x,va[l]),y = min(va[r+1]-1LL,y); return (y-x+1LL)*(tree[idx]/(va[r+1]-va[l])); }
    long long m = (l+r)/2LL;
    return read(l,m,idx*2LL,x,y)+read(m+1LL,r,idx*2LL+1LL,x,y);
}

void print(int l,int r,int idx)
{
    pushlz(l,r,idx);
    cout << va[l] <<  ' ' << va[r+1]-1 << ' ' << tree[idx] << endl;
    if(l==r) return;
    int m = (l+r)/2;
    print(l,m,idx*2),print(m+1,r,idx*2+1);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> l >> m;

    for(long long i = 0;i < m;i++)
    {
        long long t;
        cin >> t;
        if(t==0)
        {
            long long a,b,d;
            cin >> a >> b >> d;
            b--;
            inp[i] = {t,a,b,d};
            s.insert(a),s.insert(b+1LL);
        }
        else
        {
            long long a,b;
            cin >> a >> b;
            b--;
            inp[i] = {t,a,b,0};
        }
    }
    
    s.insert(0),s.insert(l);
    for(long long x : s){ va[idx] = x,idx++; }
    n = s.size();

    build(0,n-2LL,1LL);
//print(0,**n-2,1LL);
    for(long long i = 0;i < m;i++)
    {
        long long t,a,b,d; tie(t,a,b,d) = inp[i];
        //a = id[a],b = id[b];
        if(t==0) update(0,n-2LL,1LL,a,b,d);
        else cout << read(0,n-2LL,1LL,a,b) << '\n';
  //      print(0,n-2,1);
//        cout << endl;
    }
}
