#include "interactive.h"
#include <bits/stdc++.h>
using namespace std;

const int N = 101;
const int K = 7;

int a[N],ba;
vector<int> res[K];
set<int> s[K],all;
map<int,int> ma,mb;

void findans(int id)
{
    vector<int> a,b;
    b = get_pairwise_xor(res[id]);
    res[id].push_back(1);
    a = get_pairwise_xor(res[id]);
    ma.clear(),mb.clear();
    for(int x : a) ma[x]++;
    for(int x : b) ma[x]--;
    for(auto [x,y] : ma) if(x and y) all.insert(x^ba),s[id].insert(x^ba);
}

vector<int> guess(int n)
{
    a[1] = ba = ask(1);
    for(int i = 2;i <= n;i++) for(int j = 0;j < K;j++) if(i&(1 << j)) res[j].push_back(i);
    for(int i = 0;i < K;i++) if(res[i].size()>0) findans(i);
    for(int x : all) 
    {
        int each = 0;
        for(int j = 0;j < K;j++) if(s[j].find(x)!=s[j].end()) each^=(1 << j);
        a[each] = x;
    }
    vector<int> tmp;
    for(int i = 1;i <= n;i++) tmp.push_back(a[i]);
    return tmp;
}

