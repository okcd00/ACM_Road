#include <cmath> 
#include <cctype>
#include <cstdio>
#include <string>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
int n,a[200048]={0},ans=0;
#define Max(a,b) ((a)>(b)?(a):(b))
#define Min(a,b) ((a)<(b)?(a):(b))
#define update(x) ans=(ans<(x)?x:ans);

int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;++i) scanf("%d",&a[i]);
	sort(a,a+n);
	for(int i=0;i<n-1;++i)
	if(i==0||a[i]!=a[i-1])
	{
		int j=a[i]+a[i],p;
		while(j <= a[n-1])
		{
			p = lower_bound(a,a+n,j)-a;
			if(p > 0) update(a[p-1] % a[i]);
			j+=a[i];
		}
		update(a[n-1] % a[i]); 
	}
	printf("%d\n",ans);
	return 0;
}
