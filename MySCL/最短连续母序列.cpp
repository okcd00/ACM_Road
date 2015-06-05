#include<stdio.h>
#include<string.h>

struct str
{
    char letter[1600];
    int len;
}ans,a[20];

struct
{
    struct str temp;
    int x,y;
}add[500];

int f[1<<12][15],father[1<<12][15],reduce[20][20],cost[20][20],n,m,max,Test,s;
struct str ADD(struct str ans,int k,int reduce)
{
    int i;
    for(i=ans.len;i<ans.len+a[k].len-reduce;i++)
        ans.letter[i]=a[k].letter[reduce+i-ans.len];
    ans.letter[i]=0;
    ans.len=ans.len+a[k].len-reduce;
    return ans;
}
void quick(int l,int r)
{
    int i=l,j=r;
    struct str x=add[(i+j)>>1].temp;
    while(i<=j)
    {
        while(strcmp(add[i].temp.letter,x.letter)<0)  i++;
        while(strcmp(add[j].temp.letter,x.letter)>0)  j--;
        if(i<=j)
        {
            add[0]=add[i],add[i]=add[j],add[j]=add[0];
            i++,j--;
        }
    }
    if(i<r)  quick(i,r);
    if(j>l)  quick(l,j);
}
void READY()
{
    int i,j,k,r;
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
            for(k=0;k<a[i].len;k++)
            {
                for(r=0;k+r<a[i].len&&a[i].letter[k+r]==a[j].letter[r];r++);
                if(k+r==a[i].len)
                {
                    reduce[j][i]=r;
                    break;
                }
            }
    s=0;
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
        {
            s++;
            add[s].temp=ADD(a[i],j,reduce[j][i]),add[s].x=i,add[s].y=j;
        }
    quick(1,s);
    for(i=1;i<=s;i++)
        cost[add[i].x][add[i].y]=i;
}
void read()
{
    int i,j,k,r;
    scanf("%d",&n);
    memset(reduce,0,sizeof(reduce));
    for(i=1;i<=n;i++)
    {
        scanf("%s",a[i].letter);
        a[i].len=strlen(a[i].letter);
    }
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
        {
            if(i==j)  continue;                 
            for(k=0;k<a[j].len;k++)
            {
                for(r=0;r+k<a[j].len&&r<a[i].len&&a[j].letter[k+r]==a[i].letter[r];r++);
                if(r==a[i].len)  break;
            }
            if(k<a[j].len)  a[i].letter[0]=0;
        }
    for(i=n;i>=1;i--)
        if(a[i].letter[0]==0)
        {
            for(j=i;j<n;j++)
                a[j]=a[j+1];
            n--;
        }
    m=(1<<n)-1;
}
void DP()
{
    int i,j,k;
    for(i=0;i<=m;i++)
        for(j=1;j<=n;j++)
            f[i][j]=father[i][j]=0;
    for(i=1;i<=m;i++)
        for(j=1;j<=n;j++)
        {
            int add=1<<(j-1);
            if((i&add)==0)
                for(k=1;k<=n;k++)
                    if((i&(1<<(k-1)))!=0)
                    {
                        if(father[i+add][j]==0)
                        {
                            f[i+add][j]=f[i][k]+reduce[k][j],father[i+add][j]=k;
                            continue;
                        }
                        if(f[i+add][j]<f[i][k]+reduce[k][j])
                            f[i+add][j]=f[i][k]+reduce[k][j],father[i+add][j]=k;
                        else if(f[i+add][j]==f[i][k]+reduce[k][j]&&cost[j][father[i+add][j]]>cost[j][k])
                            father[i+add][j]=k;
                    }
        }
}
void solve()
{
    max=-1;
    int i,j,now;
    for(i=1;i<=n;i++)
    {
        if(max<f[m][i])
        {
            max=f[m][i],now=m;
            ans=a[i];
            for(j=i;father[now][j]!=0;)
            {
                ans=ADD(ans,father[now][j],reduce[father[now][j]][j]);
                int t=j;
                j=father[now][j],now-=(1<<(t-1));
            }
        }
        else if(max==f[m][i])
        {
            struct str temp=a[i];
            now=m;
            for(j=i;father[now][j]!=0;)
            {
                temp=ADD(temp,father[now][j],reduce[father[now][j]][j]);
                int t=j;
                j=father[now][j],now-=(1<<(t-1));
            }
            if(strcmp(ans.letter,temp.letter)>0)  ans=temp;
        }
    }
}
int main()
{
    int T=0;
    scanf("%d",&T);
    for(int i=1;i<=T;i++)
    {
		read();
		READY();
		DP();
		solve();
		printf("%s\n",ans.letter);
    }
    return 0;
}
