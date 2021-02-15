'''
 @author Sourabh Gome
 Time complexity : O(n^2)
 Space complexity : O(1)
'''

def twoNumberSum(array, targetSum):
    length = len(array)
    for i in range(length-1):
        firstNum = array[i]
        for j in range(i+1, length):
            secondNum = array[j]
            if firstNum + secondNum == targetSum :
                return [firstNum, secondNum]
    return []

# Driver code
arr = [8,5,3,1,-1,6,-4,11]
targetSum = 10
result = twoNumberSum(arr, targetSum)
print(result)