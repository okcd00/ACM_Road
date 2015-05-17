#include <cmath> 
#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int n;
	cin>>n;
	int mid=n/2;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(abs(j-mid)<=mid-abs(mid-i))cout<<'D';
			else cout<<'*';
		}
		cout<<endl;
	}
	
	return 0;
}
