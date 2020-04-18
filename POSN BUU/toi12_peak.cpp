#include <bits/stdc++.h>
using namespace std;

const int N = 5e6;

int n,k,a[N],lst;
priority_queue<int> q;
vector<int> ans;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> k;

    for(int i = 0;i < n;i++) cin >> a[i];

    for(int i = 0;i < n;i++)
    {
        bool f = true;
        if(i>0 and a[i]<=a[i-1]) f = false;
        if(i<n-1 and a[i]<=a[i+1]) f = false;
        if(f) q.push(a[i]);
    }

    if(q.empty()){ cout << "-1"; return 0; }

    for(int i = 0;i < k;i++)
    {
        while(!q.empty() and q.top()==lst) q.pop();
        if(q.empty()) break;
        ans.push_back(q.top());
        lst = ans.back();
        q.pop();
    }

    if(ans.size()==k){ for(int x : ans) cout << x << '\n'; }
    else{ for(int i = ans.size()-1;i >= 0;i--) cout << ans[i] << '\n'; }
}
