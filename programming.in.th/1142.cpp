#include <bits/stdc++.h>
using namespace std;

const int N = 1 << 18;

struct node
{
    int mx;
    friend node operator+(const node &a,const node &b)
    {
        node ret;
        ret.mx = max(a.mx,b.mx);
        return ret;
    }
};

int n,k;
set<int> s;
vector<pair<int,int> > inp;
int ix[N];
node tree[N << 1];
int lazy[N << 1];

void pushlz(int l,int r,int idx)
{
    if(lazy[idx]==0) return;
    tree[idx].mx+=lazy[idx];
    if(l!=r) lazy[idx*2]+=lazy[idx],lazy[idx*2+1]+=lazy[idx];
    lazy[idx] = 0;
}

void update(int l,int r,int idx,int x,int y)
{
    pushlz(l,r,idx);
    if(x>ix[r] or y<ix[l]) return;
    if(x<=ix[l] and y>=ix[r]) 
    {
        lazy[idx]++;
        pushlz(l,r,idx);
        return;
    }
    int m = (l+r)/2;
    update(l,m,idx*2,x,y),update(m+1,r,idx*2+1,x,y);
    tree[idx] = tree[idx*2]+tree[idx*2+1];
}   

node read(int l,int r,int idx,int x,int y)
{
    pushlz(l,r,idx);
    if(x>ix[r] or y<ix[l]){ node ret; ret.mx = 0; return ret; }
    if(x<=ix[l] and y>=ix[r]) return tree[idx];
    int m = (l+r)/2;
    return read(l,m,idx*2,x,y)+read(m+1,r,idx*2+1,x,y);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> k;

    for(int i = 0;i < n;i++)
    {
        int x,y;
        cin >> x >> y;
        inp.push_back({x,y});
        s.insert(x);
        s.insert(y+1);
    }

    n = s.size();
    int ii = 0;
    for(auto it : s) ix[ii++] = it;

    for(pair<int,int> xy : inp)
    {
        int x = xy.first,y = xy.second;
        if(read(0,n-1,1,x,y).mx+1>k) cout << "no";
        else
        {
            update(0,n-1,1,x,y);
            cout << "yes";
        }
        cout << '\n';
    }
}
