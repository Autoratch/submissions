#include <bits/stdc++.h>
using namespace std;

struct node
{
    int sz,val,prio,id;
    node *l,*r;
};

using pnode = node*;

int sz(pnode t){ if(!t) return 0; return t->sz; }
void upd(pnode t){ if(!t) return; t->sz = 1+sz(t->l)+sz(t->r); }

void split(pnode t,pnode &l,pnode &r,int key)
{
    if(!t) return void(l = r = NULL);
    if(key>=t->val) split(t->r,t->r,r,key-1),l = t;
    else split(t->l,l,t->l,key),r = t;
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

void erase(pnode &t,int key,int id)
{
    if(!t) return;
    if(id==t->id){ pnode tmp = t; merge(t,t->l,t->r); free(tmp); }
    else if(key>t->val) erase(t->r,key,id);
    else erase(t->l,key,id);
    upd(t);
}

pnode init(int key,int id)
{
    pnode res = new node;
    *res = {1,key,rand(),id,NULL,NULL};
    return res;
}

int count(pnode t,int key,int id)
{
    if(!t) return 0;
    if(t->val==key and t->id<id) return count(t->l,key,id)+1;
    else if(key<=t->val) return count(t->l,key,id);
    else return count(t->r,key,id);
}

void print(pnode t)
{
    if(!t) return;
    cout << t->val << ' ' << t->l->val << ' ' << t->r->val << endl;
    print(t->l),print(t->r);
}

pnode treap;
int n,q;
int res[200000];

int main()
{
    srand(time(NULL));
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> q;
    for(int i = 0;i < n;i++){ int x; cin >> x; insert(treap,init(x,i)); res[i] = x; }
    while(q--)
    {
        int x,y;
        cin >> x >> y;
        erase(treap,res[x],x);
        insert(treap,init(y,x));
        res[x] = y;
        cout << count(treap,y,x) << '\n';
    }
}
