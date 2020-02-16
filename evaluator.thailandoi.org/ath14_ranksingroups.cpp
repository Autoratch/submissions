#include <bits/stdc++.h>
using namespace std;

struct node
{
    int sz,val,prio;
    node *l,*r;
};

using pnode = node*;

int sz(pnode t){ if(!t) return 0; return t->sz; }
void upd(pnode t){ if(!t) return; t->sz = sz(t->l)+sz(t->r)+1; }

void split(pnode t,pnode &l,pnode &r,int key)
{
    if(!t) return void(l = r = NULL);
    if(t->val>key) split(t->l,l,t->l,key),r = t;
    else split(t->r,t->r,r,key),l = t;
    upd(t);
}

void merge(pnode &t,pnode l,pnode r)
{
    if(!l) return void(t = r);
    if(!r) return void(t = l);
    if(l->prio>r->prio) merge(l->r,l->r,r),t = l;
    else merge(r->l,l,r->l),t = r;
    upd(t);
}

void insert(pnode &t,pnode it)
{
    if(!t) return void(t = it);
    if(it->prio>t->prio) split(t,it->l,it->r,it->val),t = it;
    else if(it->val>t->val) insert(t->r,it);
    else insert(t->l,it);
    upd(t);
}

pnode init(int val)
{
    pnode res = new node;
    *res = {1,val,rand(),NULL,NULL};
    return res;
}

const int N = 1e5 + 1;

int t,n,q;
pnode treap[N];
int pa[N],sze[N];
queue<int> qu;

void read(pnode t)
{
    if(!t) return;
    qu.push(t->val);
    read(t->l),read(t->r);
}

int ranks(pnode t,int x)
{
    if(t->val==x) return sz(t->r);
    else if(x>t->val) return ranks(t->r,x);
    else return ranks(t->l,x)+1+sz(t->r);
}

int root(int x){ if(pa[x]==x) return x; return pa[x] = root(pa[x]); }

int main()
{
    srand(time(NULL));
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> t;
    while(t--)
    {
        cin >> n >> q;
        for(int i = 1;i <= n;i++) sze[i] = 1,pa[i] = i,treap[i] = init(i);
        while(q--)
        {
            int k;
            cin >> k;
            if(k==1)
            {
                int x,y,xx,yy;
                cin >> x >> y;
                xx = x,yy = y;
                if(sze[x]<sze[y]) swap(x,y);
                read(treap[y]);
                while(!qu.empty()){ int a = qu.front(); qu.pop(); insert(treap[x],init(a)); }
                treap[xx] = treap[x];
                sze[xx]+=sze[yy];
                pa[yy] = xx;
                sze[yy] = 0;
                treap[yy] = NULL;
            }
            else
            {
                int x;
                cin >> x;
                cout << ranks(treap[root(x)],x)+1 << '\n';
            }
        }
    }
}
