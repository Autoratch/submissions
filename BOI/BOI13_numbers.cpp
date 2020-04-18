#include <bits/stdc++.h>
using namespace std;

string a,b;
deque<int> q;
long long tmp,resa,resb;

long long solve(int len)
{
    int fixed = 0;
    bool fix = false;
    for(int i = 0;i < q.size();i++)
    {
        if(i>0){ if(fix and q[i]==q[i-1]) return 0; }
        if(i>1){ if(fix and q[i]==q[i-2]) return 0; }
        if(!fix and q[i]) fix = true;
        if(fix) fixed++;
    }
    int lenn = len;
    len-=q.size();
    long long ret = 1;
    if(fixed==0)
    {
        for(int i = 0;i < len;i++)
        {
            if(i==0) ret*=9LL;
            else if(i==1) ret*=9LL;
            else ret*=8LL;
        }
        for(int i = 0;i < len-1;i++)
        {
            q.push_back(0);
            for(int j = 1;j <= 9;j++) q.push_back(j),ret+=solve(lenn),q.pop_back();
        }
        if(len>0) ret++;
        for(int i = 0;i < len-1;i++) q.pop_back();
    }
    else if(fixed==1) for(int i = 0;i < len;i++)
    {
        if(i==0) ret*=9LL;
        else ret*=8LL;
    }
    else for(int i = 0;i < len;i++) ret*=8LL;
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> tmp >> b; 
    tmp--;
    long long tm = tmp;
    while(tmp) a = (char)('0'+(tmp%10LL))+a,tmp/=10LL;
    if(tm>=0)
    {
    if(a.length()==0) a+='0';
    for(char c : a)
    {
        int x = c-'0';
        for(int i = 0;i < x;i++) q.push_back(i),resa+=solve(a.length()),q.pop_back();
        q.push_back(x);
    }
    resa+=solve(a.length());
    }
    while(!q.empty()) q.pop_back();
    for(char c : b)
    {
        int x = c-'0';
        for(int i = 0;i < x;i++) q.push_back(i),resb+=solve(b.length()),q.pop_back();
        q.push_back(x);
    }
    resb+=solve(b.length());
    cout << resb-resa;
}
