#include <bits/stdc++.h>
using namespace std;

const long long N = 1e5 + 1;

long long n,m;
long long a[N],c[N];
priority_queue<pair<long long,long long>,vector<pair<long long,long long> >,greater<pair<long long,long long> > > q;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> m;

    for(long long i = 0;i < n;i++) cin >> a[i];
    for(long long i = 0;i < n;i++) cin >> c[i];
    for(long long i = 0;i < n;i++)
    {
        q.push({c[i],i});
    }

    for(long long i = 0;i < m;i++)
    {
        long long x,am;
        cin >> x >> am;
        x--;
        if(a[x]>=am)
        {
            cout << c[x]*am << '\n';
            a[x]-=am;
        }
        else
        {
            long long tmp = 0;
            tmp+=c[x]*a[x];
            am-=a[x];
            a[x] = 0;
            while(am and !q.empty())
            {
                long long idx = q.top().second;
                if(a[idx]>am)
                {
                    a[idx]-=am;
                    tmp+=c[idx]*am;
                    am = 0;
                    break;
                }
                else
                {
                    am-=a[idx];
                    tmp+=c[idx]*a[idx];
                    a[idx] = 0;
                    q.pop();
                }
            }
            if(am!=0) cout << "0\n";
            else cout << tmp << '\n';
        }
    }
}
