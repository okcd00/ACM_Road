#include <cmath> 
#include <cctype>
#include <cstdio>
#include <string>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

#define Max(a,b) ((a)>(b)?(a):(b))
#define Min(a,b) ((a)<(b)?(a):(b))

struct node
{
      int left,right;//左端点、右端点
      int n;//记录这条线段出现了多少次，默认为0
}a[16];

void insert(int s,int t,int step)//要插入的线段的左端点和右端点、以及当前线段树中的某条线段
{
      if (s==a[step].left && t==a[step].right)
      {
            a[step].n++;//插入的线段匹配则此条线段的记录+1
            return;//插入结束返回
      }
      if (a[step].left==a[step].right)   return;//当前线段树的线段没有儿子，插入结束返回
      int mid=(a[step].left+a[step].right)/2;
      if (mid>=t)    insert(s,t,step*2);//如果中点在t的右边，则应该插入到左儿子
      else if (mid<s)    insert(s,t,step*2+1);//如果中点在s的左边，则应该插入到右儿子
      else//否则，中点一定在s和t之间，把待插线段分成两半分别插到左右儿子里面
      {
            insert(s,mid,step*2);
            insert(mid+1,t,step*2+1);
      }
}


int main()
{
	
	return 0;
}
