#include <cstdio>  
#include <iostream>  
#include <algorithm>  
using namespace std;  
typedef pair<char,int> pl;  
//http://blog.csdn.net/okcd00/article/details/22693405
#define max(a,b) a>b?a:b  
#define min(a,b) a<b?a:b  
  
int main()  
{  
	pl src,dsn;  
	cin>>src.first>>src.second;  
 	cin>>dsn.first>>dsn.second;  
	int rx= src.first-dsn.first;  
	int dy= src.second-dsn.second;  
	int maxv= rx>dy?rx:dy;  
	int minv= rx<dy?rx:dy;  
  
	if(src.first==dsn.first && dsn.first==dsn.second)
	{ 
    	cout<<"0";  
		return 0;  
	}  
	int mxv=max(abs(maxv),abs(minv)); //之前一直是mxv=maxv,坑惨了   
	cout<<mxv;  
	char x,y;  
	for(int i=0;i<mxv;i++)  
	{  
		if(rx!=0||dy!=0)cout<<endl;  
    	if(rx!=0)
		{  
        	cout<<((rx>0)?"L":"R");  
            (rx>0)?rx--:rx++;  
        }  
        if(dy!=0)  
		{  
        	cout<<((dy>0)?"D":"U");  
            (dy>0)?dy--:dy++;  
        }              
	}  
 	return 0;  
}  
