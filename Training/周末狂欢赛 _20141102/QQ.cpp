#include <stdio.h>
#include <string.h>
#include <iostream>
#include <cmath>
using namespace std;
int fang(int a,int b,int c,int d,int e,int f)
{
    if((long long)(f-b)*(c-a)==(long long)(d-b)*(e-a))
        return 1;
    return 0;
}
int xie(int x,int y,int a,int b,int p,int q)
{
    if((long long)(a-x)*(p-x)+(long long)(b-y)*(q-y)<0)
        return 0;
    return 1;
}
int juli(int x,int y,int m,int n,int a,int b)
{
    if(x!=a)
    {
        if(a>x)
        {
            if((a-x)*5<(m-x)) return 0;
            if((a-x)*5>(m-x)*4) return 0;
            return 1;
        }
        else
        {
            if((x-a)*5<(x-m)) return 0;
            if((x-a)*5>(x-m)*4) return 0;
            return 1;
        }
    }
    else
    {
        if(b>y)
        {
            if((b-y)*5<(n-y))return 0;
            if((b-y)*5>(n-y)*4)return 0;
            return 1;
        }
        else
        {
            if((y-b)*5<(y-n))return 0;
            if((y-b)*5>(y-n)*4)return 0;
            return 1;
        }
    }
}
struct note
{
    int x,y,z,zz;
} a[7];
int main()
{
    int t,x,y,m,n,p,q,x1,y1,x2,y2;
    int count1,count2;
    //int cnt=0;
    cin>>t;
    
        while(t--)
        {
            //cnt++;
            for(int i=0; i<3; i++)
                scanf("%d%d%d%d",&a[i].x,&a[i].y,&a[i].z,&a[i].zz);
                /*if(cnt==11)
                {
                    for(int i=0;i<3;i++)
                       printf("(%d %d %d %d)\n",a[i].x,a[i].y,a[i].z,a[i].zz);
                }*/
            for(int i=0; i<2; i++)
                for(int j=i+1; j<3; j++)
                {
                    if(a[i].x==a[j].x&&a[i].y==a[j].y)
                    {
                        x=a[i].x,y=a[i].y;
                        m=a[i].z,n=a[i].zz;
                        p=a[j].z,q=a[j].zz;
                        count1=i;
                        count2=j;
                    }
                    else if(a[i].x==a[j].z&&a[i].y==a[j].zz)
                    {
                        x=a[i].x,y=a[i].y;
                        m=a[i].z,n=a[i].zz;
                        p=a[j].x,q=a[j].y;
                        count1=i;
                        count2=j;
                    }
                    else if(a[i].z==a[j].z&&a[i].zz==a[j].zz)
                    {
                        x=a[i].z,y=a[i].zz;
                        m=a[i].x,n=a[i].y;
                        p=a[j].x,q=a[j].y;
                        count1=i;
                        count2=j;
                    }
                    else if(a[i].z==a[j].x&&a[i].zz==a[j].y)
                    {
                        x=a[i].z,y=a[i].zz;
                        m=a[i].x,n=a[i].y;
                        p=a[j].z,q=a[j].zz;
                        count1=i;
                        count2=j;
                    }
                }
            for(int i=0; i<3; i++)
                if(i!=count1&&i!=count2)
                {
                    x1=a[i].x,y1=a[i].y,x2=a[i].z,y2=a[i].zz;
                    break;
                }
            int flag=1;
            if(xie(x,y,m,n,p,q)==0)
                flag=0;
            if(flag)
            {
                if(fang(x,y,m,n,x1,y1)&&fang(x,y,p,q,x2,y2))
                {
                    if(juli(x,y,m,n,x1,y1)==0)
                        flag=0;
                    if(juli(x,y,p,q,x2,y2)==0)
                        flag=0;
                }
                else if(fang(x,y,p,q,x1,y1)&&fang(x,y,m,n,x2,y2))
                {
                    if(juli(x,y,m,n,x2,y2)==0)
                        flag=0;
                    if(juli(x,y,p,q,x1,y1)==0)
                        flag=0;
                }
                else
                    flag=0;
            }
            if(flag==1)
                printf("YES\n");
            else
                printf("NO\n");
        }
    return 0;
}
