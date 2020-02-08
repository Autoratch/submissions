#include <bits/stdc++.h>
using namespace std;

const int N = 1001;

int m,n;
long long a[N][N],h[N][N],ans;
stack<pair<long long,long long> > s;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> m >> n;
    for(int i = 1;i <= m;i++) for(int j = 1;j <= n;j++)
    {   
        cin >> a[i][j];
        if(a[i][j]==a[i-1][j]) h[i][j] = h[i-1][j]+1;
        else h[i][j] = 1;
    }
    for(int i = 1;i <= m;i++)
    {
        long long sum = 0;
        for(int j = 1;j <= n;j++) 
        {
            long long cnt = 1;
            if(a[i][j]!=a[i][j-1]){ while(!s.empty()) s.pop(); sum = 0; }
            else while(!s.empty() and s.top().first>h[i][j]) cnt+=s.top().second,sum-=s.top().first*s.top().second,s.pop();
            s.push({h[i][j],cnt});
            sum+=(long long)(h[i][j])*cnt;
            ans+=sum;
        }
        while(!s.empty()) s.pop();
    }
    cout << ans;
}
