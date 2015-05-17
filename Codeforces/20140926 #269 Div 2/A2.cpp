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

#define Max(a,b) ((a)>(b)?(a):(b))
#define Min(a,b) ((a)<(b)?(a):(b))

bool cmp(const int a, const int b){return a > b;}


int main()
{
	int l[6]; 
	for(int i=0;i<6;i++)
	{
		scanf("%d",&l[i]);
	}
	sort(l,l+6);
	if(count(l,l+6,l[0])>=4)
	{
		if(l[4]==l[5]) cout<<"Elephant"<<endl;
		if(l[4]< l[5]) cout<<"Bear"<<endl;
	}
	else if(count(l,l+6,l[1])>=4)
	{
		cout<<"Bear"<<endl;
	}
	else if(count(l,l+6,l[2])>=4)
	{
		if(l[0]==l[1]) cout<<"Elephant"<<endl;
		if(l[0]< l[1]) cout<<"Bear"<<endl;
	}
	else cout<<"Alien"<<endl;
	return 0;
}
