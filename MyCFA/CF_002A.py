# define some variable    
n = int(raw_input())    
maxScore = {}    
input = []    
    
# n times input    
while n > 0:    
    list = raw_input().split()    
    input.append(list)    
    name = list[0]    
    score = int(list[1])    
    if maxScore.has_key(name):    
       maxScore[name] += score    
    else:    
       maxScore[name] = score    
    n -= 1    
    
# find maxScore = ans    
ans = 0    
for key in maxScore:    
    ans = max(ans , maxScore[key])    
    
# def to find the time >= ans    
def getTime(str):    
    sum = 0    
    cnt = 0    
    for list in input:    
        name = list[0]    
        score = int(list[1])    
        if name == str:    
           sum += score    
           if sum >= ans:    
              return cnt    
        cnt += 1     
    
# one by one if score == ans    
time = 2147483647    
for key in maxScore:    
    if maxScore[key] == ans:    
       t = getTime(key)    
       if time > t:    
          time = t    
          ansName = key    
    
# output    
print ansName  
