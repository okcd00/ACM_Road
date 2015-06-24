#include<map>
#include<vector>
#include<cstdio>
#include<string>
#include<cstring>
#include<cstdlib>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
map<pii,int> obs;	//at pos(x,y) 0x1111 means uldr
map<pii,int> rec;	//states record
map<int,vector<int> > col_rec;
map<int,vector<int> > row_rec;

int main()
{
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		int dir=0;	//3-up 2-left 1-down 0-right
		obs.clear();
		rec.clear();
		col_rec.clear();
		row_rec.clear();
		for(int i=0;i<n;i++)
		{
			int x,y;
			scanf("%d%d",&x,&y);
			obs[make_pair(x,y)]=1;
			col_rec[x].push_back(y);
			row_rec[y].push_back(x);
		}
		map<int,vector<int> >::iterator it;
		for(it=col_rec.begin();it!=col_rec.end();++it) sort(it->second.begin(),it->second.end());
		for(it=row_rec.begin();it!=row_rec.end();++it) sort(it->second.begin(),it->second.end());
		
		//rec[make_pair(0,0)] &= 0x0001;	first state
		pair<int,int> sta=make_pair(0,0);
		int pos=0,ans=0;
		while(1)
		{
			if(rec[sta]&(1<<dir)) {ans=-1;break;}
			else rec[sta] &= (1<<dir);
			if(dir==0)
			{
				int pos= *upper_bound(row_rec[sta.second].begin(),row_rec[sta.second].end(),sta.first);
				if(pos==*row_rec[sta.second].end()) break;
				else 
				{
					sta= make_pair(pos-1,sta.second);
					dir=(dir+1)%4;
				}
			}
			else if(dir==1)
			{
				int pos= *upper_bound(col_rec[sta.first].begin(),col_rec[sta.first].end(),sta.second);
				if(pos==*col_rec[sta.first].end()) break;
				else 
				{
					vector<int>::iterator vit= upper_bound(col_rec[sta.first].begin(),col_rec[sta.first].end(),sta.second);
					--vit;
					sta= make_pair(sta.first,pos-1);
					dir=(dir+1)%4;
				}
			}
			else if(dir==2)
			{
				int pos= *upper_bound(row_rec[sta.second].begin(),row_rec[sta.second].end(),sta.first);
				if(pos==*row_rec[sta.second].begin()) break;
				else 
				{
					vector<int>::iterator vit= upper_bound(row_rec[sta.second].begin(),row_rec[sta.second].end(),sta.first);
					--vit;
					sta= make_pair(*vit+1,sta.second);
					dir=(dir+1)%4;
				}
			}
			else
			{
				int pos= *upper_bound(col_rec[sta.first].begin(),col_rec[sta.first].end(),sta.second);
				if(pos==*col_rec[sta.first].end()) break;
				else 
				{
					sta= make_pair(sta.first,pos+1);
					dir=(dir+1)%4;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}

