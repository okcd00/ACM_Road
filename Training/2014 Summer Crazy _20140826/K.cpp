#include <cstdio>
#include <string>
#include <cstring>
#include <iostream>
#include <algorithm> 
using namespace std;
int main()
{
	int cnt=0;
	char a[1000+10];
	while (scanf("%s", a)!=EOF)
	{
		int len = strlen(a); 
		if (islower(a[0])) printf("%c", a[0]-32);
		else printf("%c", a[0]);
		for (int i = 1; i < len; ++i){ printf("%c", a[i]);}
		printf("\n");
		cnt++;
	}
  	return 0;
}
