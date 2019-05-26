#include <bits/stdc++.h>
using namespace std;

const int N = 2e5;

int n,a[N],x[N],lst,ans;
stack<pair<int,int> > s;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n;
    
    for(int i = 0;i < n;i++) cin >> a[i];

    for(int i = 0;i < n;i++)
    {
        if(a[i]>0) s.push({a[i],i});
        else 
        {
            if(!s.empty() and s.top().first==-a[i]) x[i] = i-s.top().second+1+x[max(0,s.top().second-1)],ans = max(ans,x[i]),s.pop();
            else while(!s.empty()) s.pop();
        }
    }

    cout << ans;
}
