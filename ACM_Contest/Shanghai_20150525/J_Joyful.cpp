#include<cstdio>
#include<iostream>
#include<algorithm>
#define rep(i,a,b) for(int i=a;i<b+1;i++)
#define lson (k<<1)
#define rson (k<<1|1)
#define mid ((l+r)>>1)
using namespace std;
typedef long long ll;
int n,m,k;

double pow(double a,int b)
{
	double res=1.0;
	while(b>0)
	{
		if(b&1) res=res*a;
		a=a*a;
		b>>=1;
	}
	return res;
}

int main()
{
	int T;
	scanf("%d",&T);
	rep(z,1,T)
	{
		scanf("%d%d%d",&n,&m,&k);
		double ans=0.0;
		for(double x=1.0; x<=(double)n; x+=1)
		for(double y=1.0; y<=(double)m; y+=1)
		{
			double temp=0.0;
			temp+=(x-1)/n*(x-1)/n + (y-1)/m*(y-1)/m + (n-x)/n*(n-x)/n + (m-y)/m*(m-y)/m;
			temp-=(x-1)/n*(y-1)/m*(x-1)/n*(y-1)/m + (x-1)/n*(m-y)/m*(x-1)/n*(m-y)/m;
			temp-=(n-x)/n*(y-1)/m*(n-x)/n*(y-1)/m + (n-x)/n*(m-y)/m*(n-x)/n*(m-y)/m;
			double tmp=pow(temp,k);	 
			ans+=1-tmp;
		}
		printf("Case #%d: %.f\n",z,ans);
	}
	return 0;
}
