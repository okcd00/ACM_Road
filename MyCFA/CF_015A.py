# input  
n,t = map(int , raw_input().split())  
dict = {}  
for i in range(n):  
    x,a = map(int , raw_input().split())  
    dict[x] = a  
  
# getAns  
ans = 2  
list = dict.keys()  
list.sort()  
pre = -(1<<30)  
  
for key in list:  
    a = float(dict[key])/2  
    if pre != -(1<<30):  
       dis = abs((key-a)-pre)  
       if dis > t:  
          ans += 2  
       elif dis == t:  
          ans += 1  
    pre = key+a  
  
# output  
print ans  