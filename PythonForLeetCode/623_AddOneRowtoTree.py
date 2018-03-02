# Definition for a binary tree node.
class TreeNode(object):
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    def addOneRow(self, root, v, d):
        """
        :type root: TreeNode
        :type v: int
        :type d: int
        :rtype: TreeNode
        """
        if d == 1:
            a = TreeNode(v)
            a.left = root
            return a
        self.d = d - 1
        self.v = v
        self.trav(root, 1)
        return root

    def trav(self, root, level):
        if root == None:
            return
        if level == self.d:
            left = root.left
            right = root.right
            newNode = TreeNode(self.v)
            root.left = newNode
            newNode = TreeNode(self.v)
            root.right = newNode
            root.left.left = left
            root.right.right = right
            return
        self.trav(root.left, level + 1)
        self.trav(root.right, level + 1)