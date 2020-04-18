#include <bits/stdc++.h>
using namespace std;

const int N = 2000;

int n,m,ans;
int pa[N],sz[N];
bool no[N];

int root(int x)
{
	if(pa[x]==x) return x;
	else return pa[x] = root(pa[x]);
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> m;
	
	for(int i = 1;i <= n;i++) pa[i] = i,sz[i] = 1;
	
	for(int i = 0;i < m;i++)
	{
		int a,b;
		cin >> a >> b;
		if(root(a)!=root(b))
		{
			int sa = sz[root(a)],sb = sz[root(b)];
			pa[root(a)] = root(b);
			sz[root(b)] = sa+sb;
		}
	}
	
	cin >> m;
	
	for(int i = 0;i < m;i++)
	{
		int a,b;
		cin >> a >> b;
		if(root(a)==root(b)) no[root(a)] = true;
	}
	
	for(int i = 1;i <= n;i++) if(pa[i]==i and !no[i]) ans = max(ans,sz[i]);
	
	cout << ans;
}