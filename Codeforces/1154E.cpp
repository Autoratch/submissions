#include <bits/stdc++.h>
using namespace std;

const int N = 2e5;

int n,k;
bool w;
int a[N];
set<int> s;
priority_queue<pair<int,int> > q;
int ans[N];
vector<int> add;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> k;

    for(int i = 0;i < n;i++){ cin >> a[i]; s.insert(i); q.push({a[i],i}); }

    while(!s.empty())
    {
        int id = q.top().second;
        q.pop();
        if(s.find(id)==s.end()) continue;
        auto it = s.find(id);
        add.clear();
        for(int i = 0;i <= k;i++)
        {
            add.push_back(*it);
            if(it==s.begin()) break;
            it--;
        }
        it = s.find(id);
        it++;
        for(int i = 0;i < k;i++)
        {
            if(it==s.end()) break;
            add.push_back(*it);
            it++;
        }
        for(int x : add)
        {
            s.erase(x);
            ans[x] = (int)w+1;
        }
        w = !w;
    }

    for(int i = 0;i < n;i++) cout << ans[i];
}
