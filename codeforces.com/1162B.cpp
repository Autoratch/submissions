#include <bits/stdc++.h>
using namespace std;

const int N = 50;

int m,n;
int a[N][N],b[N][N];
bool ok = true;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> m >> n;
	
	for(int i = 0;i < m;i++) for(int j = 0;j < n;j++) cin >> a[i][j];
	for(int i = 0;i < m;i++) for(int j = 0;j < n;j++) cin >> b[i][j];
	
	for(int i = 0;i < m;i++) for(int j = 0;j < n;j++) if(a[i][j]>b[i][j]) swap(a[i][j],b[i][j]);
	
	for(int i = 0;i < m;i++) for(int j = 0;j < n;j++)
	{
		if(i and a[i][j]<=a[i-1][j]) ok = false;
		if(i and b[i][j]<=b[i-1][j]) ok = false;
		if(j and a[i][j]<=a[i][j-1]) ok = false;
		if(j and b[i][j]<=b[i][j-1]) ok = false;
	}
	
	if(ok) cout << "Possible";
	else cout << "Impossible";
}