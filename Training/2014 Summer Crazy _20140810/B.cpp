#include <cmath> 
#include <cctype>
#include <cstdio>
#include <string>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
//Sorting Structures

int n=0;
char ss[40];

struct node
{
    int a,b,c;
    int number;
    char name[40];
}s[110];

bool j1()
{
	if(ss[0]==ss[1]&&ss[0]==ss[3]&&ss[3]==ss[4]&&ss[4]==ss[6]&&ss[6]==ss[7]) return true;
	else return false;
}

bool j2()
{
	if(ss[0]>ss[1]&&ss[1]>ss[3]&&ss[3]>ss[4]&&ss[4]>ss[6]&&ss[6]>ss[7])return true;
	else return false;
}

bool cmp1(node a,node b)	//By a
{
    if(a.a!=b.a) return a.a>b.a;
    else return a.number<b.number;
}

bool cmp2(node a,node b)	//By b
{
    if(a.b!=b.b) return a.b>b.b;
    else return a.number<b.number;
}
bool cmp3(node a,node b)	//By c
{
    if(a.c!=b.c) return a.c>b.c;
    else return a.number<b.number;
}

int main()
{
    while(scanf("%d",&n)!=EOF)
    {
    	int m;
        memset(s,0,sizeof(s));
        for(int i=0;i<n;i++)
        {
            scanf("%d%s",&m,s[i].name);
            
            s[i].number=i;
            for(int j=0;j<m;j++)
            {
                scanf("%s",ss);

                     if( j1() )	s[i].a++;
                else if( j2() )	s[i].b++;
                else			s[i].c++;
            }
        }

        sort(s,s+n,cmp1);
        printf("If you want to call a taxi, you should call: %s",s[0].name);
        for(int i=1;i<n&&s[i].a==s[i-1].a;i++) printf(", %s",s[i].name);
        printf(".\n");
        
		sort(s,s+n,cmp2);
        printf("If you want to order a pizza, you should call: %s",s[0].name);
        for(int i=1;i<n&&s[i].b==s[i-1].b;i++) printf(", %s",s[i].name);
        printf(".\n");
        
		sort(s,s+n,cmp3);
        printf("If you want to go to a cafe with a wonderful girl, you should call: %s",s[0].name);
        for(int i=1;i<n&&s[i].c==s[i-1].c;i++) printf(", %s",s[i].name);
        printf(".\n");

    }
    return 0;
}
