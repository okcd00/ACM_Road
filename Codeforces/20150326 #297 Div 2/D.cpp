#include <bits/stdc++.h>
//Code By cikofte@Codeforces

#include <cmath> 
#include <queue>
#include <cctype>
#include <cstdio>
#include <string>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
#define	st first
#define	nd second
#define	mp make_pair
#define	pb push_back
#define Max(a,b) ((a)>(b)?(a):(b))
#define Min(a,b) ((a)<(b)?(a):(b))

#define	ctrl( xx,yy )	( xx>=1 and yy>=1 and xx<=m and yy<=n and s[xx][yy]=='.' )

using namespace std;

int	m,n;
char	s[3000][3000];
char	h[3000][3000];

int	bozuk( int x,int y )	//Bad mood .Turkey
{
	if( s[x][y]!='*' )	return	0;
	if( ctrl( x-1,y ) and ctrl( x-1,y+1 ) and ctrl( x,y+1 ) )	return	1;
	if( ctrl( x,y+1 ) and ctrl( x+1,y+1 ) and ctrl( x+1,y ) )	return	1;
	if( ctrl( x+1,y ) and ctrl( x+1,y-1 ) and ctrl( x,y-1 ) )	return	1;
	if( ctrl( x,y-1 ) and ctrl( x-1,y-1 ) and ctrl( x-1,y ) )	return	1;
	return	0;
}

int main()
{
	cin>>m>>n;
	for(ll i=1;i<=m;i++)	scanf("%s",s[i]+1);
	queue< pair<int,int> >	Q;
	for(ll i=1;i<=m;i++)
		for(ll j=1;j<=n;j++)
			if( bozuk( i,j ) )	Q.push( mp(i,j) ), h[i][j]=1;
	int	x,y,xx,yy;
	while( Q.size() )
	{
		x = Q.front().st;
		y = Q.front().nd;
		Q.pop();
		s[x][y] = '.';
		h[x][y] = 0;
		for(ll i=-1;i<=1;i++)
			for(ll j=-1;j<=1;j++)
			{
				if( !i and !j )	continue;
				xx = x+i;
				yy = y+j;
				if( xx<1 or xx>m or yy<1 or yy>n 
					or h[xx][yy] or !bozuk( xx,yy ) )	continue;
				Q.push( mp(xx,yy) ), h[xx][yy] = 1;
				s[xx][yy] = '.';
			}
	}
	for(ll i=1;i<=m;i++) printf("%s\n",s[i]+1);
	return 0;
}
