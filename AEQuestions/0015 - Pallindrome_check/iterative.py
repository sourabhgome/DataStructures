'''
 @author Sourabh Gome
 Time complexity  : O(n)
 Space complexity : O(1)
'''

def isPallindrome(string):
    left = 0
    right = len(string)-1
    while left < right:
        if string[left] != string[right]:
            return False
        left += 1
        right -= 1
    return True

#Driver Code
print(isPallindrome("abcdcba"))