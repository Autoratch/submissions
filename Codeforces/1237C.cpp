#include <bits/stdc++.h>
using namespace std;

int n;
map<pair<int,int>,vector<pair<int,int> > > m;
map<int,vector<pair<pair<int,int>,int> > > l;
//vector<pair<int,int> > v,w;
//vector<pair<pair<int,int>,int> > r,t;
vector<int> ans;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n;

    for(int i = 0;i < n;i++)
    {
        int x,y,z;
        cin >> x >> y >> z;
        m[{x,y}].push_back({z,i+1});
    }

    for(auto it = m.begin();it != m.end();it++) sort(it->second.begin(),it->second.end());

    for(auto it = m.begin();it != m.end();it++)
    {
//        pair<int,int> x = it->first;
        for(int i = 0;i < it->second.size();i++) 
        {
            if(i==0 and it->second.size()%2==1) continue;
            pair<int,int> x = it->second[i];
            ans.push_back(x.second);
        }
        pair<int,int> x = it->second[0];
        bool t = it->second.size()%2;
        it->second.clear();
        if(t) it->second.push_back(x);
    }
    for(auto it = m.begin();it != m.end();it++)
    {
        for(int i = 0;i < it->second.size();i++)
        {
            int a = it->first.first,b = it->first.second,c = it->second[i].first,id = it->second[i].second;
            l[a].push_back({{b,c},id});
        }
    }
    for(auto it = l.begin();it != l.end();it++)
    {
        for(int i = 0;i < it->second.size();i++)
        {
            if(i==0 and it->second.size()%2==1) continue;
            ans.push_back(it->second[i].second);
        }
        pair<pair<int,int>,int> x = it->second[0];
        bool t = it->second.size()%2;
        it->second.clear();
        if(t) it->second.push_back(x);
    }

    auto it = l.end();
    if(l.size())
    {
    it--;
    for(;;it--)
    {
//cout << "ok";
//return 0;
        for(pair<pair<int,int>,int> x : it->second) ans.push_back(x.second);
        if(it==l.begin()) break;
    }
    }
    for(int i = 0;i < ans.size();i+=2) cout << ans[i] << ' ' << ans[i+1] << '\n';
}
