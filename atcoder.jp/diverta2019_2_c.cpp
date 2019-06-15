#include <bits/stdc++.h>
using namespace std;

const int N = 1e5;

int n,a[N];
vector<int> pos,neg;
int z;
vector<pair<int,int> > ans;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n;

    for(int i = 0;i < n;i++) cin >> a[i];

    for(int i = 0;i < n;i++) if(a[i]<0) neg.push_back(a[i]); else if(a[i]>0) pos.push_back(a[i]); else z++;

    if(z==n)
    {
        cout << "0\n";
        n--;
        while(n--) cout << "0 0\n";
        return 0;
    }

    if(pos.size() and neg.size())
    {
        int po = pos[0],ne = neg[0];
        for(int i = 1;i < pos.size();i++) ans.push_back({ne,pos[i]}),ne-=pos[i];
        for(int i = 1;i < neg.size();i++) ans.push_back({po,neg[i]}),po-=neg[i];
        ans.push_back({po,ne});
        cout << po-ne << '\n';
        for(pair<int,int> x : ans) cout << x.first << ' ' << x.second << '\n';
        while(z--) cout << po-ne << " 0\n";
        return 0;
    }
    else
    {
        if(z)
        {
            if(pos.size()==1 or neg.size()==1)
            {
                int now;
                if(pos.size()) cout << pos[0] << '\n',now = pos[0];
                else cout << -neg[0] << '\n',now = neg[0];
                if(neg.size()) cout << "0 " << now << '\n',z--;
                now = abs(now);
                while(z--) cout << now << " 0\n";
                return 0;
            }
            if(pos.size())
            {
                ans.push_back({0,pos.back()});
                neg.push_back(-pos.back());
                pos.resize(pos.size()-1);
                z--;
            }
            else
            {
                ans.push_back({0,neg.back()});
                pos.push_back(-neg.back());
                neg.resize(neg.size()-1);
                z--;
            }
            int po = pos[0],ne = neg[0];
            for(int i = 1;i < pos.size();i++) ans.push_back({ne,pos[i]}),ne-=pos[i];
            for(int i = 1;i < neg.size();i++) ans.push_back({po,neg[i]}),po-=neg[i];
            ans.push_back({po,ne});
            cout << po-ne << '\n';
            for(pair<int,int> x : ans) cout << x.first << ' ' << x.second << '\n';
            while(z--) cout << po-ne << " 0\n";
            return 0;
        }
        else
        {
            if(pos.size())
            {
                int s = 0;
                sort(pos.begin(),pos.end());
                for(int i = 1;i < n;i++) s+=pos[i];
                s-=pos[0];
                cout << s << '\n';
                int now = pos[0]-pos[1];
                cout << pos[0] << ' ' << pos[1] << '\n';
                for(int i = 2;i < n-1;i++) cout << now << ' ' << pos[i] << '\n',now-=pos[i];
                cout << pos.back() << ' ' << now;
                return 0;
            }
            else
            {
                int s = 0;
                sort(neg.begin(),neg.end());
                reverse(neg.begin(),neg.end());
                for(int i = 1;i < n;i++) s+=neg[i];
                s-=neg[0];
                cout << -s << '\n';
                int now = neg[0]-neg[1];
                cout << neg[0] << ' ' << neg[1] << '\n';
                for(int i = 2;i < n-1;i++) cout << now << ' ' << neg[i] << '\n',now-=neg[i];
                cout << now<< ' ' << neg.back();
                return 0;   
            }
        }
    }
}
