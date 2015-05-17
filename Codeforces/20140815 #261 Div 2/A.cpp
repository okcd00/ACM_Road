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
	int x1,y1,x2,y2,x3,y3,x4,y4,l;
	cin>>x1>>y1>>x2>>y2;
	if(x1==x2)
	{
		l=abs(y1-y2);
		x3=x4=(x1-l>=-1000?(x1-l):(x1+l));
		if(x3==x1+l && x1+l>1000)cout<<-1<<endl;
		else cout<<x3<<" "<<y1<<" "<<x4<<" "<<y2<<endl;
	}
	else if(y1==y2)
	{
		l=abs(x1-x2);
		y3=y4=(y1-l>=-1000?(y1-l):(y1+l));
		if(y3==y1+l && y1+l>1000)cout<<-1<<endl;
		else cout<<x1<<" "<<y3<<" "<<x2<<" "<<y4<<endl;
	}
	else
	{
		if(abs(x1-x2)!=abs(y1-y2))cout<<-1<<endl;
		else cout<<x1<<" "<<y2<<" "<<x2<<" "<<y1<<endl;
	}
	return 0;
}
