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

void split(pnode t,pnode &l,pnode &r,int k)
{
    if(!t) return void(l = r = NULL);
    if(sz(t->l)>=k) split(t->l,l,t->l,k),r = t;
    else split(t->r,t->r,r,k-sz(t->l)-1),l = t;
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

pnode init(int val)
{
    pnode res = new node;
    *res = {1,val,rand(),NULL,NULL};
    return res;
}

int find(pnode t,int x)
{
    if(sz(t->l)+1==x) return t->val;
    else if(sz(t->l)>=x) return find(t->l,x);
    else return find(t->r,x-1-sz(t->l));
}

int n,m;
pnode treap;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    srand(time(NULL));

    cin >> n >> m;
    for(int i = 1;i <= n;i++)
    {
        int x;
        cin >> x;
        merge(treap,treap,init(x));
    }
    while(m--)
    {
        int t,a,l,b;
        cin >> t;
        if(t==1)
        {
            cin >> a >> l >> b;
            pnode t1,t2,t3;
            split(treap,t1,t2,a-1);
            split(t2,t2,t3,l);
            if(b<a)
            {
                pnode tx;
                split(t1,tx,t1,b-1);
                merge(treap,tx,t2);
                merge(treap,treap,t1);
                merge(treap,treap,t3);
            }
            else
            {
                pnode tx;
                split(t3,tx,t3,b-a-l);
                merge(treap,t1,tx);
                merge(treap,treap,t2);
                merge(treap,treap,t3);
            }
        }
        else
        {
            cin >> a;
            cout << find(treap,a) << '\n';
        }
    }
}
