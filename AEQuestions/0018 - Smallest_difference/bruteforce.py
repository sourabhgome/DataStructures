'''
 @author Sourabh Gome
 Time complexity  : O(n^2)
 Space complexity : O(1)
'''

def smallestDifference(a,b):
    result=[]
    smallest=abs(a[0]-b[0])
    result=[a[0], b[0]]
    for x in a:
        for y in b:
            if abs(x-y)<smallest:
                smallest=abs(x-y)
                result=[x, y]
    return result

#Driver code
a=[-1, 5, 10, 20, 28, 3]
b=[26, 134, 135, 15, 17]
print(smallestDifference(a, b))
