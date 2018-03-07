# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def rob(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        result1, result2 = self.dfs(root)
        return max([result1, result2])
    def dfs(self, root):
        if root == None:
            return 0, 0
        wLeft, wnLeft = self.dfs(root.left)
        wRigh, wnRigh = self.dfs(root.right)
        
        wCur = root.val + wnLeft + wnRigh

        maxLeft = max([wLeft, wnLeft])
        maxRigh = max([wRigh, wnRigh])
        return wCur, maxLeft + maxRigh