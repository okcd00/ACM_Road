#include <map>
#include <stack>
#include <queue>
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

int main()
{
	freopen("in.txt","r",stdin);
	char choice[4][110];
	int len[4];
	int sup[4];
	for(int i=0;i<4;i++)
	{
		cin>>choice[i];
		len[i]=strlen(choice[i])-2;
		sup[i]=len[i];
	}
	sort(sup,sup+4);
	if(sup[0]*2<=sup[1])
	{
		for(int j=0;j<4;j++)
		if(len[j]==sup[0])
		{
			char ans='A'+j;
			printf("%c",ans);
		}
	}
	else if(sup[3]>=sup[2]*2)
	{
		for(int j=0;j<4;j++)
		if(len[j]==sup[3])
		{
			char ans='A'+j;
			printf("%c",ans);
		}
	}
	else
	{
		printf("C");
	}
	return 0;
}
