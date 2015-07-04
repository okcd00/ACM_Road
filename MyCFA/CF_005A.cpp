#include <cstdio>  
#include <cstring>  
#include <iostream>  
#include <algorithm>  
using namespace std;  
//http://blog.csdn.net/okcd00/article/details/22694671

//这道题麻烦在理解题意上，其实他的意思是，总共发送了多少字节，每个人说话的时候这句话要发给在场所有的人（包括他自己）   
//难点大概除了理解题意，还有一个难点就似乎在读入上   
int main()  
{  
char str[110];  
  
    int num=0;//记录在线人数  
    int sum=0;//记录最终字节数  
    int colon;//记录冒号的位置  
    while(gets(str))  
    {  
        if(str[0]=='+')num++;  
        else if(str[0]=='-')num--;  
        else  
        {  
            for(int i=0; i<strlen(str); i++)  
            {  
                if(str[i]==':')  
                {  
                    colon=i;  
                    break;  
                }  
            }  
            sum+=(strlen(str)-1-colon)*num;  
        }  
    }  
    printf("%d\n",sum);  
    return 0;  
}  
