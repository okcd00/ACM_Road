#include <cmath> 
#include <cctype>
#include <cstdio>
#include <string>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int n,m;	cin>>n>>m;
	if(n==0&&m!=0){cout<<"Impossible"<<endl;return 0;}
	int minf= n + (m-n>0 ? (m-n) : 0);
	int maxf= n + (m-1>0 ? (m-1) : 0);
	cout<<minf<<" "<<maxf<<endl;
	return 0;
}
