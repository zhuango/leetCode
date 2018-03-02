# Definition for a binary tree node.
class TreeNode(object):
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    def tree2str(self, t):
        """
        :type t: TreeNode
        :rtype: str
        """
        if t == None:
            return ""
        left = self.tree2str(t.left)
        right = self.tree2str(t.right)
        a = str(t.val)
        if right == "" and left == "":
            return a
        if left != "" and right == "":
            return "{}({})".format(a, left)
        if left == None and right != None:
            return "{}()({})".format(a, right)
        else:
            return "{}({})({})".format(a, left, right)
