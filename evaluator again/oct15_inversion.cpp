#include <bits/stdc++.h>
using namespace std;

const long long N = 1e5;

long long n,ans;
long long a[N];
vector<long long> tmp;

void solve(long long l,long long r)
{
    if(l==r) return;
    long long m = (l+r)/2;
    solve(l,m),solve(m+1,r);
    tmp.clear();
    long long i = l,j = m+1;
    while(i<=m)
    {
//        cout <<  l << ' ' << r << ' ' << i << ' ' << j << endl;
  //      cout << a[i] << ' ' <<  a[j] << endl;
        if(j>r) ans+=(j-(m+1)),tmp.push_back(a[i]),i++;//,cout << l << ' ' << r << ' ' << m << endl << i-1 << ' ' << j << ' ' << a[i-1] << ' ' << a[j-1] << ' ' << (j-m-1) << endl;
        else if(a[i]>a[j]) tmp.push_back(a[j]),j++;
        else 
        {
//            cout << a[i] << ' ' << a[j] << ' ' << j-(m+1) << endl;
            ans+=j-(m+1);
            tmp.push_back(a[i]),i++;
        }
    }
    long long idx = l;
    for(long long x : tmp) a[idx++] = x;
//    cout << l << ' ' << r << ' ' << m << endl;
  //  for(long long i = 0;i < n;i++) cout << a[i] << ' ';
   // cout << endl;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n;

    for(long long i = 0;i < n;i++) cin >> a[i];
    
    solve(0,n-1);

    cout << ans;
}
