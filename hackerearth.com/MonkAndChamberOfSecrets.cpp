#include <bits/stdc++.h>
using namespace std;

const int N = 316;

int n,k;
queue<pair<int,int> > q;
vector<pair<int,int> > tmp;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> k;

    for(int i = 0;i < n;i++)
    {
        int x;
        cin >> x;
        q.push({x,i+1});
    }

    for(int i = 0;i < k;i++)
    {
        int mx = -1,idx;
        for(int j = 0;j < k and !q.empty();j++)
        {
            tmp.push_back(q.front());
            if(q.front().first>mx) mx = q.front().first,idx = q.front().second;
            q.pop();
        }
        cout << idx << ' ';
        for(pair<int,int> x : tmp) if(x.second!=idx) q.push({max(x.first-1,0),x.second});
        tmp.clear();
    }
}
