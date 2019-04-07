#include <bits/stdc++.h>
using namespace std;

const int N = 1000;

int n,m,k,ans,s,e;
int a[N],fw[N],bw[N];
bool used[N],em = true;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> m >> k;

    for(int i = 0;i < n;i++){ cin >> a[i]; fw[i] = -1; bw[i] = -1; }
    
    for(int i = 0;i < m;i++)
    {
        int x;
        cin >> x;
        x--;
        if(used[x])
        {
            if(x==e) continue;
            if(x==s)
            {
                s = fw[s];
                bw[s] = -1;
                fw[e] = x;
                bw[x] = e;
                fw[x] = -1;
                e = x;
            }
            else
            {
                fw[bw[x]] = fw[x];
                bw[fw[x]] = bw[x];
                fw[e] = x;
                bw[x] = e;
                fw[x] = -1;
                e = x;
            }
        }   
        else
        {
            if(em)
            {
                s = x;
                e = x;
                ans+=a[x];
                em = false;
            }
            else if(ans+a[x]<=k)
            {
                fw[e] = x;
                bw[x] = e;
                ans+=a[x];
                e = x;
            }
            else
            {
                int j = s;
                while(true)
                {
                    ans-=a[j];
                    used[j] = false;
                    int f = fw[j],b = bw[j];
                    fw[j] = -1;
                    bw[j] = -1;
                    if(f!=-1) bw[f] = -1;
                    if(b!=-1) fw[b] = -1; 
                    j = f;
                    s = j;
                    if(ans+a[x]<=k) break;
                }
                if(ans==0)
                {
                    s = x;
                    e = x;
                }
                else
                {
                    fw[e] = x;
                    bw[x] = e;
                    e = x;
                }
                ans+=a[x];
            }
            used[x] = true;
        }
    }
    cout << k-ans;
}