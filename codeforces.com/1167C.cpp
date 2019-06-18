#include <bits/stdc++.h>
using namespace std;

const int N = 5e5 + 1;

int n,m;
int pa[N],tmp[N],sz[N];

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
		int am;
		cin >> am;
		for(int j = 0;j < am;j++) cin >> tmp[j];
		for(int j = 0;j < am-1;j++) 
		{
			int a = tmp[j],b = tmp[j+1];
			int sa = sz[root(a)],sb = sz[root(b)];
			if(root(a)!=root(b)) pa[root(a)] = root(b),sz[root(b)] = sa+sb;
		}
	}
	
	for(int i = 1;i <= n;i++) cout << sz[root(i)] << ' ';
}