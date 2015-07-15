#include <map>
#include <cmath> 
#include <cctype>
#include <cstdio>
#include <string>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
//http://blog.csdn.net/okcd00/article/details/27366125
#define Max(a,b) ((a)>(b)?(a):(b))
#define Min(a,b) ((a)<(b)?(a):(b))

struct team
{
	int w,l;
	int score;
	string name;
	team(){w=0,l=0,score=0;}
} t[64];

map<string,team> mst;

bool cmp(const team &a, const team &b)
{
	if(a.score==b.score)
		if( (a.w-a.l)==(b.w-b.l) )
			return a.w>b.w;			
		else return (a.w-a.l)>(b.w-b.l);	
	else return a.score>b.score;
}

bool scmp(const team &a, const team &b)
{
	return a.name<b.name;
}

int main()
{
	int n=0;
	scanf("%d",&n);
	mst.clear();
	for(int i=0;i<n;i++)
	{
		cin>>t[i].name;
		mst[t[i].name].name=t[i].name;	
	} 
	int a=0,b=0;
	string battle,t1,t2;
	for(int i=0;i<(n-1)*n/2;i++)
	{	
		cin>>battle; 
		scanf("%d:%d",&a,&b);
		int div = battle.find('-');	//pos of '-'
		t1=battle.substr(0,div);
		t2=battle.substr(div+1,battle.length()-div-1);
		mst[t1].w+=a; mst[t2].w+=b;
		mst[t1].l+=b; mst[t2].l+=a;
		if(a==b)
		{
			mst[t1].score++;
			mst[t2].score++;
		}
		else if(a>b) mst[t1].score+=3;
		else mst[t2].score+=3;
	}
	int tpos=0;
	for(map<string,team>::iterator mit=mst.begin();mit!=mst.end();++mit)
	{
		t[tpos++] = mit->second;
		//cout<<t[tpos-1].name<<endl;
	}
	sort(t,t+n,cmp);
	sort(t,t+n/2,scmp);
	for(int i=0;i<n/2;i++) cout<<t[i].name<<endl;
	return 0;
}
