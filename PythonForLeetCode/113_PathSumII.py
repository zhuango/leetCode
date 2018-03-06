# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def pathSum(self, root, sum):
        """
        :type root: TreeNode
        :type sum: int
        :rtype: List[List[int]]
        """
        self.s = sum
        self.results = []
        self.curPath = []
        self.preorder(root)
        return self.results
    def preorder(self, root):
        if root == None:
            return
        self.curPath.append(root.val)
        if root.left == None and root.right == None:
            if sum(self.curPath) == self.s:
                self.results.append(list(self.curPath))
            self.curPath.pop()
            return
        self.preorder(root.left)
        self.preorder(root.right)
        self.curPath.pop()