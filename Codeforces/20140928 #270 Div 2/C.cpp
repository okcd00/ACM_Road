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
typedef pair<string,int> psi;
#define Max(a,b) ((a)>(b)?(a):(b))
#define Min(a,b) ((a)<(b)?(a):(b))

struct cmp
{  
    bool operator()(psi a,psi b) 
    {  
        if(a.first!=b.first)
            return a.first>b.first;  
    }  
};  


priority_queue <psi,vector<psi>,cmp> p_q;

int main()
{
	int n;	cin>>n;
	for(int i=1;i<=n;i++)
	{
		string s1,s2;
		cin>>s1>>s2;
		p_q.push(psi(s1,i));
		p_q.push(psi(s2,i));
	}
	//cout<<p_q.top().first<<"\t"<< p_q.top().second<<endl;
	for(int i=1;i<=n;i++)
	{
		int pos;	cin>>pos;
		while(!p_q.empty() && p_q.top().second!=pos) p_q.pop();
		if(p_q.empty())
		{
			cout<<"NO"<<endl;
			return 0;
		}
		p_q.pop();
	}
	cout<<"YES"<<endl;
	return 0;
}
