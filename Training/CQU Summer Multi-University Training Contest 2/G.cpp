#include <cmath>
#include <queue>
#include <cstdio>
#include <vector>
#include <string>
#include <memory>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
typedef pair<int,int> pii;

//For each case:
//The first line has one integer X, represent the number of ¡°Trouble Rectangle¡±.
//Following X line, each line output for integers xi1, yi1, xi2 and yi2, representing
// the coordinate of the top-left and bottom-right points. Output the one with smallest xi1 first,
// if there¡¯s a tie, output the smallest yi1 first.

//OMG! This kind of output??? Mean what?

int n,m;
queue<pii> Q;
int map1[55][55];
int map2[55][55];
int mark[55][55];
bool vis[55][55];
int x_1[55],x_2[55],y_1[55],y_2[55];
int dir[8][2]={{-1,-1},{-1,0},{-1,1},{0,1},{1,1},{1,0},{1,-1},{0,-1}};

bool Judge(int x,int y)
{
    if(x>=1&&x<=n&&y>=1&&y<=m)  return true;
    return false;
}

void do_sth(int dx,int dy,int& si,int& sj,int& ei,int& ej)
{
    int i=0;
    Q.push(make_pair(dx,dy));
    if(dx<si||dx>ei)
    {
        for(i=sj;i<=ej;i++)
            Q.push(make_pair(dx,i));
    }
    if(dy<sj||dy>ej)
    {
        for(i=si;i<=ei;i++)
            Q.push(make_pair(i,dy));
    }
    si=min(si,dx);
    sj=min(sj,dy);
    ei=max(ei,dx);
    ej=max(ej,dy);
}

void getrect(int ii, int jj, pii& sta_point, pii& end_point)
{
	int ei=ii,ej=jj,si=ii,sj=jj;
	bool ep_flag=false;
	pii  sp=make_pair(ii,jj);
	memset(vis,false,sizeof vis);
	while(!Q.empty())Q.pop();
	Q.push(sp);
    while(!Q.empty())
    {
    	int x=Q.front().first;
    	int y=Q.front().second;
    	Q.pop();
    	for(int i=0;i<8;i++)
    	{
   	     	int dx=x+dir[i][0];
   	       	int dy=y+dir[i][1];
           	if(Judge(dx,dy)&&!vis[dx][dy])
           	{
           		vis[dx][dy]=true;
           		if(mark[dx][dy]==1)
           		{
           	    	do_sth(dx,dy,si,sj,ei,ej);
           		}
           	}
        }
    }
	/*	
		bool imark=false,jmark=false;
		if(ej<m) for(int _i=i;_i<=ei+1;_i++)
		{
			if(mark[_i][ej+1]==1) jmark=true;
		}
		if(ei<n) for(int _j=j;_j<=ej+1;_j++)
		{
			if(mark[ei+1][_j]==1) imark=true;
		}
		ep_flag=(imark==false && jmark==false);
		ei+= imark?1:0;
		ej+= jmark?1:0;
	*/
	sta_point=make_pair(si,sj);
	end_point=make_pair(ei,ej);
	for(int _i=si;_i<=ei;_i++)	for(int _j=sj;_j<=ej;_j++)	mark[_i][_j]=0;
	
}

int rcmp(const int &i,const int &j){                     
    return x_1[i]!=x_1[j]?x_1[i]<x_1[j]:                   
                    ( x_2[i]!=x_2[j]?x_2[i]<x_2[j]            
                        : y_1[i]!=y_1[j]?y_1[i]<y_1[j] 
							:y_2[i]!=y_2[j]?y_2[i]<y_2[j] :i<j);     
}

bool in(int x,int y, int j) // if(x,y) is in Rect[J]
{
	if(x<=x_2[j] && x>=x_1[j])
	if(y<=y_2[j] && y>=y_1[j]) return true;
	return false;
}

int Check(int i,int j)
{
	if(in(x_1[i],y_1[i],j) || in(x_2[i],y_2[i],j) )return 1;
	if(in(x_2[i],y_1[i],j) || in(x_1[i],y_2[i],j) )return 1;
	return 0;
}

int main()
{
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		//init
		memset(map1,-1,sizeof map1);
		memset(map2,-1,sizeof map2);
		memset(mark, 0,sizeof mark);
		memset(vis,false,sizeof vis);
		int cnt=0;vector< pair<pii,pii> > ans; //for sorting
		ans.clear();
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				scanf("%d",&map1[i][j]); 
			}
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				scanf("%d",&map2[i][j]); 
				if(map2[i][j]!=map1[i][j]) mark[i][j]=1;
			}
		}
		
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				if(mark[i][j]<1)continue;
				else
				{
					pii sta_point,end_point;
					getrect(i,j,sta_point,end_point);
					ans.push_back( make_pair(sta_point,end_point) );
					cnt++;
				}
			}
		}
		//qsort(ans.begin(),ans.end(),badcmp); DEAD
		//qsort(rect,cnt,sizeof(rect[0]),cmp); 
		memset(x_1,-1,sizeof x_1);
		memset(x_2,-1,sizeof x_2);
		memset(y_1,-1,sizeof y_1);
		memset(y_2,-1,sizeof y_2);
		for(int i=0;i<cnt;i++)
		{
			x_1[i+1]=ans[i].first.first;
			y_1[i+1]=ans[i].first.second;
			x_2[i+1]=ans[i].second.first;
			y_2[i+1]=ans[i].second.second;
		}
		int list[55];
		memset(list,0,sizeof list);
		//Thanks to bluewind001 find this£º///////
		int cnt_dec=0;
		for(int i=1;i<cnt;i++)
		{
			for(int j=i+1;j<=cnt;j++)
			if( Check(i,j) )
			{
				x_1[i]=min(x_1[i],x_1[j]);
				y_1[i]=min(y_1[i],y_1[j]);
				x_2[i]=max(x_2[i],x_2[j]);
				y_2[i]=max(y_2[i],y_2[j]);
				x_1[j]=x_2[j]=y_1[j]=y_2[j]=-1;
				cnt_dec++;
			}
		} 
		///////////////////////////////////////////
		for(int i=1;i<=cnt;i++)list[i]=i;
		sort(list+1,list+cnt,rcmp);
		cout<<cnt-cnt_dec<<endl;
		for(int i=1;i<=cnt;i++)
		{
			if(x_1[list[i]]==-1)continue;
			cout<<x_1[list[i]]<<' '<<y_1[list[i]]<<' ';
			cout<<x_2[list[i]]<<' '<<y_2[list[i]]<<endl;
		}
		
	}
	return 0;
} 


