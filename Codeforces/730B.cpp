#include <bits/stdc++.h>
using namespace std;

int t,n;
vector<int> a,b;

int main()
{
    cin >> t;
    while(t--)
    {
        cin >> n;
        a.clear(),b.clear();
        for(int i = 1;i <= n;i+=2)
        {
            if(i+1<=n)
            {
                cout << "? " << i << ' ' << i+1 << endl;
                char c;
                cin >> c;
                if(c=='>' or c=='=') a.push_back(i),b.push_back(i+1);
                else a.push_back(i+1),b.push_back(i);
            }
            else a.push_back(i),b.push_back(i);
        }
        int mx = a[0],mn = b[0];
        for(int i = 1;i < a.size();i++)
        {
            cout << "? " << mx << ' ' << a[i] << endl;
            char c;
            cin >> c;
            if(c=='<') mx = a[i];
        }
        for(int i = 1;i < b.size();i++)
        {
            cout << "? " << mn << ' ' << b[i] << endl;
            char c;
            cin >> c;
            if(c=='>') mn = b[i];
        }
        cout << "! " << mn << ' ' << mx << endl;
    }
}
