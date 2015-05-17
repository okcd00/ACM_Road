#include <stack>
#include <queue>
#include <cmath> 
#include <cctype>
#include <cstdio>
#include <string>
#include <vector>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

int hor[]={0, 1, 2, 3, 4, 5,10,11,12,13,14,15,20,21,22,23};
int mie[]={0,10,20,30,40,50,1 ,11,21,31,41,51, 2,12,22,32};

int main()
{
	char maohao;
	int h,m;
	cin>>h>>maohao>>m;
	for(int i=0;i<16;i++)
	{
		if((hor[i]==h && mie[i]>m) || hor[i]>h)
		{
			if(hor[i]<10)cout<<"0";
			cout<<hor[i]<<":";
			if(mie[i]<10)cout<<"0";
			cout<<mie[i]<<endl;
			return 0;
		}
	}
	cout<<"00:00"<<endl;
	return 0;
} 
