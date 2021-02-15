'''
 @author Sourabh Gome
 Time complexity  : O(n)
 Space complexity : O(n) // O(log n) - recursion stack and O(n) - branch sums
'''


class BinaryTree:
    def __init__(self, value):
        self.value = value
        self.left = left
        self.right = right

def branchSums(root):
    sums=[]
    branchSumsHelper(root, 0, sums)
    return sums

def branchSumsHelper(node, runningSum, sums):
    if node is None:
        return
        newRunningSum = runningSum + node.value
    if node.left is None and node.right is None:
        sum.append(newRunningSum)
        return
    branchSumsHelper(node.left, newRunningSum, sums)
    branchSumsHelper(node.right, newRunningSum, sums)