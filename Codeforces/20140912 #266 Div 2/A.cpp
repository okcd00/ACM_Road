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
	int n,m,a,b;
	cin>>n>>m>>a>>b;
	cout<<min(a*n,min((n/m+1)*b,((n+m)%m)*a+(n/m)*b))<<endl;
	return 0;
}
