#include <cstdio>  
#include <string>  
#include <cstring>  
#include <iostream>  
#include <algorithm>  
  
/************************************************* 
strstr 
ԭ�ͣ�const char * strstr ( const char * str1, cosnt char *str2); 
            char * strstr ( char * str1, const char * str2); 
������ str1�������ҵ��ַ���ָ�룻 
        str2��Ҫ���ҵ��ַ���ָ�롣 
˵���� ��str1�в���ƥ��str2���Ӵ���������ָ���״�ƥ��ʱ�ĵ�һ��Ԫ��ָ�롣 
        ���û���ҵ�������NULLָ�롣 
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
            strncpy(find,line+i,l);//��line��ĵ�iλ��ʼ����l���ַ����ַ����Ӹ�find  
            find[l]='\0';//����Ҫ������ڼ�ֱ������  
            if(strstr(strstr(line,find)+1,find))//�ҵ�һ����Ȼ��������ͷһλ��ʼ�ҵڶ���  
            {  
                printf("%d",l);  
                return 0;  
            }   
        }  
    }  
    printf("0");  
    return 0;  
}  
