#include <cstdio>  
#include <string>  
#include <cstring>  
#include <iostream>  
#include <algorithm>  
  
/************************************************* 
strstr 
原型：const char * strstr ( const char * str1, cosnt char *str2); 
            char * strstr ( char * str1, const char * str2); 
参数： str1，待查找的字符串指针； 
        str2，要查找的字符串指针。 
说明： 在str1中查找匹配str2的子串，并返回指向首次匹配时的第一个元素指针。 
        如果没有找到，返回NULL指针。 
***************************************************/  
  
  
using namespace std;  
int main()  
{  
    //freopen("in.txt","r",stdin);  
    char line[101];  
    char find[100];  
    scanf("%s",line);  
    int len=strlen(line);  
    for(int l=len-1;l>0;l--)  
    {  
        for(int i=0;i<=len-l;i++)  
        {  
            strncpy(find,line+i,l);//从line里的第i位开始，数l个字符的字符串扔给find  
            find[l]='\0';//很重要，不封口简直是作死  
            if(strstr(strstr(line,find)+1,find))//找到一个，然后在他后头一位开始找第二个  
            {  
                printf("%d",l);  
                return 0;  
            }   
        }  
    }  
    printf("0");  
    return 0;  
}  
