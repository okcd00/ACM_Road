#include <cmath>   
#include <vector>  
#include <cctype>  
#include <cstdio>  
#include <string>  
#include <cstdlib>  
#include <cstring>  
#include <iostream>  
#include <algorithm>  
using namespace std;
int p,n;
int hash[301];

int geth(int x)
{
	return x%p;
}

int main()
{
	int flag=0;
	memset(hash,0,sizeof hash);
	scanf("%d%d",&p,&n);
	for(int i=1;i<=n;i++)
	{
		int tmp;
		scanf("%d",&tmp);
		if(hash[geth(tmp)]==0)hash[geth(tmp)]=1;
		else if(!flag)
						{
							flag=i;
							break;
						}
	}
	if(!flag)printf("-1");
	else printf("%d",flag);
	
	return 0;
}
