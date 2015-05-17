//AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAh
//Have a rest,,, My head's broken
//Unbelievable complex !

#include <cmath> 
#include <cctype>
#include <cstdio>
#include <string>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
#define Max(a,b) ((a)>(b)?(a):(b))
#define Min(a,b) ((a)<(b)?(a):(b))

struct line
{
	int x1,y1;
	int x2,y2;
} a[8];

bool cmp(const int a, const int b)
{
	return a > b;
}

bool chk_f(int a,int b,int c,int d,int e,int f)
{
	return (ll)(f-b)*(c-a)==(ll)(d-b)*(e-a) ;
}

bool chk_x(int x,int y,int a,int b,int p,int q)
{
	return (ll)(a-x)*(p-x)+(ll)(b-y)*(q-y)>=0; 
}

bool chk_dis(int x,int y,int m,int n,int a,int b)
{
	if(x!=a)
	{
		int tmp=abs(a-x)*5;
		if(a>x && tmp<m-x) return false;
		if(a>x && tmp>4*(m-x)) return false;
		if(x>a && tmp<x-m) return false;
		if(x>a && tmp>4*(x-m)) return false;
		return true;
	}
	else
	{
		int tmp=abs(b-y)*5;
		if(b>y && tmp<n-y) return false;
		if(b>y && tmp>4*(n-y)) return false;
		if(y>b && tmp<y-n) return false;
		if(y>b && tmp>4*(y-n)) return false;
		return true;
	}
}

int main()
{
	int cases=0;
	scanf("%d",&cases);
	for(int _case=1;_case<=cases;_case++)
	{
		for(int i=0;i<3;i++)	scanf("%d%d%d%d",	&a[i].x1, &a[i].y1,
													&a[i].x2, &a[i].y2);
		//find A's '^' -eeeeee puzzled&complex 
		int mrk1=0,mrk2=0;
		int x,y,m,n,p,q; //变量要不够用了…… 
		for(int i=0; i<2; i++)
		for(int j=i+1; j<3; j++)
        {
            if(a[i].x1==a[j].x1&&a[i].y1==a[j].y1)
            {
              	x=a[i].x1,y=a[i].y1;
            	m=a[i].x2,n=a[i].y2;
            	p=a[j].x2,q=a[j].y2;
                mrk1=i, mrk2=j;
            }
            else if(a[i].x1==a[j].x2&&a[i].y1==a[j].y2)
            {
                x=a[i].x1,y=a[i].y1;
                m=a[i].x2,n=a[i].y2;
                p=a[j].x1,q=a[j].y1;
                mrk1=i, mrk2=j;
            }
            else if(a[i].x1==a[j].x1&&a[i].y2==a[j].y2)
            {
                x=a[i].x2,y=a[i].y2;
                m=a[i].x1,n=a[i].y1;
                p=a[j].x1,q=a[j].y1;
                mrk1=i, mrk2=j;
            }
            else if(a[i].x2==a[j].x1&&a[i].y2==a[j].y1)
            {
                x=a[i].x2,y=a[i].y2;
                m=a[i].x1,n=a[i].y1;
                p=a[j].x2,q=a[j].y2;
                mrk1=i, mrk2=j;
            }
        }
        //A's '-'
        int rx1=0,ry1=0,rx2=0,ry2=0;
		for(int i=0;i<3;i++)
		if(i!=mrk1 && i!=mrk2)
		{
			rx1=a[i].x1, ry1=a[i].y1;
			rx2=a[i].x2, ry2=a[i].y2;
			break;
		}
		//chk_f
		bool f=true;
		if((chk_x(x,y,m,n,p,q))==false) f=false;
		//chk dist from cross point
		if(f)
		{
			if(chk_f(x,y,m,n,rx1,ry1) && chk_f(x,y,p,q,rx2,ry2))
			{
				if(chk_dis(x,y,m,n,rx1,ry1)==false)f=false;
				if(chk_dis(x,y,p,q,rx2,ry2)==false)f=false;
			}
			else if(chk_f(x,y,p,q,rx1,ry1) && chk_f(x,y,m,n,rx2,ry2))
			{
				if(chk_dis(x,y,p,q,rx1,ry1)==false)f=false;
				if(chk_dis(x,y,m,n,rx2,ry2)==false)f=false;
			}
			else f=false;
		}
		if(f)	cout<<"YES"<<endl;
		else 	cout<<"NO" <<endl;
	}
	return 0;
}
