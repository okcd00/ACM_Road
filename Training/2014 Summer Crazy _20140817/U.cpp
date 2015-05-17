#include <string>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
#define Max(a,b) ((a)>(b)?(a):(b))
#define Min(a,b) ((a)<(b)?(a):(b))

int judge(int a)
{
	for(int y=a+1;;y++)
	{
		int a=y/1000,
		b=(y/100)%10,
		c=(y/10)%10,
		d=y%10;
		if(a!=b&&b!=c&&c!=d&&a!=c&&b!=d&&a!=d)
		return y;
	}
	
}

int main()
{
	int y;	cin>>y;
	cout<<judge(y);
	return 0;
}
