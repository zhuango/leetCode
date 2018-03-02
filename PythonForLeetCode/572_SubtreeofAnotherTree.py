# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def isSubtree(self, s, t):
        """
        :type s: TreeNode
        :type t: TreeNode
        :rtype: bool
        """
        self.subTrees = set()
        self.trav(s)
        subStr = self.subTreeStr(t)
        return subStr in self.subTrees
    def trav(self, root):
        if root == None:
            return ""

        left = self.trav(root.left)
        right = self.trav(root.right)
        curStr = "(" + left + str(root.val) + right + ")"
        self.subTrees.add(curStr)
        return curStr
    def subTreeStr(self, root):
        if root == None:
            return ""

        left = self.trav(root.left)
        right = self.trav(root.right)
        curStr = "(" + left + str(root.val) + right + ")"
        return curStr