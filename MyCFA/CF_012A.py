# input    
matrix = []    
for i in range(3):    
    matrix.append(raw_input())    
# solve    
def isOk():    
    for i in range(3):    
        for j in range(3):    
            x = 2-i    
            y = 2-j    
            if matrix[i][j] != matrix[x][y]:    
               return False    
    return True    
# ouput    
if isOk():    
    print "YES"    
else:    
    print "NO"  