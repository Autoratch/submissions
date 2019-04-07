#include <bits/stdc++.h>
using namespace std;
#define l first
#define r second

const int N = 1e5;

int n;
double x0,x1;
double m[N],c[N];
pair<double,double> a[N];
double res[N];
double tmm[N];

int solve(int l,int r)
{
    if(l==r) return 0;
    int m = (l+r)/2;
    int tmp = 0;
    tmp = solve(l,m)+solve(m+1,r);
    int i = l,j = m+1,k = l;
    while(i<=m and j<=r)
    {
        if(res[i]<=res[j]) tmm[k++] = res[i++];
        else 
        {
            tmm[k++] = res[j++];
            tmp+=(m+1-i);
        }
    }
    while(i<=m) tmm[k++] = res[i++];
    while(j<=r) tmm[k++] = res[j++];
    for(int i = l;i <= r;i++) res[i] = tmm[i];
    return tmp;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> x0 >> x1;

    for(int i = 0;i < n;i++)
        cin >> m[i] >> c[i];
   
    for(int i = 0;i < n;i++)
    {
        a[i].first = m[i]*x0+c[i];
        a[i].second = m[i]*x1+c[i];
    }
   
    sort(a,a+n);

    for(int i = 0;i < n;i++) res[i] = a[i].second;

    cout << solve(0,n-1);    
}