#include <map>
#include <queue>
#include <cstdio>
#include <string>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

map <char,int> mp;

int N,M,P;
struct Matrix
{
    int mat[110][110];
    int n;
    Matrix(){}
    Matrix(int _n)
    {
        n=_n;
        for(int i = 0;i < n;i++)
            for(int j = 0;j < n;j++)
                mat[i][j] = 0;
    }
};

struct Trie
{
    int next[110][256], fail[110];
    bool end[110];
    int L,root;
    int newnode()
    {
        for(int i = 0;i < 256;i++)
            next[L][i] = -1;
        end[L++] = false;
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
            if(next[now][mp[buf[i]]] == -1)
                next[now][mp[buf[i]]] = newnode();
            now = next[now][mp[buf[i]]];
        }
        end[now] = true;
    }
    void build()
    {
        queue<int>Q;
        fail[root] = root;
        for(int i = 0;i < 256;i++)
            if(next[root][i] == -1)
                next[root][i] = root;
            else
            {
                fail[next[root][i]] = root;
                Q.push(next[root][i]);
            }
        while(!Q.empty())
        {
            int now = Q.front(); Q.pop();
            if(end[fail[now]]==true)end[now]=true;
            for(int i = 0;i < 256;i++)
                if(next[now][i] == -1)
                    next[now][i] = next[fail[now]][i];
                else
                {
                    fail[next[now][i]] = next[fail[now]][i];
                    Q.push(next[now][i]);
                }
        }
    }
    Matrix getMatrix()
    {
        Matrix res = Matrix(L);
        for(int i = 0;i < L;i++)
            for(int j = 0;j < N;j++)
                if(end[next[i][j]]==false)
                    res.mat[i][next[i][j]]++;
        return res;
    }
    void debug()
    {
        for(int i = 0;i < L;i++)
        {
            printf("id = %3d,fail = %3d,end = %3d,chi = [",i,fail[i],end[i]);
            for(int j = 0;j < 26;j++)
                printf("%2d",next[i][j]);
            printf("]\n");
        }
    }

};


/*
 * 高精度，支持乘法和加法
 */
struct BigInt
{
    const static int mod = 10000;
    const static int DLEN = 4;	//per 4 digit for a section
    int a[600],len;
    BigInt()
    {
        memset(a,0,sizeof(a));
        len = 1;
    }
    BigInt(int v)
    {
        memset(a,0,sizeof(a));
        len = 0;
        do
        {
            a[len++] = v%mod;
            v /= mod;
        }while(v);
    }
    BigInt(const char s[])
    {
        memset(a,0,sizeof(a));
        int L = strlen(s);
        len = L/DLEN;
        if(L%DLEN) len++;
        int index = 0;
        for(int i = L-1;i >= 0;i -= DLEN)
        {
            int t = 0,
				k = i - DLEN + 1;
            if(k < 0) k = 0;
            for(int j = k;j <= i;j++)
                t = t*10 + s[j] - '0';
            a[index++] = t;
        }
    }
    BigInt operator +(const BigInt &b)const
    {
        BigInt res;
        res.len = max(len,b.len);
        for(int i = 0;i <= res.len;i++)
            res.a[i] = 0;
        for(int i = 0;i < res.len;i++)
        {
            res.a[i] += ((i < len)?a[i]:0)+((i < b.len)?b.a[i]:0);
            res.a[i+1] += res.a[i]/mod;
            res.a[i] %= mod;
        }
        if(res.a[res.len] > 0)res.len++;
        return res;
    }
    BigInt operator *(const BigInt &b)const
    {
        BigInt res;
        for(int i = 0; i < len;i++)
        {
            int up = 0;
            for(int j = 0;j < b.len;j++)
            {
                int temp = a[i]*b.a[j] + res.a[i+j] + up;
                res.a[i+j] = temp%mod;
                up = temp/mod;
            }
            if(up != 0) res.a[i + b.len] = up;
        }
        res.len = len + b.len;
        while(res.a[res.len - 1] == 0 &&res.len > 1) res.len--;
        return res;
    }
    void output()
    {
        printf("%d",a[len-1]);
        for(int i = len-2;i >=0 ;i--)
            printf("%04d",a[i]);
        printf("\n");
    }
};

char buf[1010];
BigInt dp[2][110];
Trie ac;

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("out.txt","w",stdout);

    while(scanf("%d%d%d",&N,&M,&P)==3)
    {
        gets(buf);
        gets(buf);
        mp.clear();
        int len = strlen(buf);
        for(int i = 0;i < len;i++)
            mp[buf[i]]=i;
        ac.init();
        for(int i = 0;i < P;i++)
        {
            gets(buf);
            ac.insert(buf);
        }
        ac.build();
//        ac.debug();
        Matrix a= ac.getMatrix();

//        for(int i = 0;i <a.n;i++)
//        {
//            for(int j=0;j<a.n;j++)printf("%d ",a.mat[i][j]);
//            cout<<endl;
//        }

        int now = 0;
        dp[now][0] = 1;
        for(int i = 1;i < a.n;i++)
            dp[now][i] = 0;
        for(int i = 0;i < M;i++)
        {
            now^=1;	
            for(int j = 0;j < a.n;j++)
                dp[now][j] = 0;
            for(int j = 0;j < a.n;j++)
                for(int k = 0;k < a.n;k++)
                    if(a.mat[j][k] > 0)
                        dp[now][k] = dp[now][k]+dp[now^1][j]*a.mat[j][k];
//            for(int j = 0;j < a.n;j++)
//                dp[now][j].output();
        }
        BigInt ans = 0;
        for(int i = 0;i < a.n;i++)
            ans = ans + dp[now][i];
        ans.output();
    }
    return 0;
}
