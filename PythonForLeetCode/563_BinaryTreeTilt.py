# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def findTilt(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        tilt, s = self.trav(root)
        return tilt
    def trav(self, root):
        if root == None:
            return 0, 0
        ltilt, lsum = self.trav(root.left)
        rtilt, rsum = self.trav(root.right)
        return ltilt + rtilt + abs(lsum - rsum), lsum + rsum + root.val