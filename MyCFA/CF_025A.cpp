#include <iostream>
using namespace std;
int main()
{
	bool flag=false;
	int n=0,t=0,ans=0;
	int arr[101]; cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>t; arr[i]=(t%2+2)%2;
		if(i==2)
		{
			if((arr[0]+arr[1]+arr[2])%3==0) flag=true; //Same, Get Flag
			else 
			{
				if(arr[0]==arr[1]) ans = 2;
				if(arr[0]==arr[2]) ans = 1;
				if(arr[1]==arr[2]) ans = 0;
				ans++;
			}
		}
		if(flag && i>2 && arr[i]!=arr[0])
		{
			ans=i+1;
			flag = false;	
		}
	}
	cout<<ans<<endl;
	return 0;
}
