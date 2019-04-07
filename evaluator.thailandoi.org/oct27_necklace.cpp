#include <bits/stdc++.h>
using namespace std;

const int N = 3e5 + 5;

int n;
int fw[N],en[N],pa[N];

int root(int x)
{
	if(pa[x]==x) return x;
	else return pa[x] = root(pa[x]);
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n;
	
	for(int i = 1;i <= n;i++){ pa[i] = i; en[i] = i; }

	for(int i = 0;i < n-1;i++)
	{
		int a,b;
		cin >> a >> b;
        if(en[root(b)]==b){ fw[en[root(b)]] = a; en[root(b)] = en[a]; }
        else fw[en[a]] = fw[b];
        pa[a] = b;
        fw[b] = a;
    }
    
    int res = root(1);

    for(int i = res;i != 0;i = fw[i]) cout << i << ' ';
}
