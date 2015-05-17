#include<cmath>
#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	double ans;
	double x1,y1,r1,x2,y2,r2;
	cin>>x1>>y1>>r1>>x2>>y2>>r2;
	double dist=sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1));
	if(dist>=(r1+r2))	ans=(dist-r1-r2)/2;
	else if(r1>dist+r2||r2>dist+r1)
	{
		if(r1>dist+r2)	ans=(r1-dist-r2)/2;
		if(r2>dist+r1)	ans=(r2-dist-r1)/2;
	}
	else ans=(double)0;
	printf("%.18lf\n",ans);
	return 0;
}
