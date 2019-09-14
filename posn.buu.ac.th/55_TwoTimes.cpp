#include <bits/stdc++.h>
using namespace std;

const int N = 10000;

struct node
{
    set<int> s[3];
    friend node operator+(const node &a,const node &b)
    {
        node ret;
        set<int> all;
        all.clear();
        ret.s[1].clear();
        ret.s[2].clear();
        for(int i = 1;i < 3;i++) 
        {
            for(int x : a.s[i]) all.insert(x);
            for(int x : b.s[i]) all.insert(x);
        }
        for(int x : all)
        {
            int cnt = 0;
            if(a.s[1].find(x)!=a.s[1].end()) cnt++;
            if(a.s[2].find(x)!=a.s[2].end()) cnt+=2;
            if(b.s[1].find(x)!=b.s[1].end()) cnt++;
            if(b.s[2].find(x)!=b.s[2].end()) cnt+=2;
            if(cnt==1) ret.s[1].insert(x);
            if(cnt==2) ret.s[2].insert(x);
        }
        return ret;
    }
};

int n,q;
int a[N];
node tree[N << 1];

void build(int l,int r,int idx)
{
    if(l==r){ tree[idx].s[1].insert(a[l]); return; }
    int m = (l+r)/2;
    build(l,m,idx*2),build(m+1,r,idx*2+1);
    tree[idx] = tree[idx*2]+tree[idx*2+1];
}

node read(int l,int r,int idx,int x,int y)
{
    if(x>r or y<l){ node ret; ret.s[2].clear(),ret.s[1].clear(); return ret; }
    if(x<=l and y>=r) return tree[idx];
    int m = (l+r)/2;
    return read(l,m,idx*2,x,y)+read(m+1,r,idx*2+1,x,y);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> q;

    for(int i = 1;i <= n;i++) cin >> a[i];

    build(1,n,1);
//    print(1,n,1);

    while(q--)
    {
        int a,b;
        cin >> a >> b;
        cout << read(1,n,1,a,b).s[2].size() << '\n';
    }
}
