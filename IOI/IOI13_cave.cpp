#include "cave.h"
#include <bits/stdc++.h>
using namespace std;

const int N = 5000;

int a[N],sold[N],cnt[N],sol[N];
bool kn[N];
vector<int> s;

void exploreCave(int n)
{
    for(int i = 0;i < n;i++)
    {
        s.clear();
        for(int j = 0;j < n;j++) if(kn[j]) a[j] = sol[j]; else s.push_back(j),a[j] = 1;
        int tmp = tryCombination(a);
        if(tmp==-1) tmp = INT_MAX;
        if(tmp>i) sold[i] = 1;
        else sold[i] = 0;
        int l = 0,r = s.size()-1;
        while(l<r)
        {
            int m = (l+r)/2;
            for(int j = l;j <= m;j++) if(!kn[s[j]]) a[s[j]] = sold[i];
            for(int j = m+1;j <= r;j++) if(!kn[s[j]]) a[s[j]] = 1-sold[i];
            int tmp = tryCombination(a);
            if(tmp==-1) tmp = INT_MAX;
            if(tmp>i) r = m;
            else l = m+1;
        }
        cnt[s[l]] = i;
        sol[s[l]] = sold[i];
        kn[s[l]] = true;
    }
    answer(sol,cnt);
}
