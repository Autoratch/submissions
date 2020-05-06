#include <bits/stdc++.h>
using namespace std;

struct node
{
    int sz,val,prio;
    bool rev;
    node *l,*r;
};

using pnode = node*;

int sz(pnode t){ if(!t) return 0; return t->sz; }

void upd(pnode t){ if(!t) return; t->sz = sz(t->l)+sz(t->r)+1; }

void push(pnode t)
{
    if(!t) return;
    if(!t->rev) return;
    swap(t->l,t->r);
    t->rev = false;
    if(t->l) t->l->rev^=true;
    if(t->r) t->r->rev^=true;
    upd(t);
}

void split(pnode t,pnode &l,pnode &r,int key)
{
    if(!t) return void(l = r = NULL);
    push(t);
    if(sz(t->l)>=key) split(t->l,l,t->l,key),r = t;
    else split(t->r,t->r,r,key-1-sz(t->l)),l = t;
    upd(t);
}

void merge(pnode &t,pnode l,pnode r)
{
    if(!l) return void(t = r);
    if(!r) return void(t = l);
    push(l),push(r);
    if(l->prio>r->prio) merge(l->r,l->r,r),t = l;
    else merge(r->l,l,r->l),t = r;
    upd(t);
}

void insert(pnode &t,pnode it,int idx)
{
    pnode t1,t2;
    split(t,t1,t2,idx-1);
    merge(t1,t1,it);
    merge(t,t1,t2);
    upd(t);
}

void reverse(pnode &t,int l,int r)
{
    pnode t1,t2,t3;
    split(t,t1,t2,l-1);
    split(t2,t2,t3,r-l+1);
    t2->rev^=true;
    merge(t,t1,t2);
    merge(t,t,t3);
    upd(t);
}

pnode init(int val)
{
    pnode res = new node;
    *res = {1,val,rand(),false,NULL,NULL};
    return res;
}

int first(pnode t)
{
    push(t);
    if(!t->l) return t->val;
    return first(t->l);
}

pnode treap;

const int N = 3e5 + 1;

int n,a[N];

int main()
{
    srand(time(NULL));
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n;
    for(int i = 1;i <= n;i++) cin >> a[i];
    for(int i = 1;i <= n;i++) insert(treap,init(a[i]),i);
    for(int i = 0;;i++)
    {
        int tmp = first(treap);
        if(tmp==1){ cout << i; return 0; }
        reverse(treap,1,tmp);
    }
}
