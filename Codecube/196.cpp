#include <bits/stdc++.h>
using namespace std;

const long long N = 1e5 + 1;

long long n,m,as,at,bs,bt;
vector<pair<long long,long long> > adj[N];
priority_queue<pair<long long,long long>,vector<pair<long long,long long> >,greater<pair<long long,long long> > > q;
long long dist[N];
bool visited[N],dan[N];
queue<long long> qe;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> n >> m;

	for(long long i = 0;i < m;i++)
	{
		long long a,b,d;
		cin >> a >> b >> d;
		adj[a].push_back({d,b});
		adj[b].push_back({d,a});
	}

	cin >> as >> at >> bs >> bt;

	for(long long i = 1;i <= n;i++) dist[i] = LLONG_MAX;
	dist[as] = 0;
	q.push({0,as});

	while(!q.empty())
	{
		long long p = q.top().second;
		q.pop();
		if(visited[p]) continue;
		visited[p] = true;
		for(long long i = 0;i < adj[p].size();i++)
		{
			if(dist[p]+adj[p][i].first<dist[adj[p][i].second])
			{
				dist[adj[p][i].second] = dist[p]+adj[p][i].first;
				q.push({dist[adj[p][i].second],adj[p][i].second});
			}
		}
	}

	for(long long i = 1;i <= n;i++) visited[i] = 0;
	visited[at] = true;
	qe.push(at);

	while(!qe.empty())
	{
		long long p = qe.front();
		qe.pop();
		dan[p] = true;
		for(long long i = 0;i < adj[p].size();i++) if(dist[adj[p][i].second]!=LLONG_MAX and dist[adj[p][i].second]+adj[p][i].first==dist[p])
		{
			if(visited[adj[p][i].second]) continue;
			visited[adj[p][i].second] = true;
			qe.push(adj[p][i].second);
		}
	}

	for(long long i = 1;i <= n;i++) dist[i] = LLONG_MAX,visited[i] = 0;

	dist[bs] = 0;
	q.push({0,bs});

	while(!q.empty())
	{
		long long p = q.top().second;
		q.pop();
		if(visited[p] or dan[p]) continue;
		visited[p] = true;
		for(long long i = 0;i < adj[p].size();i++) if(!dan[adj[p][i].second] and dist[p]+adj[p][i].first<dist[adj[p][i].second])
		{
			dist[adj[p][i].second] = dist[p]+adj[p][i].first;
			q.push({dist[adj[p][i].second],adj[p][i].second});
		}
	}

	if(dist[bt]==LLONG_MAX) dist[bt] = -1;
	cout << dist[bt];
}
