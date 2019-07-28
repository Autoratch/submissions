#include "scanlib.h"
#include <bits/stdc++.h>
using namespace std;

const int N = 41;

int n,ou,od,u,d,all;
vector<pair<int,int> > upp,doo,boo;
bool dlu[N],dld[N];
/*
#define MAX_K 100

typedef pair<pair<int,int>, pair<int,int> > ipp;

static int sol_k;
static ipp sol_items[MAX_K];
static ipp out_items[MAX_K];
static int detect_count;

int scan_init()
{
  scanf("%d %d",&n,&sol_k);
  for(int i=0; i<sol_k; i++) {
    int a,b,c,d;
    scanf("%d %d %d %d",&a,&b,&c,&d);
    sol_items[i].first.first = a;
    sol_items[i].first.second = b;
    sol_items[i].second.first = c;
    sol_items[i].second.second = d;
  }
  sort(sol_items, sol_items+sol_k);
  detect_count = 0;
  return n;
}

int detect(int r1, int c1, int r2, int c2)
{
  detect_count++;

  if(detect_count > 2000) {
    printf("Too many questions\n");
    exit(0);
  }

  if((r1 > r2) || (c1 > c2) ||
     (r1 < 1) || (r2 > 2) ||
     (c1 < 1) || (c2 > n)) {
    printf("Interaction error\n%d %d %d %d",r1,c1,r2,c2);
    exit(0);
  }

  int count = 0;
  for(int i=0; i<sol_k; i++)
    if((r1 <= sol_items[i].second.first) &&
       (r2 >= sol_items[i].first.first) &&
       (c1 <= sol_items[i].second.second) &&
       (c2 >= sol_items[i].first.second))
      count++;

  return count;
}

void scan_report(int k, int items[][4])
{
  printf("%d calls to detect.\n",detect_count);
  
  if(k != sol_k)
    printf("Incorrect\n");
  else {
    for(int i=0; i<k; i++) {
      out_items[i].first.first = items[i][0];
      out_items[i].first.second = items[i][1];
      out_items[i].second.first = items[i][2];
      out_items[i].second.second = items[i][3];
    }
    sort(out_items, out_items+k);

    bool ok = true;
    for(int i=0; i<k; i++) {
      if(out_items[i] != sol_items[i])
        ok = false;
    }
    if(ok)
      printf("Correct\n");
    else
      printf("Incorrect\n");
  }

  for(int i = 0;i < k;i++){ for(int j = 0;j < 4;j++) cout << items[i][j] << ' '; cout << endl; }
  exit(0);
}
*/
int main()
{
    n = scan_init();
    n++;
    
    all = detect(1,1,2,n);
    u = detect(1,1,1,n);
    d = detect(2,1,2,n);

    int cl = 1;
    for(int i = 0;i < u;i++)
    {
        int l = cl,r = n;
        while(l<r)
        {
            int m = (l+r)/2;
            if(!detect(1,cl,1,m)) l = m+1;
            else r = m;
        }
        int st = l;
        l = st,r = n;
        while(l<r)
        {
            int m = (l+r)/2;
            if(detect(1,cl,1,m)==1) l = m+1;
            else r = m;
        }
        int bf = l-1;
        l = st,r = bf;
        while(l<r)
        {
            int m = (l+r)/2;
            if(detect(1,m,1,bf)==1) l = m+1;
            else r = m;
        }
        int en;
        if(detect(1,l,1,bf)) en = l;
        else en = l-1;
        upp.push_back({st,en});
        cl = en+1;
    }
    
    cl = 1;
    for(int i = 0;i < d;i++)
    {
        int l = cl,r = n;
        while(l<r)
        {
            int m = (l+r)/2;
            if(!detect(1,cl,1,m)) l = m+1;
            else r = m;
        }
        int st = l;
        l = st,r = n;
        while(l<r)
        {
            int m = (l+r)/2;
            if(detect(1,cl,1,m)==1) l = m+1;
            else r = m;
        }
        int bf = l-1;
        l = st,r = bf;
        while(l<r)
        {
            int m = (l+r)/2;
            if(detect(1,m,1,bf)==1) l = m+1;
            else r = m;
        }
        int en;
        if(detect(1,l,1,bf)) en = l;
        else en = l-1;
        doo.push_back({st,en});
        cl = en+1;
    }
 

    int i = 0,j = 0;
    while(i<upp.size() and j<doo.size())
    {
        if(upp[i]==doo[j]) 
        {
            if(detect(1,upp[i].first,2,upp[i].second)==1) dlu[i] = dld[j] = true;
            boo.push_back(upp[i]);
            i++,j++;
        }
        else if(upp[i]>doo[j]) j++;
        else i++;
    }

    int items[all][4];
    int now = 0;
    for(int i = 0;i < upp.size();i++) if(!dlu[i]) items[now][0] = 1,items[now][1] = upp[i].first,items[now][2] = 1,items[now][3] = upp[i].second,now++;
    for(int i = 0;i < doo.size();i++) if(!dld[i]) items[now][0] = 2,items[now][1] = doo[i].first,items[now][2] = 2,items[now][3] = doo[i].second,now++;
    for(int i = 0;i < boo.size();i++) items[now][0] = 1,items[now][1] = boo[i].first,items[now][2] = 2,items[now][3] = boo[i].second,now++;

    scan_report(all,items);
}
