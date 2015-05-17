#include <cmath>
#include <cstdio>
#include <vector>
#include <string>
#include <memory>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		int ans=0;
		for(int i=0;i<30000 && i*i<=n/2;i++)
		{
			int j=sqrt(n-i*i);
			if(j*j==n-i*i)
			{
					if(i==0&&j==0)		ans++;
					else if(i==0||j==0)	ans+=4;
					else if(i==j)		ans+=4;
					else if(i!=0&&j!=0)	ans+=8;
					//cout<<ans<<":"<<i<<"&"<<j<<endl;
			}
		}
		cout<<ans<<endl; 
	} 
	return 0;
}
