#include<stdio.h>
#include<math.h>
#include<iostream>
using namespace std;
int prime(long x);

int main()
{
	freopen("out.txt","w",stdout);
	long x;// printf("1000000内的所有素数是:\n");
	int pos=0,num=0;
 	for(x=2;x<=500005;x++) 
 	{  
		if(prime(x)==1)
		{
			printf("%ld,",x); 
			if(pos==8) pos=0,printf("\n");
			pos++; 
			num++;
		}
	}
	cout<<endl<<num;
	return 0;
}

 int prime(long x)
 { int i; 
 for(i=2;i<=sqrt(x);i++ ) 
 {  if(x%i==0)
 {   return 0;  }
 } return 1;
 }
