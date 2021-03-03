'''
 @author Sourabh Gome
 Time complexity  : O(n) 
 Space complexity : O(1)
'''

def moveElementToLast(array, k):
    left=0
    right=len(array)-1
    while left<right:
        if array[right]==k:
            right-=1
        elif array[left]==k:
            array[left],array[right]=array[right],array[left]
            left+=1
            right-=1
        else:
            left+=1
    return array

#Driver Code
array = [2, 1, 2, 2, 2, 3, 4, 2]
print(moveElementToLast(array,2))