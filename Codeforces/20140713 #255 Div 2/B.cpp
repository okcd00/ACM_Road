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
typedef __int64 ll;

string 	s;
int 	k,ans;
int 	w[27]; //0forMAX ,1~26


void init()
{
	
	for(int i=1;i<=26;i++)
	{
		scanf("%d",&w[i]);
		if(w[i]>=w[0])w[0]=w[i];
	}
}

void solve()
{
	int temp=0;
	temp += s.length()*2+k+1;// div2 & mulw[0]
	temp *= k;
	temp /= 2;
	temp *= w[0];
	//cout<<s.length()<<endl;
	//cout<<ans<<endl;
	//cout<<temp<<endl;
	ans+=temp;
}

int main()
{
	ans=0;
	memset(w,0,sizeof w);
	cin>>s>>k;
	init();
	for(int i=0;i<s.length();i++)
	{
		ans+= (i+1)*w[s[i]-'a'+1];
	}
	solve();
	printf("%d",ans);
	return 0;
}
