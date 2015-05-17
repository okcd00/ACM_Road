#include <memory>
#include <cstdio>
#include <iostream>
#include <algorithm>

#define MAXN 	10086
#define INF 999999999
using namespace std;
typedef  __int64 ll; 
int N;
ll K;

struct Node
{int x,p;} node[MAXN];

int cmp(const void *p1,const void *p2)	//compared by x
{
    return ((struct Node *)p1)->x-((struct Node *)p2)->x;
}

void Init()
{
    int i;
    for(i=1;i<=N;i++)	scanf("%d%d",&node[i].x,&node[i].p);
    qsort(node+1,N,sizeof(node[0]),cmp);
}

int Solve()	//Try to enum 
{
    int i,j,k,now,ans=0;
    ll M,d1,d2;
    for(i=1;i<=N;i++)	//N Range:10K 
    {
        k=i-1;j=i+1;M=K;now=node[i].p;
        while(1)
        {
            if		(k==0&&j!=N+1) d1=INF   ,d2=node[j].x-node[i].x;
            else if	(k!=0&&j==N+1) d2=INF   ,d1=node[i].x-node[k].x;
            else if	(k!=0&&j!=N+1) d1=node[i].x-node[k].x,d2=node[j].x-node[i].x;
			else break;

            if(d1<d2)	//dist l and r
            {
                if(d1 * node[k].p<=M)
				{
					now+=node[k].p;
					M-=d1*node[k].p;
					k--; 
				}
				else
				{
					now+=M/d1;
					break;
				}
            }
            else
            {
                if(d2 * node[j].p<=M)
				{
					now+=node[j].p;
					M-=d2*node[j].p;
					j++;
				}
				else
				{
					now+=M/d2;
					break;
				}
            }
        }
		ans=now>ans?now:ans;
    }
    return ans;
}

int main()
{
    while(scanf("%d%I64d",&N,&K)!=EOF)
    {
        Init();
        cout<<Solve()<<endl;
    }
	return 0;
}
