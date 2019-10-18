#include <bits/stdc++.h>
using namespace std;

const long long N = 1e5 + 1;

long long m,n,k;
deque<long long> a[N],b[N];
long long ans;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> m >> n >> k;

    for(long long i = 0;i < k;i++)
    {
        long long x,y;
        cin >> x >> y;
        a[x].push_back(y);
        b[y].push_back(x);
    }

    for(long long i = 1LL;i <= m;i++) sort(a[i].begin(),a[i].end());
    for(long long i = 1LL;i <= n;i++) sort(b[i].begin(),b[i].end());

    long long xl = 1LL,xr = m,yl = 1LL,yr = n;
    long long st = 1LL;
    long long x = 1LL,y = 1LL;
    long long lstu = 1LL,lstd = m+1LL,lstl = 0,lstr = n+1LL;
    bool go = false;

    while(true)
    {   
        if(ans) ans--;
        if(st==1LL)
        {
            long long lst = n+1LL;
           while(!a[x].empty() and a[x].front()<y) a[x].pop_front();
            if(!a[x].empty()) lst = a[x].front();
            lst = min(lst,lstr);
            ans+=lst-y;
    //           cout << lst-y << endl;
            if(lst-1LL==y and go) break;
            y = lst-1LL;
            lstr = y;
            st++;
        }
        else if(st==2)
        {
            long long lst = m+1LL;
            while(!b[y].empty() and b[y].front()<x) b[y].pop_front();
            if(!b[y].empty()) lst = b[y].front();
            lst = min(lst,lstd);
            ans+=lst-x;
  //          cout << lst-x << endl;
            if(lst-1LL==x) break;
            x = lst-1LL;
            lstd = x;
            st++;
        }
        else if(st==3)
        {
            long long lst = 0;
            while(!a[x].empty() and a[x].back()>y) a[x].pop_back();
            if(!a[x].empty()) lst = a[x].back();
            lst = max(lst,lstl);
            ans+=y-lst;
//cout << y << ' ' << lst << endl;
    //        cout << y-lst << endl;
            if(lst+1LL==y) break;
            y = lst+1LL;
            lstl = y;
            st++;
        }
        else
        {
            long long lst = 0;
            while(!b[y].empty() and b[y].back()>x) b[y].pop_back();
            if(!b[y].empty()) lst = b[y].back();
            lst = max(lst,lstu);
            ans+=x-lst;
      //      cout << x-lst << endl;
            if(lst+1LL==x) break;
            x = lst+1LL;
            lstu = x;
            st = 1LL;
            go = true;
        }
    }
//cout << ans << endl;
    if(ans+k==m*n) cout << "Yes";
    else cout << "No";
}

