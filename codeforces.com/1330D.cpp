#include <bits/stdc++.h>
using namespace std;

long long t,d,m;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> t;
    while(t--)
    {
        cin >> d >> m;
        long long cur = 1,mul = 2,ans = 0;
        for(long long i = 0;i < 30;i++)
        {
            if(i>=2) mul = (mul+(1 << (i-2)))%m;
            if(i) cur = (cur*mul)%m;
            if((1 << i)<=d)
            {
                ans = (((long long)min((long long)(1 << i),d-(1 << i)+1LL)*cur)%m+ans)%m;
            }
            else break;
        }
        cout << ans << '\n';
    }
}

