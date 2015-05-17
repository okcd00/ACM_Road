//Shortest Path Faster Algorithm
#include <stdio.h>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;

#define N 222
#define INF 99999999

vector<int> g[N];
int vis[N],d1[N],d2[N],d3[N],n,stk[N];

struct circle
{
    int x,y,r;
    void input() {scanf("%d%d%d",&x,&y,&r);}
}cir[N];

bool cross(circle a,circle b)// boolean (if crossed)
{    return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y) <= (a.r + b.r) * (a.r + b.r);}

template <class ForwardIterator, class T>	//use fill template to get simple
  void fill (ForwardIterator first, ForwardIterator last, const T& val)
{
  while (first != last) 
  {
    *first = val;
    ++first;
  }
}

void spfa(int *d,int src)
{
    memset(vis,0,sizeof(vis));
    fill(d,d + n,INF);

    d[src] = 0;
    int tp = 1;
    stk[0] = src;
    int u,i,v;
    while(tp)
    {
        u = stk[--tp];
        vis[u] = 0;
        for(i = 0; i < g[u].size(); ++i)
        {
            v = g[u][i];
            if(d[v] > d[u] + 1)
            {
                d[v] = d[u] + 1;
                if(!vis[v])
                {
                    vis[v] = 1;
                    stk[tp++] = v;
                }
            }
        }
    }
}
int main()
{
    int t,i,j;
    scanf("%d",&t);
    while(t--)
    {
        memset(g,0,sizeof(g));
        scanf("%d",&n);
        for(i = 0; i < n; ++i)
        {
            cir[i].input();
            for(j = 0; j < i; ++j)
                if(cross(cir[j],cir[i]))
                {
                    g[i].push_back(j);
                    g[j].push_back(i);
                }
        }
        spfa(d1,0);spfa(d2,1);spfa(d3,2);
        int minn = INF;
        for(i = 0; i < n; ++i)
            minn = min(minn,d1[i] + d2[i] + d3[i]);
        minn = minn == INF ? -1 : n - minn - 1;
        printf("%d\n",minn);
    }
    return 0;
}

