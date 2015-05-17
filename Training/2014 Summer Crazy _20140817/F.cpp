#include<iostream>
using namespace std;

int main()
{
	int t=-1;
    int a,b,n;
    cin>>a>>b>>n;
    for(int i=0;i<=9;i++) if((a*10+i)%b==0)
	{
		t=i;
		break;
	}
    if(t==-1)cout<<-1;
    else 
    {
        cout<<a<<t;
        for(int i=2;i<=n;i++)cout<<0;
    }
    return 0;
}
