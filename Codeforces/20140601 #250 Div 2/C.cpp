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
using namespace std;//贪心来一发 

#define Max(a,b) ((a)>(b)?(a):(b))
#define Min(a,b) ((a)<(b)?(a):(b))

int egy[1002];
int pwr[1002];
int map[1002][1002];

bool cmp_0(int *a,int* b){	return a[0]>b[0];}
bool cmp_1(int *a,int* b){	return a[1]<b[1];}

int main()
{
	freopen("in.txt","r",stdin);
	memset(egy,0,sizeof(egy));
	memset(pwr,0,sizeof(pwr));
	memset(map,0,sizeof(map));
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>egy[i];
	int no1,no2;
	for(int j=1;j<=m;j++)
	{
		cin>>no1>>no2;
		map[no1][no2]=map[no2][no1]=1;
		pwr[no1]+=egy[no2];
		pwr[no2]+=egy[no1];
	}
	int**  sup=new int*[1002]; 
	for(int i=1;i<=n;i++)
	{
		sup[i]=new int[2];//0-no 1-val
		sup[i][0]=i;
		sup[i][1]=pwr[i];
	}
	int ans=0;
	while(1)
	{
		sort(sup+1,sup+n,cmp_1);
		cout<<sup[n][1]<<endl;//I find my fault -- 贪心 is wrong 
		if(sup[n][1]==0)
		{
			printf("%d",ans);
			return 0;
		}
		for(int i=1;i<=n;i++)
		{
			if(sup[i][1]==0)continue;
			for(int j=1;j<=n;j++)
			if(map[i][j]==1)
			{
				map[i][j]=map[j][i]=0;
				sup[i][1]-=egy[j];
				sup[j][1]-=egy[i];
				ans+=egy[j];
				cout<<ans<<endl;
			}
		}
		
	}
	
	return 0;
}
