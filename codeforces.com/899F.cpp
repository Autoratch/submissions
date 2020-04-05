#include <bits/stdc++.h>
using namespace std;

struct node
{
    int sz,prio;
    char val;
    node *l,*r;
};

using pnode = node*;

int sz(pnode t){ if(!t) return 0; return t->sz; }
void upd(pnode t){ if(!t) return; t->sz = sz(t->l)+1+sz(t->r); }

void split(pnode t,pnode &l,pnode &r,int key)
{
    if(!t) return void(l = r = NULL);
    if(key<=sz(t->l)) split(t->l,l,t->l,key),r = t;
    else split(t->r,t->r,r,key-1-sz(t->l)),l = t;
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
    merge(t,t,it);
    upd(t);
}

void erase(pnode &t,int key)
{
    pnode t1,t2,t3;
    split(t,t1,t2,key-1);
    split(t2,t3,t2,1);
    merge(t,t1,t2);
    upd(t);
}

pnode init(char c)
{
    pnode res = new node;
    *res = {1,rand(),c,NULL,NULL};
    return res;
}

void print(pnode t)
{
    if(!t) return;
    print(t->l);
    cout << t->val;
    print(t->r);
}

pnode treap;

const int N = 2e5 + 1;

int n,q;
string s;
vector<int> nor[26],cap[26],dig[10];
bool out[N];
int fw[N];

void update(int idx,int val){ while(idx<N) fw[idx]+=val,idx+=(idx & -idx);  }

int read(int idx){ int val = 0; while(idx>0) val+=fw[idx],idx-=(idx & -idx); return val; }

int getid(int idx)
{
    int l = 1,r = n;
    while(l<r) 
    {
        int m = (l+r)/2;
        if(read(m)>=idx) r = m;
        else l = m+1;
    }
    return l;
}

int main()
{
    srand(time(NULL));
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> q >> s;
    for(int i = 1;i <= n;i++) 
        if(s[i-1]>='A' and s[i-1]<='Z') cap[s[i-1]-'A'].push_back(i); 
        else if(s[i-1]>='a' and s[i-1]<='z') nor[s[i-1]-'a'].push_back(i); 
        else dig[s[i-1]-'0'].push_back(i);
    for(char c : s) insert(treap,init(c));
    for(int i = 1;i <= n;i++) update(i,1);
    while(q--)
    {
        int l,r;
        char c;
        cin >> l >> r >> c;
        l = getid(l),r = getid(r);
        if(c>='A' and c<='Z')
        {
            auto itl = lower_bound(cap[c-'A'].begin(),cap[c-'A'].end(),l);
            auto itr = upper_bound(cap[c-'A'].begin(),cap[c-'A'].end(),r);
            for(auto it = itl;it != itr;it++) if(!out[*it]) erase(treap,read(*it)),out[*it] = true,update(*it,-1);
        }
        else if(c>='a' and c<='z')
        {
            auto itl = lower_bound(nor[c-'a'].begin(),nor[c-'a'].end(),l);
            auto itr = upper_bound(nor[c-'a'].begin(),nor[c-'a'].end(),r);
            for(auto it = itl;it != itr;it++) if(!out[*it]) erase(treap,read(*it)),out[*it] = true,update(*it,-1);
        }
        else
        {
            auto itl = lower_bound(dig[c-'0'].begin(),dig[c-'0'].end(),l);
            auto itr = upper_bound(dig[c-'0'].begin(),dig[c-'0'].end(),r);
            for(auto it = itl;it != itr;it++) if(!out[*it]) erase(treap,read(*it)),out[*it] = true,update(*it,-1);
        }
    }
    print(treap);
}
