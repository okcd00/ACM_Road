#include<stdio.h> 
#include<math.h>
#include<string.h>
int Max(int a,int b)
{
 return a>b?a:b;
}

void getyueshu(int x,int yueshu[])  
{  
    int count=0;  
    for(int i=1;i<=x/3;i++)  
       if(!(x%i))  
          yueshu[++count]=i;  
    yueshu[0]=count;  
}  
int val[20001]={0};  
main()  
{  
      int n;  
      int sum[20000]={0};  
      int yueshu[20000]={0};
      scanf("%d",&n);  
      getyueshu(n,yueshu);  
      for(int i=0;i<n;i++)  
         scanf("%d",&val[i]);  
      int max0=-1000*20000;  
      for(int i=1;i<=yueshu[0];i++)  
      {  
          memset(sum,0,sizeof(sum));  
          for(int j=0;j<n;j++)  
              sum[j%yueshu[i]]+=val[j];  
          for(int j=0;j<yueshu[i];j++)  
             max0=Max(max0,sum[j]);  
      }  
      printf("%d",max0);  
      return 0;  
}  
