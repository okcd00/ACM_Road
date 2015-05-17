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

bool cmp(const int a, const int b)
{
	return a > b;
}

void judge(string a,string b)
{
	if(a>b) printf(" >");
	else if(a<b) printf(" <");
	else printf(" =");
} 

int main()
{
	int cases=0;
	scanf("%d",&cases);
	for(int _case=1;_case<=cases;_case++)
	{
		string a,b;	cin>>a>>b;
		string	ra=a.substr(0,1),
				rb=b.substr(0,1);
		string	da=a.substr(2,3),
				db=b.substr(2,3),
				_da=a.substr(2,4),
				_db=b.substr(2,4);
		printf("Case %d:",_case);
		judge(ra,rb);
		if(a[1]==b[1]) judge(_da,_db);
		else judge(da,db);
		printf("\n");
	}
	return 0;
}
