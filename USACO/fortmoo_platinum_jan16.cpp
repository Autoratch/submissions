#include <bits/stdc++.h>
using namespace std;

const int N = 201;

int m,n,ans;
int a[N][N],lr[N][N],ud[N][N];

int main()
{
	freopen("fortmoo.in","r",stdin);
	freopen("fortmoo.out","w",stdout);
	cin >> m >> n;
	for(int i = 1;i <= m;i++) for(int j = 1;j <= n;j++)
	{
		char c;
		cin >> c;
		if(c=='X') a[i][j] = 1;
		lr[i][j] = a[i][j]+lr[i][j-1];
		ud[i][j] = a[i][j]+ud[i-1][j];
	}
	for(int l = 1;l <= n;l++) for(int r = l;r <= n;r++)
	{
		int x = 1,y = 1;
		while(y<=m)
		{
			if(x==y and lr[x][r]!=lr[x][l-1]) x++,y++;
			else if(ud[y][r]!=ud[x-1][r] or ud[y][l]!=ud[x-1][l]) x = y;
			else if(lr[y][r]!=lr[y][l-1]) y++;
			else ans = max(ans,(y-x+1)*(r-l+1)),y++;
		}
	}
	cout << ans;
}