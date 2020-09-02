#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 2;

struct node
{
    int sz,val,prio,lazy;
    node *l,*r;
};

using pnode = node*;

int sz(pnode t){ if(!t) return 0; return t->sz; }
void upd(pnode t){ if(!t) return; t->sz = sz(t->l)+sz(t->r)+1; } 

void push(pnode t)
{
    if(!t) return;
    if(!t->lazy) return;
    t->val+=t->lazy;
    if(t->l) t->l->lazy+=t->lazy;
    if(t->r) t->r->lazy+=t->lazy;
    t->lazy = 0;
}

void split(pnode t,pnode &l,pnode &r,int k)
{
    push(t);
    if(!t) return void(l = r = NULL);
    if(k<=sz(t->l)) split(t->l,l,t->l,k),r = t;
    else split(t->r,t->r,r,k-sz(t->l)-1),l = t;
    upd(t);
}

void merge(pnode &t,pnode l,pnode r)
{
    push(l),push(r);
    if(!l) return void(t = r);
    if(!r) return void(t = l);
    if(l->prio>r->prio) merge(l->r,l->r,r),t = l;
    else merge(r->l,l,r->l),t = r;
    upd(t);
}

pnode init(int val)
{
    pnode res = new node;
    *res = {1,val,rand(),0,NULL,NULL};
    return res;
}

int find(pnode t,int k)
{
    push(t);
    if(!t) return 0;
    if(t->val<k) return sz(t->l)+1+find(t->r,k);
    else return find(t->l,k);
}

int mx(pnode t)
{
    push(t);
    if(!t) return 0;
    if(!t->r) return t->val;
    else return mx(t->r);
}

int mn(pnode t)
{
    push(t);
    if(!t) return 0;
    if(!t->l) return t->val;
    else return mn(t->l);
}

void print(pnode t)
{
    if(!t) return;
    print(t->l);
    cout << t->val << ' ';
    print(t->r);
}

pnode treap;

int n,m;
int a[N];

int main()
{
    srand(time(NULL));
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> m;
    for(int i = 1;i <= n;i++) cin >> a[i];
    sort(a+1,a+n+1);
    for(int i = 1;i <= n;i++) merge(treap,treap,init(a[i]));
    while(m--)
    {
        char c;
        int x,y;
        cin >> c >> x >> y;
        if(c=='F')
        {
            int id = find(treap,y);
            pnode t1,t2,t3;
            split(treap,t1,t2,id);
            split(t2,t2,t3,x);
            if(t2) t2->lazy++;
            if(mx(t2)>mn(t3))
            {
                int mmx = mx(t2);
                int tmp = find(t2,mmx);
                pnode tx,ty;
                split(t2,tx,ty,tmp);
                int tmm = find(t3,mmx);
                pnode ta,tb;
                split(t3,ta,tb,tmm);
                merge(treap,t1,tx);
                merge(treap,treap,ta);
                merge(treap,treap,ty);
                merge(treap,treap,tb);
            }
            else
            {
                merge(treap,t1,t2);
                merge(treap,treap,t3);
            }
        }
        else
        {
            int l = find(treap,x);
            int r = find(treap,y+1);
            cout << r-l << '\n';
        }
    }
}
