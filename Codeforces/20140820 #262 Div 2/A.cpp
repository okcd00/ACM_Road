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
	int n,m;	cin>>n>>m;
	int day=0;
	while(n)
	{
		day++, n--;
		if(day!=0 && day%m==0) n++;	
	}
	cout<< day <<endl;
	return 0;
}
