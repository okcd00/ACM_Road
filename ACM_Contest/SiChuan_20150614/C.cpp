#include <cmath> 
#include <cctype>
#include <cstdio>
#include <string>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
const int N=5000050;
typedef pair<int,int> pii;
#define Max(a,b) ((a)>(b)?(a):(b))
#define Min(a,b) ((a)<(b)?(a):(b))
int pre[N], nxt[N];
char s[N], t[N], sta[N];

int main()
{
	while (~scanf("%s",s+1)) 
	{
		scanf("%s",t+1);
		int ls=strlen(s+1),
			lt=strlen(t+1);
		memset(pre,0,sizeof pre);
		memset(nxt,0,sizeof nxt);
		int top=0,j=0;
		for(int i=2;i<=ls;i++)
		{
			while (j>0 && s[i]!=s[j+1]) j=nxt[j];
			if(s[i]==s[j+1]) j++;
			nxt[i]=j;
		}
		for(int i=1;i<=lt;i++)
		{
			sta[++top]=t[i];
			if (sta[top]==s[pre[top-1]+1])	
				pre[top]=pre[top-1]+1;
			else 
			{
				j=pre[top-1];
				while (j>0 && s[j+1]!=sta[top]) j=nxt[j];
				if (s[j+1]==sta[top]) j++;
				pre[top]=j;
			}
			if (pre[top]==ls) top-=ls;
		}
		//sta[++top]='\0';
		for(int i=1;i<top+1;i++) putchar(sta[i]);
		puts("");
	}
	return 0;
}



