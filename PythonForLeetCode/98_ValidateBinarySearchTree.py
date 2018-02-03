# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def isValidBST(self, root):
        """
        :type root: TreeNode
        :rtype: bool
        """
        if root == None:
            return True
        result, ma, mi = self.isValidBSTT(root)
        return result
    def isValidBSTT(self, root):
        if root.left != None:
            isleftValid, leftma, leftmi = self.isValidBSTT(root.left)
            if not isleftValid or root.val <= leftma:
                return False, None, None
        else:
            leftma = root.val
            leftmi = root.val
        if root.right != None:
            isrighValid, rightma, rightmi = self.isValidBSTT(root.right)
            if not isrighValid or root.val >= rightmi:
                return False, None, None
        else:
            rightma = root.val
            rightmi = root.val
        return True, max([root.val, leftma, rightma]), min([root.val, leftmi, rightmi])