/*
    TASK: Technology TOI14
    AUTHOR: PeaTT~
    SCHOOL: KVIS
    LANG: CPP
*/
#include <bits/stdc++.h>
using namespace std;
vector<int> g[100005],rev[100005];
int mk[100005],degin[100005];
int level[100005],dp[100005],ans[100005],mlevel[100005];
queue<int> bfs;
priority_queue<pair<int,int> > heap;
int main()
{
    int n,k,t;
    int i,j,l,a,b,c,d;
    scanf(" %d %d %d",&n,&k,&t);
    for(i=1;i<=n;i++){
        scanf("%d %d",&level[i],&a);
        mlevel[level[i]]++;
        for(j=0;j<a;j++){
            scanf("%d",&b);
            g[b].push_back(i);
            degin[i]++;
        }
    }
    for(i=1;i<=n;i++){
        if(!degin[i]){
            mk[i] = 1;
            bfs.push(i);
        }
    }
    // topo, check if it's able to access
    while(!bfs.empty()){
        int now = bfs.front();
        bfs.pop();
        for(int e : g[now]){
            degin[e]--;
            if(degin[e]==0){
                mk[e] = 1;
                bfs.push(e);
            }
        }
    }
    // do dp on reverse graph
    memset(degin,0,sizeof degin);
    for(i=1;i<=n;i++){
        if(!mk[i]) continue; // unable to access
        for(int e : g[i]){
            if(mk[e]){
                rev[e].push_back(i); degin[i]++;
            }
        }
    }
    for(i=1;i<=n;i++){
        dp[i] = level[i];
        if(!mk[i]) continue;
        if(!degin[i]) bfs.push(i);
    }
    while(!bfs.empty()){
        int now = bfs.front();
        bfs.pop();
        for(int e : rev[now]){
            degin[e]--;
            dp[e] = min(dp[e],dp[now]);
            if(!degin[e]) bfs.push(e);
        }
    } // dp : done
    // greedy part
    memset(degin,0,sizeof degin);
    for(i=1;i<=n;i++){
        if(!mk[i]) continue;
        for(int e : g[i]) degin[e]++;
    }
    for(i=1;i<=n;i++){
        if(!mk[i] || degin[i]) continue;
        heap.push({-dp[i],i});
    }
    while(t-- && !heap.empty()){
        int now = heap.top().second;
        heap.pop();
        ans[level[now]]++;
        for(int e : g[now]){
            if(!mk[e]) continue;
            degin[e]--;
            if(!degin[e]) heap.push({-dp[e],e});
        }
    }
    int ANS=k;
    for(i=1;i<=k;i++){
        if(ans[i]!=mlevel[i]){
            ANS=i-1;
            break;
        }
    }
    if(!ANS) printf("-1");
    else printf("%d",ANS);
    return 0;
}
/*
6 5 4
1 0
5 1 1
2 1 2
4 2 3 5
3 1 6
2 1 1
*/
