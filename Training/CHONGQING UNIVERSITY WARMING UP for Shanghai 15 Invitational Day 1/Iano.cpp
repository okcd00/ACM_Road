#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <queue>
#include <map>
#include <iostream>
#include <sstream>
#include <algorithm>
using namespace std;
#define RD(x) scanf("%d",&x)
#define RD2(x,y) scanf("%d%d",&x,&y)
#define RD3(x,y,z) scanf("%d%d%d",&x,&y,&z)
#define clr0(x) memset(x,0,sizeof(x))
#define clr1(x) memset(x,-1,sizeof(x))
#define eps 1e-9
const double pi = acos(-1.0);
typedef long long LL;
const int maxn = 1050;
map <string , int> mp;
int ecnt,cnt;
int reboot[maxn],out[maxn],in[maxn];

struct edge{
    int v,next;
}e[maxn*maxn];

int head[maxn],vis[maxn];
void init()
{
    mp.clear();
    ecnt = cnt = 0;
    clr0(in),clr0(out),clr0(reboot);
    clr1(head),clr0(vis);
}

void add(int u,int v)
{
    e[ecnt].next = head[u];
    e[ecnt].v = v;
    head[u] = ecnt++;
}

int topo(){
    queue<int> q1,q2;// 不需要重启的进q1，需要的进q2
    for(int i = 1;i <= cnt;++i)if(in[i] == 0){
        if(reboot[i] == 0)
            q1.push(i);
        else
            q2.push(i);
    }
    int ans = 0;
    while(!q1.empty() || !q2.empty()){
        if(q1.empty() && !q2.empty()){
            ans++;
            while(!q2.empty()){
                q1.push(q2.front());
                q2.pop();
            }
        }
        while(!q1.empty()){
            int u = q1.front();q1.pop();
            vis[u] = 1;
            for(int i = head[u];i != -1;i = e[i].next){
                int v = e[i].v;
                in[v]--;
                if(in[v] == 0){
                    if(reboot[v] == 0)
                        q1.push(v);
                    else
                        q2.push(v);
                }
            }
        }
    }
    return ans;
}
int main()
{
    string s;
    char name[1050];
    int _,cas = 1;RD(_);getchar();getchar();
    while(_--)
    {
        init();
        while(getline(cin,s)){
            if(s[0] == '\0')
                break;
            istringstream sin(s);
            sin >> name;
            int len = strlen(name),flag = 0;
            if(name[len - 2] == '*'){
                flag = 1;
                name[len - 2] = '\0';
            }else
                name[len - 1] = '\0';
            string id = name,_id;
            if(mp.find(id) == mp.end())
                mp[id] = ++cnt;
            reboot[mp[id]] = flag;
            while(sin >> _id){
                if(mp.find(_id) == mp.end())
                    mp[_id] = ++cnt;
                add(mp[_id],mp[id]);
                out[mp[_id]]++;
                in[mp[id]]++;
            }
        }
        printf("Case %d: %d\n",cas++,topo());
    }
}

