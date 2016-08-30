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
    def hasPathSum(self, root, sum):
        """
        :type root: TreeNode
        :type sum: int
        :rtype: bool
        """
        self.sum = sum
        self.result = False
        self.traversal(root, 0)
        return self.result
    def traversal(self, root, sum):
        if root == None:
            return 
        else:
            sum += root.val
            if root.left == None and root.right == None:
                if sum == self.sum:
                    self.result = True
            self.traversal(root.left , sum)
            if self.result:
                return
            self.traversal(root.right, sum)
            sum -= root.val
root = generateTree([5, 4, 8, 11, None, 13, 4, 7, 2, None, None, None, 1])
sol = Solution()
print(sol.hasPathSum(root, 18))