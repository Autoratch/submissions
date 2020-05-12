#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

double n,m,d;
priority_queue<pair<double,int> > a;
bool used[N];
vector<int> ans;
double mx,sum,am;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> m >> d;
    for(int i = 1;i <= m;i++)
    {
        int x;
        cin >> x;
        a.push({x,i});
    }
    sum = d,am = n;
    mx = sum/am;
    while(!a.empty())
    {
        double x = a.top().first;
        int y = a.top().second;
        a.pop();
        if(y>2 and used[y-1] and used[y-2]) continue;
        if(y<m-1 and used[y+1] and used[y+2]) continue;
        if((sum+x)/(am+1)>mx) mx = (sum+x)/(am+1),sum+=x,am++,ans.push_back(y+n),used[y] = true;
        else break;
    }
    sort(ans.begin(),ans.end());
    cout << ans.size() << '\n';
    for(int x : ans) cout << x << ' ';
}
