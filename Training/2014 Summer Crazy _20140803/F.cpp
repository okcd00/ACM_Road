#include <cmath> 
#include <cstdio>
#include <string>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#define len(i,j,k) (a*k+b*j+c*i)
#define update(i,j,k) ans=(ans<i+j+k?(i+j+k):ans)
using namespace std;

int main()
{
	int n,t[3];
	cin>>n>>t[0]>>t[1]>>t[2]; sort(t,t+3);
	int a=t[2],b=t[1],c=t[0];
	int an=n/a,bn=n/b,cn=n/c,ans=0,exit_f=0;
	for(int i=cn;i>=0;i--)
	{
		if(len(i,0,0)==n){ans=i;break;}
		for(int j=min(bn,(n-i*c)/b);j>=0;j--)
		{
			if(len(i,j,0)==n){update(i,j,0);exit_f=1;break;}
			else if(len(i,j,0)>n)break;
			for(int k=0;k<=an;k++)
			{
				//cout<<i<<":"<<j<<":"<<k<<"\t"<<len(i,j,k)<<endl;
				if(len(i,j,k)==n) update(i,j,k); 
				else if(len(i,j,k)>n)break;
			}
		}
		if(exit_f)break;
	}
	cout<<ans<<endl;
	return 0;
}
