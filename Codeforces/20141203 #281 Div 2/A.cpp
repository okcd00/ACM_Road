#include <cmath> 
#include <cctype>
#include <cstdio>
#include <string>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
int hc[100]={0};
int ac[100]={0};
#define Max(a,b) ((a)>(b)?(a):(b))
#define Min(a,b) ((a)<(b)?(a):(b))

bool cmp(const int a, const int b)
{
	return a > b;
}

int main()
{
	string h,a;	cin>>h>>a;
	int n;	cin>>n;
	for(int i=0;i<n;i++)
	{
		int time,no;
		string w,c;
		cin>>time>>w>>no>>c;
		if(w=="a")
		{
			if(c=="r" && ac[no]!=-1)
			{
				ac[no]=-1;
				cout<<a<<" "<<no<<" "<<time<<endl;
			}
			else if(c=="y" && ac[no]==0)
			{
				ac[no]=time;
			}
			else if(c=="y" && ac[no]!=-1)
			{
				ac[no]=-1;
				cout<<a<<" "<<no<<" "<<time<<endl;
			}
		}
		else
		{
			if(c=="r" && hc[no]!=-1)
			{
				hc[no]=-1;
				cout<<h<<" "<<no<<" "<<time<<endl;
			}
			else if(c=="y" && hc[no]==0)
			{
				hc[no]=time;
			}
			else if(c=="y" && hc[no]!=-1)
			{
				hc[no]=-1;
				cout<<h<<" "<<no<<" "<<time<<endl;
			}
		}
	}
	
	return 0;
}
