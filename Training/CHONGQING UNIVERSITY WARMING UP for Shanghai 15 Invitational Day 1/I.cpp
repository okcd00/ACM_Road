#include <map>
#include <queue>
#include <cmath> 
#include <cctype>
#include <cstdio>
#include <string>
#include <cstdlib>
#include <cstring>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;

#define Max(a,b) ((a)>(b)?(a):(b))
#define Min(a,b) ((a)<(b)?(a):(b))

map <string,int> mp;
int ecnt,cnt;
int reboot[1024]={0},
	out[1024]={0},
	in[1024]={0};

struct edge
{
    int v;
	int next;
}e[1024*1024];

int head[1024]={0},vis[1024]={0};

void all_init()
{
    mp.clear();
    ecnt = cnt = 0;
    memset(in,0,sizeof in);
    memset(out,0,sizeof out);
    memset(reboot,0,sizeof reboot);
    memset(head,-1,sizeof head);
    memset(vis,-1,sizeof vis);
}

void add(int u,int v)
{
    e[ecnt].next = head[u];
    e[ecnt].v = v;
    head[u] = ecnt++;
}

int tp() //double queue topology
{
    queue<int> q1,q2; 
    for(int i = 1;i <= cnt;++i)if(in[i] == 0)
	{
        if(reboot[i] == 0) q1.push(i);
        else q2.push(i);
    }
    int ans = 0;
    while(!q1.empty() || !q2.empty())
	{
        if(q1.empty() && !q2.empty())
		{
            ans++;
            while(!q2.empty())
			{
                q1.push(q2.front());
                q2.pop();
            }
        }
        while(!q1.empty())
		{
            int u = q1.front();
			q1.pop();
            vis[u] = 1;
            for(int i = head[u];i != -1;i = e[i].next)
			{
                int v = e[i].v;
                in[v]--;
                if(in[v] == 0)
				{
                    if(reboot[v] == 0) q1.push(v);
                    else q2.push(v);
                }
            }
        }
    }
    return ans;
}
int main()
{
	string s;
    char name[1050];	//software_name
    int css, cas = 1;
	scanf("%d",&css);
	getchar(); getchar();	//another blank
    for(int i=0;i<css;i++)
    {
        all_init();
        while(getline(cin,s))
		{
            if(s[0] == '\0') break;
            istringstream sin(s); sin>>name;
            int len = strlen(name), flag = 0;
            if(name[len-2]=='*')
			{
                flag = 1;
                name[len-2]='\0';
            }else name[len-1]='\0';
            
            string id = name, _id;
            if(mp.find(id) == mp.end()) 
				mp[id] = ++cnt;
            reboot[mp[id]] = flag;
            
            while(sin >> _id)
			{
				cout<<"Now is SW:"<<_id<<endl;
                if(mp.find(_id) == mp.end())
                    mp[_id] = ++cnt;
                add(mp[_id],mp[id]);
                out[mp[_id]]++;
                in[mp[id]]++;
            }
        }
        printf("Case %d: %d\n", cas++, tp());
    }
    return 0;
}
