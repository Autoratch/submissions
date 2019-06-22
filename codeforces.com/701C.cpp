#include <bits/stdc++.h>
using namespace std;

int n,all;
string s;
set<char> st;
map<char,int> ma;
int ans = INT_MAX;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> s;

    for(char c : s) st.insert(c);
    all = st.size();

    int l = 0,r = 0;
    st.clear();
    st.insert(s[0]);
    ma[s[0]]++;

    while(l<n and r<n)
    {
        if(st.size()==all)
        {
            ans = min(ans,r-l+1);
            ma[s[l]]--;
            if(ma[s[l]]==0) st.erase(s[l]);
            l++;
        }
        else
        {
            r++;
            ma[s[r]]++;
            if(ma[s[r]]==1) st.insert(s[r]);
        }
    }

    cout << ans;
}
