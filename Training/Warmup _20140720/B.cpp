#include <cmath>   
#include <queue>
#include <vector>
#include <cstdio>  
#include <string>  
#include <cstring>  
#include <iostream>  
#include <algorithm>
using namespace std;
const int inf=99999;
const int _sign=89757;
int main()
{
	int T;
	cin>>T;
	for(int cs=1;cs<=T;cs++)
	{
		int n;
		cin>>n;
		priority_queue <pair<int, int> > pq;
		queue < pair<int, int> > q;
		for(int ns=0;ns<n;ns++)//sort in pq
		{
			pair<int,int> tmp;
			cin>>tmp.first>>tmp.second;
			pq.push(tmp);
		}
		while(!pq.empty())//trans into q
		{
			pair<int,int> tmp=pq.top();
			q.push(tmp);
			pq.pop();
		}
		q.push(make_pair(_sign,_sign));
		int len=inf,wht=inf,ans=0;
		pair<int,int> temp;
		while(1)
		{
			temp=q.front();q.pop();
			//cout<<"#"<<temp.first<<"\t"<<temp.second<<endl;
			if(temp.first==_sign&&temp.second==_sign)
			{
				if(len==inf&&wht==inf){break;}
				len=wht=inf;
				q.push(temp);
				ans++;
			}
			else if(temp.first<=len&&temp.second<=wht)
			{
				len=temp.first;
				wht=temp.second;
			}
			else q.push(temp);
			//cout<<temp.first<<"\t"<<temp.second<<endl;
		}
		cout<<ans<<endl;
	}	
	return 0;
} 
