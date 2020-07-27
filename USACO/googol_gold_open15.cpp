#include <bits/stdc++.h>
using namespace std;

int ans;
queue<int> ask;

int main()
{
    ask.push(1);
    while(!ask.empty())
    {
        int now = ask.front();
        ask.pop();
        ans = max(ans,now);
        cout << now << endl;
        int x,y;
        cin >> x >> y;
        if(x) ask.push(x);
        if(y) ask.push(y);
    }
    cout << ans;
}
