#include <cmath>
#include <cstdio>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#define maxn 100010
#define LL long long
using namespace std;

bool vis[maxn];
bool npm[maxn] = {true,true};
int prime[maxn],index[maxn],tot = 0;
vector <int> pm[maxn];

void getprime() 
{
    int i,j,temp;
    for(i = 2; i < maxn; i++) 
	{
        if(!npm[i]) prime[tot++] = i;
        for(j = 0; j < tot && (temp = i*prime[j]) < maxn; j++) 
		{
            npm[temp] = true;
            if(i%prime[j] == 0) break;
        }
    }
    for(i = 2; i < maxn; i++) 
	{
        if(!npm[i]) pm[i].push_back(i);
        else 
		{
            int t = sqrt(i),k = i;
            for(j = 0; j < tot && prime[j] <= t; j++) 
			{
                if(k%prime[j] == 0) 
				{
                    pm[i].push_back(prime[j]);	//divisors division
                    while(k && k%prime[j] == 0) k /= prime[j];
                }
            }
            if(k > 1) pm[i].push_back(k);
        }
    }
}

void del(int u)
{
    for(int i = 0; i < pm[u].size(); i++)	index[pm[u][i]] = -1;
}

bool calc(int x,int &op) 
{
    int i,j;
    bool flag = true;
    for(i = 0; i < pm[x].size(); i++) 
	{
        if(index[pm[x][i]] > 0) 
		{
            flag = false;
            op = index[pm[x][i]];
            break;
        }
    }
    if(flag)	for(i = 0; i < pm[x].size(); i++)	index[pm[x][i]] = x;
    return flag;
}
int main() 
{	
	char s[4];
    int n,m,id,i;
    getprime();
    while( ~scanf("%d %d",&n,&m) )
	{
        memset(vis,false,sizeof(vis));
        memset(index,-1,sizeof(index));
        for(i = 0; i < m; i++)
		{
            scanf("%s %d",s,&id);
            if(id == 1)
			{
                if(s[0] == '+')
				{
                    if(vis[id]) puts("Already on");
                    else {vis[id] = true;	puts("Success");}
                }
				else
				{
                    if(vis[id]) {vis[id] = false;	puts("Success");}
                    else puts("Already off");
                }
            }
			else
			{
                if(s[0] == '+')
				{
                	if(vis[id]) puts("Already on");
            		else
					{
                		int conflic;
                    	if(calc(id,conflic))
						{
                        	vis[id] = true;
                        	puts("Success");
                    	}
						else printf("Conflict with %d\n",conflic);
                	}
                }
				else
				{
                    if(vis[id]) {del(id);	vis[id] = false;	puts("Success");}
                    else puts("Already off");
                }
            }
        }
    }
    return 0;
}
