#include <bits/stdc++.h>
using namespace std;

const int N = 1 << 18;

int n,m,k;
pair<pair<int,int>,int> qe[N];
vector<int> ans;

struct node
{
    int val; 
    friend node operator+(const node &a,const node &b)
    {
        if(a.val>b.val) return a;
        else return b;
    }
}tree[N << 1];
int lazy[N << 1];

void pushlz(int l,int r,int idx)
{
    if(lazy[idx]==0) return;
    tree[idx].val+=lazy[idx];
    if(l!=r) lazy[idx*2]+=lazy[idx],lazy[idx*2+1]+=lazy[idx];
    lazy[idx] = 0;
}

void update(int l,int r,int idx,int x,int y)
{
    pushlz(l,r,idx);
    if(x>r or y<l) return;
    if(x<=l and y>=r) 
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
    if(x>r or y<l) return {INT_MIN};
    if(x<=l and y>=r) return tree[idx];
    int m = (l+r)/2;
    return read(l,m,idx*2,x,y)+read(m+1,r,idx*2+1,x,y);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> m >> k;

    for(int i = 0;i < m;i++)
    {
        int a,b;
        cin >> a >> b;
        qe[i] = {{b,a},i+1};
    }

    sort(qe,qe+m);

    for(int i = 0;i < m;i++)
    {
        int r = qe[i].first.first,l = qe[i].first.second;
        if(read(1,N,1,l,r).val>=k){ ans.push_back(qe[i].second); continue; }
        update(1,N,1,l,r);
    }

    cout << ans.size() << '\n';
    for(int x : ans) cout << x << ' ';
}
