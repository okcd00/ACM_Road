#include<cstdio>
#include<string>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

string a;
struct node
{
    int rank,pos;
} s[1111111];

inline int cmp(node a,node b){  return a.pos < b.pos;    }

int main()
{
    cin>>a;
    int len=a.length();
    int min=1, max=len;
    for(int i=1;i<=len;i++)
    {
       s[i].rank=i;
       if(a[i-1]=='r')	s[i].pos=min++;	
       else if(a[i-1]=='l')	s[i].pos=max--;
    }
    //for(int i=1;i<=len;i++) cout<<i<<"\t"<<s[i].pos<<endl;
    sort(s+1,s+1+len,cmp);
    for(int i=1;i<=len;i++)	printf("%d\n",s[i].rank);   
}


