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
int a[5]={0};
const int limit=1000000;
bool cmp(const int a, const int b)
{
	return a > b;
}


int main()
{
	int n;	cin>>n;
	for(int i=0;i<n;i++) scanf("%d",&a[i]);
	if(n==0) printf("YES\n1\n1\n3\n3\n");
	else if(n==1)
	{
		printf("YES\n%d\n%d\n%d\n",a[0]*2,a[0]*2,a[0]*3);
	}
	else if(n==2)
	{
		sort(a,a+2);
		if(a[0]==a[1] && a[0]*3<=limit) printf("YES\n%d\n%d\n",a[0]*3,a[0]*3);
		else if(a[0]==a[1] && a[0]%3==0) printf("YES\n%d\n%d\n",a[0]/3,a[0]/3);
		else
		{
			if(a[1]%a[0]==0 && a[1]/a[0]==3) printf("YES\n%d\n%d\n",a[0],a[1]);
			else if(a[1]/a[0]<3 && a[0]*3<=limit) printf("YES\n%d\n%d\n",a[0]*3,a[0]*3+a[0]-a[1]);
			else printf("NO\n"); //nonsence, ignore it
		}
		
	} 
	else if(n==3)
	{
		sort(a,a+3);
		if(a[2]%a[0]==0 && a[2]/a[0]==3) printf("YES\n%d\n",a[2]-a[1]+a[0]);
		else 
		{
			int rest1=a[2]+a[1]-a[0];	//a_4
			int rest2=a[0]+a[1]-a[2];	//a_1
			if(rest1%a[0]==0 && rest1/a[0]==3 && rest1<=limit) printf("YES\n%d\n",rest1);
			else if(a[2]%rest2==0 && a[2]/rest2==3 && rest2<=limit) printf("YES\n%d\n",rest2);
			else printf("NO\n");
		}
		
	}
	else if(n==4)
	{
		sort(a,a+4);
		if(a[0]+a[3]==a[1]+a[2] && a[3]-a[0]==(a[1]+a[2])/2 && (a[1]+a[2])%2==0 ) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}
