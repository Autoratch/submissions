#include <bits/stdc++.h>
using namespace std;

const int N = 1e5;

int n,m;
long long ans;
map<int,set<int> > ma;
map<int,multiset<int> > mas;
int res[N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> m;
    for(int i = 0;i < n;i++) ma[0].insert(i);
    for(int i = 0;i < n-1;i++) mas[0].insert(1);
    while(m--)
    {
        int x,y;
        cin >> x >> y;
        if(res[x]==y)
        {
            auto it = mas[res[x]].begin();
            if(it!=mas[res[x]].end()) ans+=*it; 
            continue;
        }
        if(1)
        {
            auto it = ma[res[x]].lower_bound(x);
            auto itl = it,itr = it;
            int sum = 0,xx = 0;
            if(it!=ma[res[x]].begin())
            {
                itl--; xx++;
                sum = (*it)-(*itl);
                auto itx = mas[res[x]].lower_bound(sum);
                mas[res[x]].erase(itx);
            }
            itr++;
            if(itr!=ma[res[x]].end())
            {
                int each = (*itr)-(*it);
                sum+=each; xx++;
                auto itx = mas[res[x]].lower_bound(each);
                mas[res[x]].erase(itx);
            }
            if(xx==2) mas[res[x]].insert(sum);
            ma[res[x]].erase(it);
        }
        res[x] = y;
        auto itr = ma[res[x]].lower_bound(x);
        int sum = 0,xx = 0;
        if(itr!=ma[res[x]].begin())
        {
            auto itl = itr; itl--;
            sum+=x-(*itl);
            xx++;
            mas[res[x]].insert(sum);
        }
        if(itr!=ma[res[x]].end())
        {
            sum+=(*itr)-x;
            int each = (*itr)-x;
            xx++;
            mas[res[x]].insert(each);
        }
        if(xx==2)
        {
            auto it = mas[res[x]].lower_bound(sum);
            mas[res[x]].erase(it);
        }
        ma[res[x]].insert(x);
        auto it = mas[res[x]].begin();
        if(it!=mas[res[x]].end()) ans+=*it;
    }
    cout << ans;
}
