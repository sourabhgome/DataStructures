'''
 @author Sourabh Gome
 Time complexity  : O(2^n)
 Space complexity : O(n)
'''

copies=0
def nthFibonacci(n):
    global copies
    copies+=1
    if n==1: return 0
    elif n==2: return 1
    return nthFibonacci(n-1)+nthFibonacci(n-2)

print(nthFibonacci(100))
print(copies)