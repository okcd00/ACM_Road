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
typedef long long ll;
#define Max(a,b) ((a)>(b)?(a):(b))
#define Min(a,b) ((a)<(b)?(a):(b))

int cmp(const void *a, const void *b)
{
	return(*(int *)a-*(int *)b);
}

int num[20],sup[20];
int away[20],vis[20];

int main()
{
	//loop varieties
	int i=0,j=0,m=0;
	memset(num,0,sizeof(num));
	memset(sup,0,sizeof(sup)); 
	memset(away,0,sizeof(away));
	memset(vis,0,sizeof(vis));
	ll _num=0;
	int k=0,_i=0,len=0;
	scanf("%lld%d",&_num,&k);
	while(_num!=0)
	{
		num[_i]=_num%10;
		sup[_i]=_num%10;
		_num/=10;
		len++,_i++;
	}
	sort(sup,sup+len,greater<int>()); 	//最大数 sup 
	for(i=0;i<len/2;i++)			//当前数 num 
	{
		int temp=num[i];
		num[i]=num[len-1-i];
		num[len-1-i]=temp;
	}
	int position=0;
	while(k>0)
	{
		if(num[position]==sup[position])
		{
			position++;
			continue;
		}
		else for(i=position;i<len;i++)
		{
			if(num[i]==sup[position])
			{
				if(k>position-i)
				{
					k-=(position-i);
					int temp_1=num[i];
					for(j=i;j>position;j--)
					{
						num[j]=num[j-1];
					}
					num[position]=temp_1;
				}
				else break;
			}
		}
		int maxInRest=0;
		//Calc Rest..
		for(m=i;m<=i+k;m++)
		{
			if(num[m]>maxInRest)maxInRest=num[m];
		}
		//Time's Up .Goodgame GG
	}
	return 0;
}
