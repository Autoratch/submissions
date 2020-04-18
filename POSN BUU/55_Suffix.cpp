#include <bits/stdc++.h>
using namespace std;

const int N = 100;

int n;
string s[N];
int a[N];
pair<int,string> p[N];
int ans;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n;

    for(int i = 0;i < n;i++) cin >>  s[i],p[i] = {-s[i].length(),s[i]};

    sort(p,p+n);

    for(int i = 0;i < n;i++) a[i] = 1;

    for(int i = 0;i < n;i++) s[i] = p[i].second;//cout << s[i] << endl;

    for(int i = 0;i < n;i++){ for(int j = 0;j < i;j++)
    {
        if(s[j].length()-s[i].length()>1) continue;
        if(s[i].length()==s[j].length())
        {
            if(s[i].substr(1,s[i].length()-1)==s[j].substr(1,s[j].length()-1)) a[i] = max(a[i],a[j]+1);
        }
        else
        {
            if(s[j].substr(1,s[j].length()-1)==s[i]) a[i] = max(a[i],a[j]+1);
        }
        ans = max(ans,a[i]);
    }
/*    cout << a[i] << ' ';*/ }

    cout << ans;
}
