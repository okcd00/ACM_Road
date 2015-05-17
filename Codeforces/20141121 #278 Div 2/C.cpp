#include <cmath> 
#include <cctype>
#include <cstdio>
#include <string>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
#define Max(a,b) ((a)>(b)?(a):(b))
#define Min(a,b) ((a)<(b)?(a):(b))

int hy=0,ay=0,dy=0;
int hm=0,am=0,dm=0;
int h=0,a=0,d=0,minc=33333;
int hyy=0,ayy=0,dyy=0;

bool cmp(const int a, const int b)
{
	return a > b;
}

bool judge(int i,int j,int k)
{
	hyy=ay+i,ayy=ay+j,dyy=dy+k;
	if(ayy> dm && dyy>=am) return true;
	if(ayy<=dm && dyy>=am) return false;
	if(ayy<=dm && dyy< am) return false;
	int hity=hyy/(am-dyy);	if(hyy%(am-dyy)!=0) hity++;
	int hitm=hm /(ayy-dm);	if(hm %(ayy-dm)!=0) hitm++;
	if(hity > hitm) return true;
	return false;
}

int main()
{
	cin>>hy>>ay>>dy;
	cin>>hm>>am>>dm;
	cin>>h>>a>>d;
	minc=33333;
	for(int i=0;i<100;i++)
	{
		if(judge(i-1,0,0))
		{
			minc=min(minc,h*i);
			//cout<<i<<":"<<minc<<endl;
			break;
		}
		for(int j=0;j<100;j++)
		{
			if(judge(i-1,j,0))
			{
				minc=min(minc,h*i+a*j);
				//cout<<i<<":"<<j<<":"<<minc<<endl;
				break;
			}
			for(int k=0;k<100;k++)
			{
				if(judge(i-1,j,k))
				{
					minc=min(minc,h*i+a*j+d*k);
					//cout<<i<<":"<<j<<":"<<k<<":"<<minc<<endl;
					break;
				}
			}
		}
	}
	cout<<minc<<endl;
	//cout<<hy<<":"<<ay<<":"<<dy<<endl;
	//cout<<hy1<<":"<<ay1<<":"<<dy1<<endl;
	return 0;
}
