#include <cmath> 
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
using namespace std;
int m,n,num;
double ans;

double quick_pow(double a,int n)
{
	if(n==1)return a;
	if(n%2==0) return quick_pow(a*a,n>>1);
	else return a*quick_pow(a*a,n>>1);
}

double calc()
{
	double tmp=0;
	for(int i=m-1;i>=0;i--)		tmp+= quick_pow((double)i/(double)m,n);
	return tmp;
}

int main()
{
	cin>>m>>n; 
	printf("%f",m-calc());
	return 0;
}
