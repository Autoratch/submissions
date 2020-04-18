#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 1;

struct node
{
    int t,w,v,d,x,id;
};

int n,m;
set<pair<int,int> > s;
unordered_map<int,int> va;
vector<node> res[N];
bool gone[N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> m;

    for(int i = 0;i < n+m;i++)
    {
        int type;
        cin >> type;
        for(int j = 0;j < res[i].size();j++)
        {
            node tmp = res[i][j];
            if(gone[tmp.id]) continue;
            s.erase(s.find({tmp.w,tmp.id}));
            if(tmp.t==3){ s.insert({tmp.x,tmp.id}); va[tmp.x] = tmp.v; }
        }
        if(type==1)
        {
            node tmp;
            tmp.id = i;
            cin >> tmp.t >> tmp.w >> tmp.v;
            s.insert({tmp.w,tmp.id});
            va[tmp.w] = tmp.v;
            if(tmp.t==1) continue;
            if(tmp.d>=n+m) continue;
            if(tmp.t==2) cin >> tmp.d;
            else cin >> tmp.d >> tmp.x;
            res[tmp.d].push_back(tmp);
        }
        else
        {
            if(s.empty()){ cout << "0\n"; continue; }
            auto it = s.begin();
            cout <<  va[it->first] << '\n';
            gone[it->second] = true;
            s.erase(it);
        }
    }
}
