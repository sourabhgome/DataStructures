'''
 @author Sourabh Gome
 Time complexity  : O(n)
 Space complexity : O(1)
'''

def validateSubsequence(array, subsequence):
    index=0
    for x in array:
        if(index>=len(subsequence)): break
        if(subsequence[index]==x):
            index+=1
    return index==len(subsequence)

# Driver Code
array = [5, 1, 22, 25, 6, -1, 8, 10]
subsequence = [1, 6, -1, 10]
print(validateSubsequence(array, subsequence))