import os  
import sys  
  
# solve  
def solve():  
    n = int(raw_input())  
    dic = {}  
    for i in range(n):  
        str = raw_input()  
        dic[str] = [0,0,0]  
      
    i = n*(n-1)/2  
    while i:  
        list = raw_input().split()  
        tmp1 = list[0].split("-")  
        tmp2 = list[1].split(":")  
        i -= 1  
  
        if(int(tmp2[0]) > int(tmp2[1])):  
            dic[tmp1[0]][0] += 3  
            dic[tmp1[0]][1] += int(tmp2[1])  
            dic[tmp1[0]][2] += int(tmp2[0])  
              
            dic[tmp1[1]][1] += int(tmp2[0])  
            dic[tmp1[1]][2] += int(tmp2[1])  
        elif(int(tmp2[0]) == int(tmp2[1])):  
            dic[tmp1[0]][0] += 1  
            dic[tmp1[0]][1] += int(tmp2[1])  
            dic[tmp1[0]][2] += int(tmp2[0])  
  
            dic[tmp1[1]][0] += 1  
            dic[tmp1[1]][1] += int(tmp2[0])  
            dic[tmp1[1]][2] += int(tmp2[1])  
        else:  
            dic[tmp1[0]][1] += int(tmp2[1])  
            dic[tmp1[0]][2] += int(tmp2[0])  
  
            dic[tmp1[1]][0] += 3  
            dic[tmp1[1]][1] += int(tmp2[0])  
            dic[tmp1[1]][2] += int(tmp2[1])  
  
    # out  
    ans = sorted(dic.items() , key = lambda value:(value[1][0],value[1][2]-value[1][1],value[1][2]) , reverse = True)  
    out = []  
    for i in range(n/2):  
        out.append(ans[i][0])  
    out.sort()  
    for s in out:  
        print s  
  
# main  
if __name__ == "__main__":  
    solve()  