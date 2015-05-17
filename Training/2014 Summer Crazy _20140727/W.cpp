/*
#include <stack>
#include <queue>
#include <cmath> 
#include <cctype>
#include <cstdio>
#include <string>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
int fs [18]={0, 1, 0, 2, 1, 3, 0, 2, 4, 3, 5, 0, 2, 4, 6, 1, 3, 5};//four s
int ss [18]={0, 0, 1, 0, 1, 0, 2, 1, 0, 1, 0, 3, 2, 1, 0, 3, 2, 1};//seven s
int sup[18]={0, 4, 7, 8,11,12,14,15,16,19,20,21,22,23,24,25,26,27};


int main()
{
	int n; cin>>n;
	int _m=n/28,m=n%28;
	int cnt4=0,cnt7=4*_m;
	if(n<11)
	{
		if(n==4||n==7)cout<<n;
		cout<<"-1";
		return 0;
	}
	for(int i=0;i<18;i++)
	{
		if(m==sup[i])
		{
			cnt4+=fs[i];
			cnt7+=ss[i];
			for(int j=0;j<cnt4;j++)cout<<"4";
			for(int k=0;k<cnt7;k++)cout<<"7";
			return 0;
		}
	}
	cout<<"-1";
	return 0;
} 
*/

#include<cstdio>
#include<string>
#include<cstring>
#include<iostream>
using namespace std;
int n,i,j,k,flag,sum;
int main()
{
	int s4,s7;	cin>>n;
	s4=n/4; s7=n/7;
	for(i=0;i<=s4;i++)
	{
		for(j=0;j<=s7;j++)	if(i*4+j*7==n)
		{
				flag=1;
				break;
		}
		if(flag)  break;
	}
	if(!flag)		cout<<-1<<endl;
	else
	{
		for(k=1;k<=i;k++)			printf("4");
		for(k=1;k<=j;k++)			printf("7");
		printf("\n");
	}

	return 0;
}
