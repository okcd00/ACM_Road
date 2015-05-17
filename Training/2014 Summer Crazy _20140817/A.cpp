#include <cmath> 
#include <cctype>
#include <cstdio>
#include <string>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
char csb[9][9];
#define Max(a,b) ((a)>(b)?(a):(b))
#define Min(a,b) ((a)<(b)?(a):(b))
#define gout {cout<<"NO";return 0;}

int main()
{
	int cnt;
	for(int i=1;i<=8;i++)
	{
		scanf("%c",&csb[i][1]);
		for(int j=2;j<=8;j++)
		{	
			scanf("%c",&csb[i][j]);
			if(csb[i][j]==csb[i][j-1]) gout
		}
		if(csb[i][8]==csb[i][1]) gout
		scanf("%c",&csb[i][0]);//huiche
	}
	cout<<"YES";
	return 0;
}
