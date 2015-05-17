#include <cmath>   
#include <vector>  
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
	int a1,a2,a3;
	int b1,b2,b3;
	int n;
	cin>>a1>>a2>>a3>>b1>>b2>>b3>>n;
	int c=a1+a2+a3;
	int m=b1+b2+b3;
	while(c+m)
	{
		if(c)
		{
			if(c>=5) c-=5,n--;
			else c=0,n--;
			
		}
		else
		{
			if(m)
			{
				if(m>=10) m-=10,n--;
				else m=0,n--;
			}
		}
		
		if(n<0) 
		{
			puts("NO");
			return 0;
		}
	}
	puts("YES");
	return 0;
}
