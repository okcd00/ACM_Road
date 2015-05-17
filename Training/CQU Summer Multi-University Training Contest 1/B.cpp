#include <cmath>
#include <cstdio>
#include <vector>
#include <string>
#include <memory>
#include <cstring>
#include <iostream>
#include <algorithm>
#define MAXN 505
using namespace std;
int vcat[101];
int vdog[101];

int map[101][101]; //Cat-Dog 1:like_C_dislike_D,-1:like_D_dislike_C


int main()
{
	int N,M,P;
	char huiche;
	while(scanf("%d%d%d",&N,&M,&P)!=EOF)
	{
		memset(vcat,0,sizeof vcat);
		memset(vdog,0,sizeof vdog);
		scanf("%c",&huiche); 
		for(int i=0;i<P;i++)
		{
			char k1,k2;
			int n1,n2;
			scanf("%c%d %c%d",&k1,&n1,&k2,&n2);
			scanf("%c",&huiche); 
			if(k1=='C') 
		}	
		
		cout<<;
	}
	return 0;
}



#include<iostream>
 #include<cstdio>
 #include<cstring>
 #include<string>
 #include<algorithm>
 using namespace std;

const int N=600;//N不能太大 否则超时
int cap[N][N];//初始化要清零
int _link[N];
 bool used[N];
 int nx,ny;//1->nx
 bool _find(int t)
 {
     for(int i=1;i<=ny;i++)

    if(!used[i]&&cap[t][i]==1)
     {
         used[i]=true;
         if(_link[i]==-1||_find(_link[i]))
         {
             _link[i]=t;
             return true;
         }
     }
     return false;
 }
 int MaxMatch()
 {
     int num=0;
     memset(_link,-1,sizeof(_link));
     for(int i=1;i<=nx;i++)
     {
         memset(used,false,sizeof(used));
         if(_find(i))   num++;
     }
     return num;
 }
 string a[600],b[600];
 //最大点独立集=P-最大匹配
//只有喜欢猫和喜欢狗的人会发生冲突,有用的总人数为p
 //如果两边发生冲突，则连一条边
//这样求的是最多不发生冲突的人个数,即最大点独立集
int main()
 {
     int n,m,p;
     while(scanf("%d%d%d",&n,&m,&p)==3)
     {
         for(int i=1;i<=p;i++)
         {
             cin>>a[i]>>b[i];
         }
         memset(cap,0,sizeof(cap));
         nx=ny=p;
         for(int i=1;i<=p;i++)
         {
             if(a[i][0]=='C')//喜欢猫的人
            for(int j=1;j<=p;j++)
             {
                 if(a[j][0]=='D')//喜欢狗的人
                if(a[i]==b[j]||a[j]==b[i])//如果发生冲突
                {
                     cap[i][j]=1;
                 }
             }
         }
         int ans=MaxMatch();
         printf("%d\n",p-ans);
     }
     return 0;
 }


/*
 struct Node 
 { 
     char str1[10]; 
     char str2[10]; 
 }cat[nMax], dog[nMax]; 
 int map[nMax][nMax]; 
 int useif[nMax]; 
 int link[nMax]; 
 int c, d, v; 
  
 int can(int t) 
 { 
     for(int i = 0; i < dog_num; ++ i) 
     { 
         if(!useif[i] && map[t][i]) 
         { 
             useif[i] = 1; 
             if(link[i] == -1 || can(link[i])) 
             { 
                 link[i] = t; 
                 return 1; 
             } 
         } 
     } 
     return 0; 
 } 
  
 int main() 
 { 

         cat_num = dog_num = 0; 
         scanf("%d %d %d", &c, &d, &v); 
         for(int i = 0; i < v; ++ i) 
         { 
             char a[10], b[10]; 
             scanf("%s %s", a, b); 
             if(a[0] == 'C') 
             {   
                 strcmp(cat[cat_num].str1, a); 
                 strcmp(cat[cat_num].str2, b); 
                 cat_num ++; 
             } 
             else 
             { 
                 strcmp(dog[dog_num].str1, a); 
                 strcmp(dog[dog_num].str2, b); 
                 dog_num ++; 
             } 
         } 
         for(int i = 0; i < cat_num; ++ i) 
             for(int j = 0; j < dog_num; ++ j) 
                 if(!strcmp(cat[i].str1, dog[j].str2) || !strcmp(cat[i].str2, dog[j].str1)) 
                     map[i][j] = 1; 
         int ans = 0; 
         memset(link, -1, sizeof(link)); 
         for(int i = 0; i < cat_num; ++ i) 
         { 
             memset(useif, 0, sizeof(useif)); 
             if(can(i)) ans++; 
         } 
         printf("%d\n",v - ans);     } 
     return 0; 
 } 
