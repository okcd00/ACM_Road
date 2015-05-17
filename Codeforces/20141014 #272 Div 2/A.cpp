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

bool cmp(const int a, const int b)
{
	return a > b;
}

int main()
{
	int n,m;	cin>>n>>m;
	int steps=n%2+n/2;
	if(n==0){cout<<"0"; return 0;}
	if(steps%m!=0) steps+=(m-steps%m);
	if(steps>n) steps=-1;
	cout<<steps;	return 0;
}
