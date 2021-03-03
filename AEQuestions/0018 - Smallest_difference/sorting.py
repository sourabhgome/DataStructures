'''
 @author Sourabh Gome
 Time complexity  : O(n log(n) + m log(m)) 
 Space complexity : O(1)
'''

def smallestDifference(a,b):
    a.sort()
    b.sort()
    smallest_dif=abs(a[0]-b[0])
    result=[a[0], b[0]]
    i=1
    j=1
    while i<len(a) and j<len(b):
        if a[i]==b[j]:
            return [a[i], b[j]]
        elif a[i]<b[j]:
            if smallest_dif > abs(a[i]-b[j]):
                smallest_dif=abs(a[i]-b[j])
                result=[a[i], b[j]]
            i+=1
        else:
            if smallest_dif > abs(a[i]-b[j]):
                smallest_dif=abs(a[i]-b[j])
                result=[a[i], b[j]]
            j+=1
    return result

#Driver code
a=[-1, 5, 10, 20, 28, 3]
b=[26, 134, 135, 15, 17]
print(smallestDifference(a, b))