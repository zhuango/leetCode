#!/usr/bin/python3
# Definition for a binary tree node.
class TreeNode(object):
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None
def generateTree(nodes):
    if len(nodes) == 0:
        return None
    root = TreeNode(nodes[0])
    queue = []
    queue.append(root)
    del nodes[0]
    while len(nodes) != 0:
        curVal  = nodes[0]
        curNode = queue[0]
        if curVal == None:
            curNode.left = None
        else:
            curNode.left = TreeNode(int(curVal))
            queue.append(curNode.left)
        del nodes[0]
        
        if len(nodes) == 0:
            break
        else:
            curVal = nodes[0]
        if curVal == None:
            curNode.right = None
        else:
            curNode.right = TreeNode(int(curVal))
            queue.append(curNode.right)
        del nodes[0]
        del queue[0]
    return root
class Solution(object):
    def highAndIsBalanced(self, root):
        if root == None:
            return (0, True)
        else:
            high = 0
            leftHigh  = self.highAndIsBalanced(root.left)
            rightHigh = self.highAndIsBalanced(root.right)
            if leftHigh > rightHigh:
                high = leftHigh[0]  + 1
            else:
                high = rightHigh[0] + 1
            isbalanced = abs(leftHigh[0] - rightHigh[0]) <= 1
            return (high, isbalanced and leftHigh[1] and rightHigh[1])
    def isBalanced(self, root):
        """
        :type root: TreeNode
        :rtype: bool
        """
        result = self.highAndIsBalanced(root)
        return result[1]

sol = Solution()
root = generateTree([])
print(sol.isBalanced(root))
root = generateTree([1])
print(sol.isBalanced(root))
root = generateTree([1, 2])
print(sol.isBalanced(root))
root = generateTree([1, 2, 3])
print(sol.isBalanced(root))
root = generateTree([1, 2, 3, None, 4, None, None, 5])
print(sol.isBalanced(root))
root = generateTree([1, 2, 3, 7, 4, 9, None, 5])
print(sol.isBalanced(root))
root = generateTree([1, 2, 3, 7, 4, 9, None, 5, None, None, None, None, 9])
print(sol.isBalanced(root))

        
        