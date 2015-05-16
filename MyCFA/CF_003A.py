# Class for Point    
class Point:    
     def __init__(self , x , y):    
         self.x = x     
         self.y = y    
    
# input start and end Point    
str = raw_input()    
start = Point(8-int(str[1]) , ord(str[0])-97)    
    
str = raw_input()    
end = Point(8-int(str[1]) , ord(str[0])-97)    
    
# solve this problem    
dir = [[-1,0],[-1,1],[0,1],[1,1],[1,0],[1,-1],[0,-1],[-1,-1]]    
move = ["U","RU","R","RD","D","LD","L","LU"]    
ans = max(abs(start.x-end.x) , abs(start.y-end.y))    
    
# output    
print ans    
m = ans    
    
x = start.x    
y = start.y    
    
# print "%d %d" % (start.x , start.y)    
# print "%d %d" % (end.x , end.y)    
    
while m > 0:    
    for i in range(8):    
        tmpx = x+dir[i][0]    
        tmpy = y+dir[i][1]    
        if (tmpx >= 0 and tmpx < 8 and tmpy >= 0 and tmpy < 8):    
           dis = max(abs(tmpx-end.x) , abs(tmpy-end.y))      
           if dis < m:    
              print move[i]    
              x = tmpx    
              y = tmpy    
              break    
    m -= 1  
