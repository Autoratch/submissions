#include <bits/stdc++.h>
using namespace std;

struct node
{
    int sz,prio;
    char val;
    bool rev;
    node *l,*r;
};

using pnode = node*;

int sz(pnode t){ if(!t) return 0; return t->sz; }
void upd(pnode t){ if(!t) return; t->sz = sz(t->l)+sz(t->r)+1; }

void push(pnode t)
{
    if(!t or !t->rev) return;
    t->rev = false;
    swap(t->l,t->r);
    if(t->l) t->l->rev^=true;
    if(t->r) t->r->rev^=true;
}

void split(pnode t,pnode &l,pnode &r,int key)
{
    if(!t) return void(l = r = NULL);
    push(t);
    if(key<=sz(t->l)) split(t->l,l,t->l,key),r = t;
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

void insert(pnode &t,pnode it,int key)
{
    pnode t1,t2;
    split(t,t1,t2,key);
    merge(t,t1,it);
    merge(t,t,t2);
}

void reverse(pnode &t,int x,int y)
{
    pnode t1,t2,t3;
    split(t,t1,t2,x-1);
    split(t2,t2,t3,y-x+1);
    t2->rev^=true;
    merge(t,t1,t2);
    merge(t,t,t3);
}

void print(pnode t)
{
    if(!t) return;
    push(t);
    print(t->l);
    cout << t->val;
    print(t->r);
}

pnode init(char c)
{
    pnode res = new node;
    *res = {1,rand(),c,false,NULL,NULL};
    return res;
}

pnode treap;
string s;
int q;

int main()
{
    srand(time(NULL));
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> s >> q;
    for(char c : s) merge(treap,treap,init(c));
    while(q--)
    {
        char c;
        cin >> c;
        if(c=='R'){ int x,y; cin >> x >> y; reverse(treap,x,y); }
        else
        {
            int x;
            string s;
            cin >> x >> s;
            for(char c : s) insert(treap,init(c),x++);
        }
    }    
    print(treap);
}