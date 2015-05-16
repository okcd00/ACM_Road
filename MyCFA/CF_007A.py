# input  
matrix = []  
for i in range(8):  
    matrix.append(raw_input())  
  
# getAns  
ans = 0  
# row  
for i in range(8):  
    if matrix[i][0] == 'B':  
       for j in range(8):  
           if matrix[i][j] == 'W':  
              break  
       if j == 7 and matrix[i][j] == 'B':  
          ans += 1          
  
# col  
for i in range(8):  
    if matrix[0][i] == 'B':  
       for j in range(8):  
           if matrix[j][i] == 'W':  
              break  
       if j == 7 and matrix[j][i] == 'B':  
           ans += 1  
  
if ans == 16:  
   ans = 8  
print ans  
