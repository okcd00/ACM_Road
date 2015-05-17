#include<cstdio>
#include<string>
#include<cstring>
#include<iostream>
using namespace std;

int main()
{
    int i=0,flag=0,n=0;
	string a;	cin>>a;	n=a.length();
    while(a[i]>=a[i+1] && i<n-1)	i++;    a[i]=1;
    for(i=0;i<=n-1;i++)	if(a[i]!=1)	printf("%c",a[i]);
    return 0;
}
