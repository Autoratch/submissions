#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 1;

int n;
int ans[N];
map<int,deque<pair<int,int> > > a; 

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n;
    for(int i = 0;i < n;i++)
    {
        int x,y;
        cin >> x >> y;
        a[x].push_back({y,i+1});
    }
    bool f = false;
    int cnt = 0;
    for(auto it : a)
    {
        deque<pair<int,int> > &y = it.second;
        sort(y.begin(),y.end());
        if(f) while(!y.empty()) ans[y.back().second] = cnt++,y.pop_back();
        else while(!y.empty()) ans[y.front().second] = cnt++,y.pop_front();
        f^=1;
    }
    for(int i = 1;i <= n;i++) cout << ans[i] << '\n';
}
