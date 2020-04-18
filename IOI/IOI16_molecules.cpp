#include "molecules.h"
#include <bits/stdc++.h>
using namespace std;

deque<pair<long long,int> > q;
vector<pair<long long,int> > a;
long long sum,idx;

vector<int> find_subset(int x,int y,vector<int> b)
{
    for(int i = 0;i < b.size();i++) a.push_back({b[i],i});
    sort(a.begin(),a.end());
    while(true)
    {
        if(sum<x)
        {
            if(idx==a.size()) return vector<int>(0);
            q.push_back(a[idx]),sum+=a[idx].first;
            idx++;
        }
        else if(sum>y)
        {
            sum-=q.front().first;
            q.pop_front();
        }
        else
        {
            vector<int> ans;
            for(auto p : q) ans.push_back(p.second);
            return ans;
        }
    }
}

