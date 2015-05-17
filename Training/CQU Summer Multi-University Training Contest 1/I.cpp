#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;

typedef struct edge
{
	int	  x;
	edge *n;
};

bool f[30000];
edge *e[30000],*g[30000];
int q[30000],mark[30000],u[30000],v[30000];
int num,n,m;

void addedge(int x,int y)
{
    edge *p;
	
    p=new edge;
    p->x=y,    p->n=e[x];     
    e[x]=p;
	
    p=new edge;
    p->x=x,    p->n=g[y];
    g[y]=p;
}

void search(int t)
{
    edge *p;
    p=e[t];
    f[t]=true;
    while (p!=NULL)
    {
		if (!f[p->x]) search(p->x);
		p=p->n;
    }     
    q[++num]=t;
}

void build(int t,int m)
{
    edge *p;
    p=g[t];
    f[t]=false;
    mark[t]=m;

    while (p!=NULL)
    {
        if (f[p->x]) build(p->x,m);
        p=p->n;
    }
}

int main()
{
    int i,x,y;
    while (scanf("%d%d",&n,&m)!=EOF)
    {
        for (i=1; i<=n; i++) e[i]=g[i]=NULL;
        for (i=0; i<m; i++)
        {
            cin>>x>>y;
            addedge(x,y);
        }      
        for (i=1; i<=n; i++) f[i]=false;
        num=0;
        for (i=1; i<=n; i++) if (!f[i]) search(i);
		num=0;
        for (i=n; i>=1; i--) if (f[q[i]]) 
        {
            num++;
            build(q[i],num);             
        }
        for (i=1; i<=num; i++) u[i]=v[i]=0;
        for (i=1; i<=n; i++)
        {
            edge *p;
            p=e[i];
            while (p!=NULL)
            {
                if (mark[i]!=mark[p->x]) 
				{
					u[mark[i]]++;
                    v[mark[p->x]]++;
                }
				p=p->n;
            }    
        }
        int k1=0,k2=0;
        for (i=1; i<=num; i++)
        {
            if (u[i]==0) k1++;
            if (v[i]==0) k2++;
        }
        int k0=0; 
		cout<< ((num==1)?k0:k1>k2?k1:k2) <<endl;
    }
    return 0;
}
