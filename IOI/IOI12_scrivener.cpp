#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 1;

int n = N-1,ver,cnt,root[N],len[N];
struct node{ char c; int left,right; }tree[N*20];

int clone(int x){ tree[++cnt] = tree[x]; return cnt; }

void build(int l,int r,int idx)
{
    tree[idx] = {0,idx*2,idx*2+1};
    cnt = max(cnt,idx);
    if(l==r) return;
    int m = (l+r)/2;
    build(l,m,idx*2),build(m+1,r,idx*2+1);
}

int update(int l,int r,int idx,int x,char c)
{
    int now = clone(idx);
    if(l==r)
    {
        tree[now] = {c,idx,idx};
        return now;
    }
    int m = (l+r)/2;
    if(x<=m) tree[now].left = update(l,m,tree[now].left,x,c);
    else tree[now].right = update(m+1,r,tree[now].right,x,c);
    return now;
}

char read(int l,int r,int idx,int x)
{
    if(l==r) return tree[idx].c;
    int m = (l+r)/2;
    if(x<=m) return read(l,m,tree[idx].left,x);
    else return read(m+1,r,tree[idx].right,x);
}

void Init(){ build(1,n,1),root[0] = 1; }

void TypeLetter(char c){ root[ver+1] = update(1,n,root[ver],len[ver]+1,c),len[ver+1] = len[ver]+1,ver++; }

void UndoCommands(int u){ root[ver+1] = root[ver-u],len[ver+1] = len[ver-u],ver++; }

char GetLetter(int x){ return read(1,n,root[ver],x+1); }
