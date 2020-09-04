#include <bits/stdc++.h>
using namespace std;
 
struct node
{
	int sz;
	long long val;
	int prio,id,mx;
	node *l,*r;
};
 
using pnode = node*;
 
int sz(pnode t){ if(!t) return 0; return t->sz; }
int id(pnode t){ if(!t) return 0; return t->id; }
int mx(pnode t){ if(!t) return 0; return t->mx; }
void upd(pnode t)
{ 
	if(!t) return; 
	t->sz = sz(t->l)+1+sz(t->r);
	t->mx = max(mx(t->l),mx(t->r));
	t->mx = max(t->mx,t->id);
}
 
void split(pnode t,pnode &l,pnode &r,int k)
{
	if(!t) return void(l = r = NULL);
	if(k<=sz(t->l)) split(t->l,l,t->l,k),r = t;
	else split(t->r,t->r,r,k-1-sz(t->l)),l = t;
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
 
pnode init(long long val,int mx)
{
	pnode res = new node;
	*res = {1,val,rand(),mx,mx,NULL,NULL};
	return res;
}
 
int count(pnode t,long long x)
{
	if(!t) return 0;
	if(t->val<=x) return 1+sz(t->l)+count(t->r,x);
	else return count(t->l,x);
}
 
pnode treap;
 
void insert(long long val,int mx)
{
	pnode res = init(val,mx);
	int cnt = count(treap,val);
	pnode t1,t2;
	split(treap,t1,t2,cnt);
	merge(treap,t1,res);
	merge(treap,treap,t2);
}
 
int findmx(pnode t,long long val)
{
	if(!t) return 0;
	if(t->val<=val) return max(findmx(t->r,val),max(mx(t->l),t->id));
	else return findmx(t->l,val);
}
 
void print(pnode t)
{
	if(!t) return;
	print(t->l);
	cout << t->val << ' ' << t->mx << ' ' << t->id << endl;
	print(t->r);
}
 
const int N = 5e5 + 1;
 
long long n,s[N],dp[N],mn[N];
 
int main()
{
	srand(time(NULL));
	ios_base::sync_with_stdio(0); cin.tie(0);
 
	cin >> n;
	for(int i = 1;i <= n;i++) cin >> s[i],s[i]+=s[i-1];
	for(int i = 1;i <= n;i++)
	{
		int j = findmx(treap,s[i]);
		dp[i] = dp[j]+1,mn[i] = s[i]-s[j];		
		insert(mn[i]+s[i],i);
	}
	cout << dp[n];
}
