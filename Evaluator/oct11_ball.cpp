#include <bits/stdc++.h>
using namespace std;

int n;
set<int> s,t;
vector<int> a;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n;

    for(int i = 0;i < n;i++)
    {
        t.clear();
        int x;
        cin >> x;
        auto tm = s.begin();
        if(i and *tm==0)
        {
            for(auto it = s.begin();it != s.end();)
            {
                t.insert(x);
                if(*it>x) break;
                x++;
                it = s.erase(it);
            }
            for(auto it = t.begin();it != t.end();it++) s.insert(*it);
        }
        else
        {
            bool f = false;
            for(auto it = s.begin();it != s.end();)
            {
                if(*it>x)
                {
                    t.insert(x);
                    f = true;
                    break;
                }
                else if(*it==x)
                {
                    t.insert(x-1);
                    f = true;
                    break;
                }
                t.insert(*it-1);
                it = s.erase(it);
                x--;
            }
            if(!f) s.insert(x);
            for(auto it = t.begin();it != t.end();it++) s.insert(*it);
        }

//        for(auto it = s.begin();it != s.end();it++) cout << *it << ' ';
  //      cout << endl;
    }

    for(auto it = s.begin();it != s.end();it++) a.push_back(*it);

    for(int i = a.size()-1;i >= 0;i--) cout << a[i] << '\n';
}
