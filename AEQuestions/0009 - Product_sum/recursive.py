'''
 @author Sourabh Gome
 Time complexity :  O(n) -> No. of elements
 Space complexity : O(d) -> Depth of array
'''

def productSum(arr, depth=1):
    new_sum=0
    for x in arr:
        if type(x) is int:
            new_sum+=x
        else:
            new_sum+=productSum(x, depth+1)
    return new_sum*depth

#Driver Code
arr = [5, 2, [7, -1], 3, [6, [-13, 8], 4]]
print(productSum(arr))