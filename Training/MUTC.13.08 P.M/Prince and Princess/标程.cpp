#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<vector>
using namespace std;
#define maxn 2000
int N,M;
int m;
vector<int>vv[maxn];
vector<int>nv[maxn];
vector<int>ans[maxn];
int link[maxn];
int vis[maxn];
int dfn[maxn],low[maxn],belong[maxn],instack[maxn],stack[maxn];
int dex,color,top;
void DFS(int x)
{
    dfn[x]=low[x]=++dex;
    instack[x]=1;
    stack[top++]=x;
    int len=nv[x].size();
    for(int i=0;i<len;i++)
    {
        int v=nv[x][i];
        if(!dfn[v])
        {
            DFS(v);
            low[x]=min(low[v],low[x]);
        }
        else if(instack[v])
            low[x]=min(dfn[v],low[x]);
    }
    if(low[x]==dfn[x])
    {
        int j;
        color++;
        do
        {
            j=stack[--top];
            belong[j]=color;
            instack[j]=0;
        }while(x!=j);
    }
}
void tarjan()
{
    memset(dfn,0,sizeof(dfn));
    for(int i=1;i<=M;i++)
        if(!dfn[i])
            DFS(i);
    for(int i=1;i<=N;i++)
        ans[i].clear();
    for(int i=1;i<=M;i++)
    {
        if(link[i]==-1)
            continue;
        int x=link[i];
        int len=vv[x].size();
        for(int j=0;j<len;j++)
            if(belong[vv[x][j]]==belong[i])
                ans[x].push_back(vv[x][j]);
        sort(ans[x].begin(),ans[x].end());
    }
}
bool dfs(int x)
{
    int len=vv[x].size();
    for(int i=0;i<len;i++)
    {
        int v=vv[x][i];
        if(vis[v])
            continue;
        vis[v]=1;
        if(link[v]==-1||dfs(link[v]))
        {
            link[v]=x;
            return 1;
        }
    }
    return 0;
}
int main()
{
    int T;
    scanf("%d",&T);
    int cas=0;
    while(T--)
    {
        scanf("%d%d",&N,&M);
        for(int i=1;i<=N;i++)
            vv[i].clear();
        for(int i=1;i<=N;i++)
        {
            int k;
            scanf("%d",&k);
            for(int j=1;j<=k;j++)
            {
                int x;
                scanf("%d",&x);
                vv[i].push_back(x);
            }
        }
        memset(link,-1,sizeof(link));
        for(int i=1;i<=N;i++)
        {
            memset(vis,0,sizeof(vis));
            dfs(i);
        }
        memset(vis,0,sizeof(vis));
        for(int i=1;i<maxn;i++)
            nv[i].clear();
        int xu=0;
        for(int i=1;i<=M;i++)
            if(link[i]!=-1)
                vis[link[i]]=1;
        for(int i=1;i<=N;i++)
            if(!vis[i])
                link[++xu+M]=i;
        for(int i=1;i<=M+xu;i++)
        {
            int x=link[i];
            if(x==-1)
            {
                for(int j=1;j<=M+xu;j++)
                    nv[i].push_back(j);
            }
            else
            {
                int len=vv[x].size();
                for(int j=0;j<len;j++)
                {
                    int v=vv[x][j];
                    nv[i].push_back(v);
                }
                for(int j=M+1;j<=M+xu;j++)
                    nv[i].push_back(j);
            }
        }
        m=M;
        M+=xu;
        tarjan();
        printf("Case #%d:\n",++cas);
        for(int i=1;i<=N;i++)
        {
            int len=ans[i].size();
            printf("%d",len);
            for(int j=0;j<len;j++)
                printf(" %d",ans[i][j]);
            puts("");
        }
    }
}
