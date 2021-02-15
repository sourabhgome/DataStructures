'''
 @author Sourabh Gome
 Average :
 Time complexity  : O(log n)
 Space complexity : O(1)
 Worst :
 Time complexity  : O(n)
 Space complexity : O(1)
'''

def findClosestValueInBST(tree, target):
    closest=float("inf")
    currentNode=tree
    while currentNode is not None:
        if abs(target - closest) > abs(target - currentNode.value):
            closest=currentNode.value
        if target < currentNode.value:
            currentNode=currentNode.left
        elif target > currentNode.value:
            currentNode=currentNode.right
        else:
            break