'''
 @author Sourabh Gome
 Time complexity  : O(n)
 Space complexity : O(n)
'''

copies=0
storage={1:0, 2:1}
def nthFibonacci(n):
    global copies
    copies+=1
    if n in storage:
        return storage[n]
    storage[n] = nthFibonacci(n-1) + nthFibonacci(n-2)
    return storage[n]

print(nthFibonacci(100))
print(copies)