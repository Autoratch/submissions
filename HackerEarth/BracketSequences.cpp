#include <bits/stdc++.h>
using namespace std;

const int N = 1 << 19;

string s;
int n,a[N],ans;
struct node
{
    int val;
    friend node operator+(const node &a,const node &b){ if(a.val<b.val) return a; return b; }
}tree[N << 1];

void build(int l,int r,int idx)
{
    if(l==r) return void(tree[idx] = {a[l]});
    int m = (l+r)/2;
    build(l,m,idx*2),build(m+1,r,idx*2+1);
    tree[idx] = tree[idx*2]+tree[idx*2+1];
}

node read(int l,int r,int idx,int x,int y)
{
    if(x>r or y<l) return {INT_MAX};
    if(x<=l and y>=r) return tree[idx];
    int m = (l+r)/2;
    return read(l,m,idx*2,x,y)+read(m+1,r,idx*2+1,x,y);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> s;
    n = s.length();
    int now = 0,id = 0;
    for(char c : s)
    {
        if(c=='(') now++;
        else now--;
        a[++id] = now;
    }
    if(now!=0){ cout << "0"; return 0; }
    build(1,n,1);
    for(int i = 1;i <= n;i++)
    {
        int l = read(1,n,1,i,n).val,r = read(1,n,1,1,i-1).val;
        if(l>=a[i-1] and r+a[n]-a[i-1]>=0) ans++;
    }
    cout << ans;
}
