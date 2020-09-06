#include "transfer.h"
#include <bits/stdc++.h>
using namespace std;

int n,k;
int ret[10],mxk;
vector<int> s;

vector<int> get_attachment(vector<int> source)
{
    n = source.size();
    if(n==63) k = 6;
    else k = 8;
    for(int i = 0;i < k;i++) ret[i] = 0;
    for(int i = 1;i <= n;i++) for(int j = 0;j < k;j++) if(i&(1 << j)) ret[j]^=source[i-1];
    int all = 0;
    for(int i = 0;i < k;i++) all^=ret[i];
    vector<int> tmp;
    for(int i = 0;i < k;i++) tmp.push_back(ret[i]);
    tmp.push_back(all);
    return tmp;
}

vector<int> retrieve(vector<int> data)
{
    if(data.size()>200) n = 255,k = 8;
    else n = 63,k = 6;
    int all = 0;
    for(int i = n;i < data.size();i++) all^=data[i];
    if(all)
    {
        vector<int> tmp;
        for(int i = 0;i < n;i++) tmp.push_back(data[i]);
        return tmp;
    }
    for(int i = 0;i < k;i++) ret[i] = 0;
    int idx = 0;
    for(int i = 1;i <= n;i++) for(int j = 0;j < k;j++) if(i&(1 << j)) ret[j]^=data[i-1];
    for(int i = 0;i < k;i++) if(ret[i]!=data[i+n]) idx^=(1 << i);
    if(idx) data[idx-1]^=1;
    vector<int> tmp;
    for(int i = 0;i < n;i++) tmp.push_back(data[i]);
    return tmp;
}
