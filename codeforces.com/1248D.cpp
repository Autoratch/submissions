#include <bits/stdc++.h>
using namespace std;

const int N = 1 << 19;

int n;
string s;
int a[N];
vector<int> op,cl;
int ans;
int pre[N],suf[N];

struct node
{
    int val;
    friend node operator+(const node &a,const node &b)
    {
        if(a.val<b.val) return a;
        else return b;
    }
}tree[N << 1];

void build(int l,int r,int idx)
{
    if(l==r){ tree[idx] = {a[l]}; return ; }
    int m = (l+r)/2;
    build(l,m,idx*2),build(m+1,r,idx*2+1);
    tree[idx] = tree[idx*2]+tree[idx*2+1];
}

node read(int l,int r,int idx,int x,int y)
{
    if(x>y) return {INT_MAX};
    if(x>r or y<l) return {INT_MAX};
    if(x<=l and y>=r) return tree[idx];
    int m = (l+r)/2;
    return read(l,m,idx*2,x,y)+read(m+1,r,idx*2+1,x,y);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> s;

    for(int i = 1;i <= n;i++)
    {
        if(i) a[i] = a[i-1];
        if(s[i-1]=='(') a[i]++;
        else a[i]--;
    }

    if(a[s.length()]!=0){ cout << "0\n1 1"; return 0; }

    int xl,yl,ans = -1;

    for(int x = 0;x < n;x++) for(int y = 0;y < n;y++)
    {
        string t = s;
        swap(t[x],t[y]);
        for(int i = 1;i <= n;i++)
        {
            a[i] = a[i-1];
            if(t[i-1]=='(') a[i]++;
            else a[i]--;
        }
        int each = 0;
        pre[0] = INT_MAX;
        suf[n+1] = INT_MAX;
        for(int i = 1;i <= n;i++) pre[i] = min(a[i],pre[i-1]);
        for(int i = n;i >= 1;i--) suf[i] = min(a[i],suf[i+1]);
        for(int i = 1;i <= n;i++)
        {
            int stb = i+1;
            if(a[i]<=suf[stb] and pre[i]>=-a[n]+a[i]) each++;
        }
        if(each>ans){ ans = each,xl = x,yl = y; }
    }

    cout << ans << '\n' << xl+1 << ' ' << yl+1;
}
