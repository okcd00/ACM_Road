#include <cmath>   
#include <vector>  
#include <cctype>  
#include <cstdio>  
#include <string>  
#include <cstdlib>  
#include <cstring>  
#include <iostream>  
#include <algorithm>  
#define update(x) ans=(x>ans)?x:ans
using namespace std;
int n,m,k,p;
int map[1001][1001];
int row[1001];
int col[1001];

int main()
{
	memset(map,0,sizeof map);
	memset(col,0,sizeof col);
	memset(row,0,sizeof row);
	cin>>n>>m>>k>>p;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		scanf("%d",&map[i][j]);
		row[i]+=map[i][j];
		col[j]+=map[i][j];
	}
	
	
	return 0;
}
