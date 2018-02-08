# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def getMinimumDifference(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        if root.left:
            self.result = abs((root.val-root.left.val))
        else:
            self.result = abs((root.val -root.right.val))
        tempNode = root
        while tempNode != None:
            self.last = tempNode.val + self.result
            tempNode = tempNode.left
        self.dfs(root)
        return self.result
    def dfs(self, root):
        if root == None:
            return
        self.dfs(root.left)
        abd = abs((root.val - self.last))
        if abd < self.result:
            self.result = abd
        self.last = root.val
        self.dfs(root.right)

sol = Solution()
result = sol.getMinimumDifference()
print(result)