'''
 @author Sourabh Gome
 Time complexity  : O(n)
 Space complexity : O(1)
'''

def nthFibonacci(n):
    if n <=1 : return 0
    lastTwo = [0, 1]
    counter=3
    while counter <= n:
        nextFib = sum(lastTwo)
        lastTwo[0] = lastTwo[1]
        lastTwo[1] = nextFib
        counter+=1
    return lastTwo[1]

print(nthFibonacci(100))