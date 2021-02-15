'''
 @author Sourabh Gome
 Time complexity  : O(n)
 Space complexity : O(h) -> h = heigth of tree
'''

def nodeDepths(root, depth=0):
    if root is None:
        return 0
    return depth + nodeDepths(root.left, depth+1) + nodeDepths(root.right, depth+1)