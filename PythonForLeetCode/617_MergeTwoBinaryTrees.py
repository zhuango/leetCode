# Definition for a binary tree node.
class TreeNode(object):
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution(object):
    def mergeTrees(self, t1, t2):
        """
        :type t1: TreeNode
        :type t2: TreeNode
        :rtype: TreeNode
        """
        newRoot = self.buildFromTwoTrees(t1, t2)
        return newRoot
    def buildFromTwoTrees(self, root1, root2):
        if root1 == None and root2 == None:
            return None
        if root1 == None:
            newNode = TreeNode(root2.val)
            newNode.left = self.buildFromTwoTrees(None, root2.left)
            newNode.right = self.buildFromTwoTrees(None, root2.right)
        elif root2 == None:
            newNode = TreeNode(root1.val)
            newNode.left = self.buildFromTwoTrees(root1.left, None)
            newNode.right = self.buildFromTwoTrees(root1.right, None)
        else:
            newNode = TreeNode(root1.val + root2.val)
            newNode.left = self.buildFromTwoTrees(root1.left, root2.left)
            newNode.right = self.buildFromTwoTrees(root1.right, root2.right)
        return newNode
