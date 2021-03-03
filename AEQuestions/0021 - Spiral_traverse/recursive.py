'''
 @author Sourabh Gome
 Time complexity  : O(N) -> N = n*m
 Space complexity : O(N) -> N = n*m
'''

def spiralTraverse(matrix):
    result=[]
    spiralFill(matrix, 0, len(matrix)-1, 0, len(matrix[0])-1, result)
    return result

def spiralFill(matrix, startRow, endRow, startCol, endCol, result):
    if startRow>endRow or startCol>endCol:
        return

    for col in range(startCol, endCol+1):
        result.append(matrix[startRow][col])
    
    for row in range(startRow+1, endRow+1):
        result.append(matrix[row][endCol])

    for col in reversed(range(startCol, endCol)):
        result.append(matrix[endRow][col])

    for row in reversed(range(startRow+1,endRow)):
        result.append(matrix[row][startCol])
    
    spiralFill(matrix, startRow+1, endRow-1, startCol+1, endCol-1, result)

#Driver Code
matrix = [
    [1, 2, 3, 4],
    [12, 13, 14, 5],
    [11, 16, 15, 6],
    [10, 9, 8, 7]
]
print(spiralTraverse(matrix))