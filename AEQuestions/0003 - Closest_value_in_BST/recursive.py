'''
 @author Sourabh Gome
 Average :
 Time complexity  : O(log n)
 Space complexity : O(log n)
 Worst :
 Time complexity  : O(n)
 Space complexity : O(n)
'''

def findClosestValueInBST(tree, target):
    findClosestValueInBSTHelper(tree, target, float("inf"))

def findClosestValueInBSTHelper(tree, target, closest):
    if tree is None:
        return closest
    if abs(target - closest) > abs(target - tree.value):
        closest=tree.value
    if target < tree.value:
        findClosestValueInBSTHelper(tree.left, target, closest)
    elif target > tree.value:
        findClosestValueInBSTHelper(tree.right, target, closest)
    else:
        return closest