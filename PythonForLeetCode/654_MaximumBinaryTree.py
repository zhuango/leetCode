# Definition for a binary tree node.
class TreeNode(object):
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    def constructMaximumBinaryTree(self, nums):
        """
        :type nums: List[int]
        :rtype: TreeNode
        """
        root = None
        for num in nums:
            root = self.insert(root, num)
        return root
    def insert(self, root, num):
        if root == None:
            return TreeNode(num)
        if root.val > num:
            root.right = self.insert(root.right, num)
        else:
            newRoot = TreeNode(num)
            newRoot.left = root
            root = newRoot
        return root
            


sol = Solution()
result = sol.constructMaximumBinaryTree([1,3, 2,6,0,5])
print(result)
