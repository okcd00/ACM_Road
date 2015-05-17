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
string s,t;

int main()
{
	int pos=0;
	cin>>s>>t;
	for(int i=0;i<t.length();i++)
		if(pos!=s.length()-1 && s[pos]==t[i])pos++;
	cout<<pos+1;
	return 0;
}
