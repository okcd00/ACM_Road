#include <cstdio>  
#include <string>
#include <cstring>  
#include <iostream>  
//http://blog.csdn.net/okcd00/article/details/27373475
using namespace std;  
  
int main()   
{
	string s,ans=""; 
	cin>>s; 
	int len=s.length();
	while(s[len-1]=='/')len--;
	s=s.substr(0,len);
	for(int i=0;i<len;i++)
	{
		if(s[i]!='/') ans=ans+s[i];
		else if(i+1<len && s[i+1]!='/') ans=ans+s[i];
	}
	if(ans.length()==0)cout<<'/'<<endl;
	else cout<<ans<<endl;
	return 0;  
}  
