#include <cmath> 
#include <cctype>
#include <cstdio>
#include <string>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

#define Max(a,b) ((a)>(b)?(a):(b))
#define Min(a,b) ((a)<(b)?(a):(b))

bool cmp(const int a, const int b)
{
	return a > b;
}

int main()
{
	int n;	cin>>n;
	if(n==1 || n==2) cout<<1<<endl<<1<<endl;
	else if(n==3) cout<<2<<endl<<"1 3"<<endl;
	else 
	{
		printf("%d\n",n);
		int mid=n/2+1;
		for(int i=1;mid-i>0 || mid+i<=n;i++)
		{
			if(mid-i>0) printf("%d ",mid-i);
			if(mid+i<=n) printf("%d ",mid+i);
		}
		printf("%d",n/2+1);
	}
	return 0;
}
