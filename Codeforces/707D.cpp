#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 1;

int n,m,q;
int root[N],cur,cnt;
struct node
{
    int val,lazy,left,right;
}tree[N*20];

int clone(int x){ tree[++cnt] = tree[x]; return cnt; }

void pushlz(int l,int r,int idx)
{
    if(!tree[idx].lazy) return;
    if(tree[idx].lazy==1) tree[idx].val = r-l+1;
    else if(tree[idx].lazy==2) tree[idx].val = 0;
    else tree[idx].val = r-l+1-tree[idx].val;
    if(l!=r)
    {
        int newl = clone(tree[idx].left),newr = clone(tree[idx].right);
        tree[newl].lazy = 3-tree[newl].lazy;
        tree[newr].lazy = 3-tree[newr].lazy;
        tree[idx].left = newl,tree[idx].right = newr;
    }
    tree[idx].lazy = 0;
}

void build(int l,int r,int idx)
{
    cnt = max(cnt,idx);
    tree[idx] = {0,0,idx*2,idx*2+1};
    if(l==r) return;
    int m = (l+r)/2;
    build(l,m,idx*2),build(m+1,r,idx*2+1);
}

int update(int l,int r,int idx,int t,int x,int y)
{
    pushlz(l,r,idx);
    if(x>r or y<l) return idx;
    int now = clone(idx);
    if(x<=l and y>=r)
    {
        tree[now].lazy = t;
        pushlz(l,r,now);
        return now;        
    }
    int m = (l+r)/2;
    tree[now].left = update(l,m,tree[now].left,t,x,y);
    tree[now].right = update(m+1,r,tree[now].right,t,x,y);
    tree[now].val = tree[tree[now].left].val+tree[tree[now].right].val;
    return now;
}

int read(int l,int r,int idx)
{
    pushlz(l,r,idx);
    return tree[idx].val;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> m >> q;
    build(1,n*m,1);
    root[0] = 1;
    while(q--)
    {
        int t;
        cin >> t;
        if(t==1)
        {
            int x,y;
            cin >> x >> y;
            x = (x-1)*m+y;
            root[cur+1] = update(1,n*m,root[cur],1,x,x),cur++;
        }
        else if(t==2)
        {
            int x,y;
            cin >> x >> y;
            x = (x-1)*m+y;
            root[cur+1] = update(1,n*m,root[cur],2,x,x),cur++;
        }
        else if(t==3)
        {
            int x;
            cin >> x;
            x = (x-1)*m+1;
            int y = x+m-1;
            root[cur+1] = update(1,n*m,root[cur],3,x,y),cur++;
        }
        else
        {
            int x;
            cin >> x;
            root[cur+1] = root[x],cur++;
        }
        cout << read(1,n*m,root[cur]) << '\n';
    }
}