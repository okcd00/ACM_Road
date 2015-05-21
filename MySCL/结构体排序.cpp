#include <queue>
#include <cstdio>
#include <string>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

#define MAXN 100

struct In 
{    
	int data;   
	char str[100];   
}s[MAXN];   
  
// 按照结构体中字符串str字典序排序   
int cmp ( const void *a , const void *b )   
{   
	return strcmp( (*(In *)a).str , (*(In *)b).str );   
}   

struct Point  
{   
	int x;   
	int y;   
}p[MAXN];   
  
// 按照 x 从小到大排序，当 x 相等时按照 y 从大到小排序   
int cmp2( const void *a , const void *b )
{   
	struct Point *c = (Point *)a;   
	struct Point *d = (Point *)b;   
	if(c->x != d->x) return c->x - d->x;   
	else return d->y - c->y;   
}   

int main()
{
	qsort(s,MAXN,sizeof(s[0]),cmp);  
	qsort(p,MAXN,sizeof(p[0]),cmp2); 
	return 0;	
} 
