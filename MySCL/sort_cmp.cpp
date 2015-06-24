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
  
// ���սṹ�����ַ���str�ֵ�������   
inline int cmp (const In a, const In b){return strcmp( a.str , b.str );}

struct Point  
{   
	int x;   
	int y;   
}p[MAXN];   
  
// ���� x ��С�������򣬵� x ���ʱ���� y �Ӵ�С����   
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
