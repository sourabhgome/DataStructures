'''
 @author Sourabh Gome
 Time complexity : O(n log n)
 Space complexity : O(1)
'''

def twoNumberSum(array, targetSum):
    array.sort()
    left = 0
    right = len(array)-1
    while(left < right):
        firstNum = array[left]
        secondNum = array[right]
        if firstNum+secondNum == targetSum : return [firstNum, secondNum]
        elif firstNum+secondNum < targetSum : left+=1
        else : right-=1
    return []

# Driver code
arr = [8,5,3,1,-1,6,-4,11]
targetSum = 13
result = twoNumberSum(arr, targetSum)
print(result)