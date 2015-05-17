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

int num[10]={0};
char cnum[11]={"pqruvwxyz"};

int main()
{
	int cases=0;
	scanf("%d",&cases);
	for(int _case=1;_case<=cases;_case++)
	{
		int flag=1;
		for(int i=0;i<10;i++) 
		{
			scanf("%d",&num[i]);
			if(num[i]!=0)
			{
				if(flag && num[i]>0);
				else printf("%c",num[i]>0?'+':'-');
				
				if(i==9) printf("%d",abs(num[i]));
				else if(abs(num[i])==1) printf("%c",cnum[i]);
				else printf("%d%c",abs(num[i]),cnum[i]);
				
				flag=0;
			} 
		}
		printf("\n");
	}
	return 0;
}
