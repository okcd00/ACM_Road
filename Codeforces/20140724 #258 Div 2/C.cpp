#include <cmath> 
#include <memory> 
#include <cstdio>
#include <string>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
typedef __int64 ll;
#define Max(a,b) ((a)>(b)?(a):(b))
#define Min(a,b) ((a)<(b)?(a):(b))

int cmp(const void *a, const void *b)
{
	return(*(int *)a-*(int *)b);
}

int main()
{
	int cases=0;
	scanf("%d",&cases);
	for(int _case=1;_case<=cases;_case++)
	{
		ll n,k,d1,d2,rest=0;
		cin>>n>>k>>d1>>d2;
		rest=n-k;
		if(n%3!=0)
		{
			cout<<"no"<<endl;
			continue;
		} 
		if(rest==0 && d1==0 && d2==0)
		{
			cout<<"yes"<<endl;
			continue;
		}
		if(d1==0 && d2==0)
		{
			cout<<(rest%3==0?"yes":"no")<<endl;
			continue;
		}
		if(rest<0)
		{
			cout<<"no"<<endl;
			continue;
		}
		
		ll rest1=rest-d1-d1-d2;		// >>
		if((d1+d2)>(n/3)) rest1=-1;
		if(d1+d2+d2>k) rest1=-1;
		ll rest2=rest-max(d1,d2)-(max(d1,d2)-min(d1,d2));// >< 
		if(max(d1,d2)>(n/3)) rest2=-1;
		if(d1+d2>k)rest2=-1;
		ll rest3=rest-d1-d2;		// <>
		if(max(d1,d2)>(n/3)) rest3=-1;
		if(max(d1,d2)+max(d1,d2)-min(d1,d2)>k) rest3=-1;
		ll rest4=rest-d1-d2-d2;		// <<
		if((d1+d2)>(n/3)) rest4=-1;
		if(d1+d1+d2>k) rest4=-1;
		
		if(rest1>=0 && rest1%3==0)cout<<"yes"<<endl;
		else if(rest2>=0 && rest2%3==0)cout<<"yes"<<endl;
		else if(rest3>=0 && rest3%3==0)cout<<"yes"<<endl;
		else if(rest4>=0 && rest4%3==0)cout<<"yes"<<endl;
		else cout<<"no"<<endl;
	}
	return 0;
}
 
