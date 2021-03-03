'''
 @author Sourabh Gome
 Time complexity  : O(n^2)
 Space complexity : O(n)
'''

def threeNumberSum(array, target):
    array.sort()
    result=[]
    size=len(array)
    i=0
    while(i<size-2):
        first=array[i]
        left=i+1
        right=size-1
        while left<right:
            currentSum=first+array[left]+array[right]
            if currentSum < target:
                left+=1
            elif currentSum > target:
                right-=1
            elif currentSum == target:
                result.append([first,array[left],array[right]])
                left+=1
                right-=1
        i+=1
    return result

#Driver code
array=[12, 3, 1, 2, -6, 5, -8, 6]
target_sum=0
print(threeNumberSum(array,target_sum))