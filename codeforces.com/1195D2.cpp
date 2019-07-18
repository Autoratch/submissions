#include <bits/stdc++.h>
using namespace std;

const long long N = 100000;
const long long K = 20;
long long MOD = 998244353LL;

long long n;
string a[N];
long long cnt[K],res[K];
long long ans;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n;

    for(int i = 0;i < n;i++) cin >> a[i],cnt[a[i].length()]++;

    for(long long i = 0;i < n;i++)
    {
        reverse(a[i].begin(),a[i].end());
        for(long long j = 1;j <= 10;j++) 
        {
            if(!cnt[j]) continue;
            bool out = false;
            int idx = 19,my = 0,yo = 0;
            while(my<a[i].length())
            {
                res[idx]+=(a[i][my]-48LL)*cnt[j],my++;
                idx--;
                if(!out) idx--,yo++;
                if(yo==j) out = true;
            }
            out = false;
            idx = 18,my = 0,yo = 1;
            out = yo==j;
            while(my<a[i].length())
            {
                res[idx]+=(a[i][my]-48LL)*cnt[j],my++;
                idx--;
                if(!out) idx--,yo++;
                if(yo==j) out = true;
            }
        }
   }

    for(long long i = 0;i < 20;i++) ans = ((ans*10LL)%MOD+res[i])%MOD;

    cout << ans;
}
