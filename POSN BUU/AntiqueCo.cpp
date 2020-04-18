#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 1;
const int K = 317;

struct node
{
    int l,r,num;
    friend bool operator<(const node &a,const node &b){ return a.r<b.r; }
};

int n,k,q;
vector<node> block[K+1];
int ans[N],res[N],a[N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> k >> q;

    for(int i = 0;i < n;i++) cin >> a[i];
    for(int i = 1;i <= q;i++)
    {
        int a,b;
        cin >> a >> b;
        a--,b--;
        block[a/K].push_back({a,b,i});
    }

    for(int i = 0;i < K;i++)
    {
        if(block[i].size()==0) continue;
        sort(block[i].begin(),block[i].end());
        int l,r,cnt = 0;
        for(int j = block[i][0].l;j <= block[i][0].r;j++)
        {
            res[a[j]]++;
            if(res[a[j]]==k) cnt++;
        }
        l = block[i][0].l,r = block[i][0].r;
        ans[block[i][0].num] = cnt;
        for(int j = 1;j < block[i].size();j++)
        {
            while(l<block[i][j].l)
            {
                res[a[l]]--;
                if(res[a[l]]==k-1) cnt--;
                l++;
            }
            while(l>block[i][j].l)
            {
                l--;
                res[a[l]]++;
                if(res[a[l]]==k) cnt++;
            }
            while(r<block[i][j].r)
            {
                r++;
                res[a[r]]++;
                if(res[a[r]]==k) cnt++;
            }
            ans[block[i][j].num] = cnt;
        }
        for(int j = 0;j < N;j++) res[j] = 0;
    }

    for(int i = 1;i <= q;i++) cout << ans[i] << '\n';
}
