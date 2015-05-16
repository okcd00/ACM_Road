#include<stdio.h>  //ZoeCUR's C Code
int main()  
{  
    int a[4];  
    for(int i=0;i<4;i++) scanf("%d",&a[i]);  
    for(int j=0;j<4;j++)  
    { 
    	for(int k=j+1;k<4;k++)  
    	{  
            if(a[k]<a[j])  
            {  
                int temp;  
                temp=a[j];  
                a[j]=a[k];  
               	a[k]=temp;  
            }  
     	}
    }  
    if((a[0]+a[1])<a[2]&&a[0]+a[2]<a[3]&&a[1]+a[2]<a[3])printf("IMPOSSIBLE");  
    else if(a[0]+a[1]>a[2]||a[0]+a[2]>a[3]||a[1]+a[2]>a[3])printf("TRIANGLE");  
    else printf("SEGMENT");  
    return 0;  
}  
