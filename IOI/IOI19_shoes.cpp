#include "shoes.h"
#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 1;
const int HSH = 1e5;

int n;
queue<int> q[N];
int fw[N];

void update(int idx,int val){ while(idx<N) fw[idx]+=val,idx+=(idx & -idx); }

int read(int idx){ int val = 0; while(idx>0) val+=fw[idx],idx-=(idx & -idx); return val; }

long long count_swaps(vector<int> s)
{
    long long ans = 0;
    n = s.size();
    for(int i = 0;i < n;i++) q[s[i]+HSH].push(i+1),update(i+1,1);
    for(int i = 1;i <= n;i++)
    {
        int x = s[i-1];
        if(read(i)-read(i-1)==0) continue;
        int y = -x,t = q[y+HSH].front();
        q[x+HSH].pop();
        q[y+HSH].pop();
        ans+=read(t-1)-read(i);
        if(x>y) ans++;
        update(t,-1);
    }
    return ans;
}
