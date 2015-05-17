#include <cmath>
#include <string>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
#define Max(a,b) ((a)>(b)?(a):(b))
#define Min(a,b) ((a)<(b)?(a):(b))
int row[4]={0};
int m[4][4]={0};
int mark[4]={0};
//int col[4]={0};

int main()
{
	memset(m,0,sizeof m);
	for(int i=1;i<=3;i++)
	{
		for(int j=1;j<=3;j++)
		{
			cin>>m[i][j];
			row[i]+=m[i][j];
			if(m[i][j]==0) mark[i]=j;
			//col[j]+=m[i][j];
		}
	}
	row[0]=max(row[1],max(row[2],row[3]));
	for(int i=1;i<=3;i++)
	{
		if(row[0]==row[i])
		{
			for(int j=1;j<=3;j++)
			{
				if(j!=i) m[j][mark[j]]=row[0]-row[j];
				else m[j][mark[j]]=0;
			}
		}
	}
	int plus=(m[1][3]+m[3][1]-m[1][1]-m[3][3])/2;
	for(int i=1;i<=3;i++)	m[i][mark[i]]+=plus;
	for(int i=1;i<=3;i++)
	{
		for(int j=1;j<=3;j++)
		{
			cout<<m[i][j];
			cout<<(j==3?"\n":" ");
		}
	}
	return 0;
}
