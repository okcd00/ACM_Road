# input  
list = raw_input().split()  
n,p1,p2,t1,t2,t3 = map(int , list)  
  
# solve  
ans = 0  
pre = -1  
  
while n > 0:  
    n -= 1  
    list = raw_input().split()  
    start,end = map(int , list)  
    ans += (end-start)*p1  
      
    if pre != -1:  
       x = start-pre  
       if x > t1:  
          ans += t1*p1  
          x -= t1  
          if x > t2:  
             ans += t2*p2  
             x -= t2  
             ans += x*p3  
          else:  
             ans += x*p2  
       else:  
          ans += x*p1   
    pre = end  
  
print ans  