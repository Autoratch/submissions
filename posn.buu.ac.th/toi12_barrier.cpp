#include <bits/stdc++.h>
using namespace std;

const int N = 6e6;

int n,k;
deque<pair<long long,int> > q;
long long cur,s,ans;
int len;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> k;

    for(int i = 0;i < n;i++) 
    {
        cin >> cur;
        s+=cur;
        while(!q.empty() and q.front().second<i-k) q.pop_front();
        if(!q.empty())
        {
            if(s-q.front().first>ans) ans = s-q.front().first,len = i-q.front().second;
            else if(s-q.front().first==ans) len = min(len,i-q.front().second);
        }
        else
        {
            if(s>ans) ans = s,len = i+1;
            else if(s==ans) len = min(len,i+1);
        }
        while(!q.empty() and q.back().first>=s) q.pop_back();
        q.push_back({s,i});
    }

    cout << ans << '\n' << len;
}
