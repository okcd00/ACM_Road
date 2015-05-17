#include <cmath> 
#include <cstdio>
#include <string>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
int n;
int tri[66666];

void tri_init()
{
	int i;
	tri[0]=0;
	for(i=1;tri[i]<n;i++)
	{
		tri[i]= (i*(i+1))/2;
		if(tri[i] > n || tri[i] < 0) return;
		//cout<<i<<":"<<tri[i]<<endl;
	}
}

bool find_it(int tmp)
{
	for(int i=1;;i++)
	{
		if(tri[i]==tmp)return true;
		if(tri[i]>tmp)return false;
	}
	return false;
}

bool solve(int n)
{
	for(int i=1;;i++)
	{
		int tmp=n-tri[i];
		if(find_it(tmp))return true;
		if(tmp<=0)return false;
	}
	return false;
}

int main()
{
	cin>>n;
	memset(tri,0,sizeof tri);
	tri_init();
	cout<<(solve(n)?"YES":"NO")<<endl;
	return 0;
}
