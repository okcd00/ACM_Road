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
inline int cmp (const In a, const In b){return strcmp( a.str , b.str );}

struct Point  
{   
	int x;   
	int y;   
}p[MAXN];   
  
// 按照 x 从小到大排序，当 x 相等时按照 y 从大到小排序   
int cmp2( const Point a , const Point b )
{   
	if(a.x != b.x) return a.x - b.x;   
	else return b.y - a.y;   
}   

int main()
{
	sort(s,s+MAXN,cmp);  
	sort(p,p+MAXN,cmp2); 
	return 0;	
} 
