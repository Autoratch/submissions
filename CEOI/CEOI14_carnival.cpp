#include <bits/stdc++.h>
using namespace std;

const int N = 151;

int n,lst,cur,ans[N];

int ask(int l,int r,int x)
{
    cout << r-l+2 << ' ';
    for(int i = l;i <= r;i++) cout << i << ' ';
    cout << x << endl;
    int ret;
    cin >> ret;
    return ret;
}

void solve(int l,int r,int x)
{
    if(l==r) return void(ans[x] = ans[l]);
    int m = (l+r)/2;
    if(ask(l,m-1,m)==ask(l,m,x)) solve(l,m,x);
    else solve(m+1,r,x);
}

int main()
{
    cin >> n;
    for(int i = 1;i <= n;i++) 
    {
        if(ask(1,i-1,i)!=lst) ans[i] = ++cur;
        else solve(1,i-1,i);
        lst = ask(1,i-1,i);
    }
    cout << "0 ";
    for(int i = 1;i <= n;i++) cout << ans[i] << ' ';
    cout << endl;
}
