#include <bits/stdc++.h>
using namespace std;

int n,m,k;
int a[1000001],b[1001];

int leftmost(int x){ return x*k; }

int rightmost(int x){ return x*k+k-1; }

int getl(int pos,int val)
{
    for(int i = pos;i >= leftmost(pos/k);i--) if(val<a[i]) return pos-i;
    for(int i = pos/k-1;i >= 0;i--)
    {
        if(b[i]<=val) continue;
        int j;
        for(j = rightmost(i);val >= a[j];j--);
        return pos-j;
    }
    return INT_MAX;
}

int getr(int pos,int val)
{
    for(int i = pos;i <= rightmost(pos/k);i++) if(val<a[i]) return i-pos;
    for(int i = pos/k+1;i <= k+1;i++) 
    {
        if(b[i]<=val) continue;
        int j;
        for(j = leftmost(i);val >= a[j];j++);
        return j-pos;
    }
    return INT_MAX;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> m;
    
    k = sqrt(n);

    while(m--)
    {
        int x,y;
        cin >> x >> y;
        cout << min(n,min(getl(x,y),getr(x,y))) << '\n';
        a[x] = y;
        b[x/k] = max(b[x/k],y);
    }
}
