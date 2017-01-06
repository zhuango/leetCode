#!/usr/bin/python
# Definition for a binary tree node.
class TreeNode(object):
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution(object):
    def __init__(self):
        self.number = 0
        self.sum = 0
    def sumNumbers(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        if root == None: return 0
        self.preOrder(root)
        return self.sum
    def preOrder(self, root):
        self.number = self.number * 10 + root.val
        if root.right == None and root.left == None:
            self.sum += self.number
        else:
            if not root.left == None:
                self.preOrder(root.left)
            if not root.right == None:
                self.preOrder(root.right)
        self.number = self.number / 10

solver = Solution()
