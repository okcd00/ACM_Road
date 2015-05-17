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
char map[101][101];

int main()
{
	//freopen("in.txt","r",stdin);
	int n,m;
	scanf("%d%d",&n,&m);
	char huiche;
	scanf("%c",&huiche);
	//printf("%d %d\n",n,m); ÖÐÍ¾¸ÄÌâ £¿£¡£¡ 
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			char ch;
			scanf("%c",&ch);
			if(ch=='-')printf("-");
			else if(ch=='.')printf((i+j)%2==0?"B":"W");
			else printf("%c",ch);
		}
		if(i==n-1)return 0;
		else 
		{
			scanf("%c",&huiche);
			printf("\n");
		}
	}
	
	return 0;
}
