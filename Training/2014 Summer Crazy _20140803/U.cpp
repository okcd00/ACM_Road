#include <cmath> 
#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int n,k;	cin>>n>>k;
	if(k>=n*3 && k<=n*5) cout<<0<<endl;
	else cout<<n*3-k<<endl;
	return 0;
}
