#include<iostream>  
#include<algorithm>
using namespace std;  
//http://blog.csdn.net/okcd00/article/details/25349317

#define Jx(a) ((i==a)?tx:x1[a])
#define Jy(a) ((i==a)?ty:y1[a])
int m[4][2]={{0,1},{1,0},{0,-1},{-1,0}};  

bool isR(int x1,int y1,int x2,int y2,int x3,int y3)  
{  
    int a,b,c;  
    a=(x1-x2)*(x1-x2)+(y1-y2)*(y1-y2);  
    b=(x1-x3)*(x1-x3)+(y1-y3)*(y1-y3);  
    c=(x3-x2)*(x3-x2)+(y3-y2)*(y3-y2);  
    if(a==0||b==0||c==0) return 0;  
    if(a+b==c||a+c==b||b+c==a) return 1;  
    else return 0;  
}  

int main()  
{  
    int x1[4],y1[4];  
    for(int i=0;i<3;i++) cin>>x1[i]>>y1[i];  
    if(isR(x1[0],y1[0],x1[1],y1[1],x1[2],y1[2]))  
    {  
        cout<<"RIGHT"<<endl;  
        return 0;  
    }  
    int tx,ty;  
    for(int i=0;i<=3;i++)  
    {  
		for(int j=0;j<=3;j++)  
		{  
			tx=x1[i]+m[j][0];  
			ty=y1[i]+m[j][1]; 
			if( isR(Jx(0),Jy(0),Jx(1),Jy(1),Jx(2),Jy(2)) )
			{
				cout<<"ALMOST"<<endl;
				return 0;
			}
				
			/***** The Complete Version Below *****
			if(i==0 && isR(tx,ty,x1[1],y1[1],x1[2],y1[2]))  
			{  
				cout<<"ALMOST"<<endl;  
				return 0;  
			}  
			if(i==1 && isR(x1[0],y1[0],tx,ty,x1[2],y1[2]))  
			{  
				cout<<"ALMOST"<<endl;  
				return 0;  
			}  
			if(i==2 && isR(x1[0],y1[0],x1[1],y1[1],tx,ty))  
			{  
				cout<<"ALMOST"<<endl;  
				return 0;  
			}         
			 ***** The Complete Version Above *****/
		}  
        if(i==3) cout<<"NEITHER"<<endl;  
    }  
    return 0;  
}  
