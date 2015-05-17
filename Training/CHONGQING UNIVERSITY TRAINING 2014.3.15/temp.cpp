#include <algorithm>
#include <iostream>
using namespace std;

int main()
{
	int n=0,ans=0;
	cin>>n;
	char last[2];
	cin>>last;
	char curr[2];
	while(--n)
	{
		cin>>curr;
		if(curr[0]!=last[1])ans++;
		last[0]=curr[0];
		last[1]=curr[1];
	}
	cout<<ans;
}
