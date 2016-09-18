#!/usr/bin/python3
# Definition for a binary tree node.
class TreeNode(object):
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


class Solution(object):
    def __init__(self):
        self.curRoot = 0
    def buildTree(self, preorder, inorder):
        """
        :type preorder: List[int]
        :type inorder: List[int]
        :rtype: TreeNode
        """
        return self.generateTree(preorder, inorder, 0, len(inorder) - 1)

    def generateTree(self, preorder, inorder, start, end):
        if start == end:
            return TreeNode(inorder[start])
        elif start > end:
            self.curRoot -= 1
            return None
        curRootVal = preorder[self.curRoot]
        curRootIndexFromInorder = inorder.index(curRootVal)
        curRootNode = TreeNode(curRootVal)
        self.curRoot += 1
        curRootNode.left  = self.generateTree(preorder, inorder, start, curRootIndexFromInorder - 1)
        self.curRoot += 1
        curRootNode.right = self.generateTree(preorder, inorder, curRootIndexFromInorder + 1, end)

        return curRootNode

sol = Solution()
root = sol.buildTree([1, 2, 4, 3, 5, 6], [4, 2, 1, 5, 3, 6])
print(root)