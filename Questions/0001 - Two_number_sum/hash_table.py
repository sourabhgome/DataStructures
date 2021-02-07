'''
 @author Sourabh Gome
 Time complexity : O(n)
 Space complexity : O(n)
'''

def twoNumberSum(array, targetSum):
    hash_table=dict()
    for x in arr:
        y = targetSum - x
        if y in hash_table:
            return [x,y]
        hash_table[x] = 1
    return []

# Driver code
arr = [8,5,3,1,-1,6,-4,11]
targetSum = 10
result = twoNumberSum(arr, targetSum)
print(result)