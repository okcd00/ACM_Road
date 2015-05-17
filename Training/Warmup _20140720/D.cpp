#include <cmath>   
#include <cstdio>  
#include <string>  
#include <cstring>  
#include <iostream>  
#include <algorithm>
using namespace std;
//int num[10]={1,4,4,2,1,1,4,4,2,1};
int main()
{
	int T;
	cin>>T;
	int ans2[4]={6,2,4,8},ans3[4]={1,3,9,7},ans7[4]={1,7,9,3},ans8[4]={6,8,4,2};
	int ans4[2]={6,4},ans9[2]={1,9};
	for(int i=0;i<T;i++)
	{
		int N;
		cin>>N;
		int r=N%10;
		switch(r)
		{
			case 0:
				cout<<"0"<<endl;
				break;
			case 1:
				cout<<"1"<<endl;
				break;
			case 2:
				cout<<ans2[N%4]<<endl;
				break;
			case 3:
				cout<<ans3[N%4]<<endl;
				break;
			case 4:	
				cout<<ans4[N%2]<<endl;
				break;
			case 5:
				cout<<"5"<<endl;
				break;
			case 6:
				cout<<"6"<<endl;
				break;
			case 7:
				cout<<ans7[N%4]<<endl;
				break;
			case 8:
				cout<<ans8[N%4]<<endl;
				break;
			case 9:
				cout<<ans9[N%2]<<endl;
				break;
		}
	}
	return 0;
} 
