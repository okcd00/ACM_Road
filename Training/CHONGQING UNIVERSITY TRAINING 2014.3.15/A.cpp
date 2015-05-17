#include <algorithm>
#include <iostream>
#include <cstdio>
#define RD(a) scanf("%d",&a)

using namespace std;

int main()
{
	int n=0,ans=1;
	scanf("%d",&n);
	int last,curr;
	RD(last);
	for(int i=1;i<=n-1;i++)
	{
		RD(curr);
		if(curr==last) continue;
		else { last=curr; ans++; }
	}
	cout<<ans<<endl;
	return 0;
}
