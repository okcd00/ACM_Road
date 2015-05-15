#include <queue>
#include <cstdio>
#include <string>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
#define Maxn 500010	//Max number of n 
#define bk 26 //Branch-kind number

struct Trie	//AcMachine Trie Tree 
{
    int next[Maxn][bk], fail[Maxn], end[Maxn];
    int root,L;
    int newnode()
    {
        for(int i=0;i<bk;i++) next[L][i]=-1;	//init *Next
        end[L++] = 0;
        return L-1;
    }
    void init()
    {
        L = 0;
        root = newnode();
    }
    void insert(char buf[])
    {
        int len = strlen(buf);
        int now = root;
        for(int i = 0;i < len;i++)
        {
            if(next[now][buf[i]-'a'] == -1)
                next[now][buf[i]-'a'] = newnode();
            now = next[now][buf[i]-'a'];
        }
        end[now]++;
    }
    void build()
    {
        queue<int> Q;
        fail[root] = root;
        for(int i = 0;i < bk;i++)
            if(next[root][i] == -1)
                next[root][i] = root;
            else
            {
                fail[next[root][i]] = root;
                Q.push(next[root][i]);
            }
        while( !Q.empty() )
        {
            int now = Q.front();
            Q.pop();
            for(int i = 0;i < bk;i++)
                if(next[now][i] == -1)
                    next[now][i] = next[fail[now]][i];
                else
                {
                    fail[next[now][i]]=next[fail[now]][i];
                    Q.push(next[now][i]);
                }
        }
    }
    int query(char buf[])
    {
        int len = strlen(buf),
        	now = root,
        	res = 0;
        for(int i = 0;i < len;i++)
        {
            now = next[now][buf[i]-'a'];
            int temp = now;
            while( temp != root )
            {
                res += end[temp];
                end[temp] = 0;
                temp = fail[temp];
            }
        }
        return res;
    }
    void debug()
    {
        for(int i=0;i<L;i++)
        {
            printf("id = %3d,fail = %3d,end = %3d,\nchi = [",i,fail[i],end[i]);
            for(int j = 0;j < 26;j++) printf("%2d",next[i][j]);
            printf("]\n");
        }
    }
};

char buf[Maxn*2];
Trie ac;

int main()
{
    int T,n;
    scanf("%d",&T);
    for(int _T=1; _T<=T; _T++)
    {
        scanf("%d",&n);
        ac.init();
        for(int i = 0;i < n;i++)
        {
            scanf("%s",buf);
            ac.insert(buf);
        }
        ac.build();
        scanf("%s",buf);
        printf("%d\n",ac.query(buf));
        //ac.debug();
    }
    return 0;
}
