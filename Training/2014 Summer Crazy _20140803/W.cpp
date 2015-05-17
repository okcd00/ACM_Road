#include <cmath> 
#include <cstdio>
#include <string>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
char map[51][51];
int mrk[51][51];
int cnt=0;

int main()
{
	int n,m;	cin>>n>>m;
	getchar();
	memset(map,'*',sizeof map);
	memset(mrk,0,sizeof mrk);
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++) 
		{
			cin>>map[i][j];
			if(map[i][j]=='#')cnt++;
		}
		getchar();
	}
	int flag=0;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++) if(map[i][j]=='#')
		{
			if(i!=0 && map[i-1][j]=='#') mrk[i][j]++;
			if(i<n-1 && map[i+1][j]=='#') mrk[i][j]++;
			if(j!=0 && map[i][j-1]=='#') mrk[i][j]++;
			if(j<m-1 && map[i][j+1]=='#') mrk[i][j]++;
			//cout<<mrk[i][j];
			if(mrk[i][j]==1) 
			{
				flag=1;
				break;
			}
		}
		//cout<<endl;
		if(flag)break;
	}
	if(cnt<=2)cout<<"-1"<<endl;
	else cout<<(flag?1:2)<<endl;
	return 0;
}


