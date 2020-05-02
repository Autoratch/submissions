#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 1;

int n,ans,res,full;
bool pr[N];
long long tmpp;
vector<int> prime;
map<long long,long long> ma,all;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n;
    for(int i = 2;i < N;i++) pr[i] = true;
    for(int i = 2;i < N;i++) if(pr[i])
    {
        prime.push_back(i);
        for(int j = 2;j*i < N;j++) pr[i*j] = false;
    }
    for(int i = 1;i <= n;i++)
    {
        long long x,xx;
        cin >> x; xx = x;
        long long tmp = 1,alll = 1;
        for(int y : prime) 
        {
            tmpp = y;
            int cn = 0;
            while(x%tmpp==0) x/=tmpp,cn++;
            cn%=3;
            if(cn)
            {
                alll*=tmpp*tmpp*tmpp;
                if(cn==2) tmp*=tmpp*tmpp;
                else tmp*=tmpp;
            }
            if(x==1) break;
        }
        if(x>1){ ans++; continue; }
        if(tmp==1){ full = true; continue; }
        ma[tmp]++,all[tmp] = alll;
    }
    for(auto it : ma)
    {
        if(it.second==ma[all[it.first]/it.first] and it.first>all[it.first]/it.first) res+=it.second;
        else if(it.second>ma[all[it.first]/it.first]) ans+=it.second;
    }
    cout << ans+res+full;
}
