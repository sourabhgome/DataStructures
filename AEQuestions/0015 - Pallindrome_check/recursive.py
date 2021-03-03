'''
 @author Sourabh Gome
 Time complexity  : O(n)
 Space complexity : O(n) -> Recursion Stack
'''

def isPallindrome(string, first=0):
    last = len(string) - 1 - first
    return True if first >= last else string[first] == string[last] and isPallindrome(string, first+1)

#Driver Code
print(isPallindrome("abcdcba"))