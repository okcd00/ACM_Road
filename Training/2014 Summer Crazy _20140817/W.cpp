#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
int n, k;
int main()
{
	cin>>n>>k;
	if(n/k>=3)
	{
		for (int i=1; i<=k; i++)	cout<<i<<" ";
		for (int i=0; i< k; i++)	cout<<(i==0?k:i)<<" ";
		for (int i=1; i<=k; i++)	cout<<i<<" ";
		for (int i=k*3+1; i<=n; i++)cout<<1<<" ";
	} 	else						cout<<-1;
    return 0;
}

