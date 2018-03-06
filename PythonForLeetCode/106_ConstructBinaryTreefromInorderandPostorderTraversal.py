# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    def buildTree(self, inorder, postorder):
        """
        :type inorder: List[int]
        :type postorder: List[int]
        :rtype: TreeNode
        """
        self.dicInorder = {}
        self.dicPostorder = {}
        for i in range(len(inorder)):
            self.dicInorder[inorder[i]] = i
            self.dicPostorder[postorder[i]] = i
        return self.build(inorder, 0, len(inorder) -1 , postorder, 0, len(postorder) - 1)

    def build(self, inorder, startIn, endIn, postorder, startPost, endPost):
        if startIn > endIn or startPost > endPost:
            return None
        # if startIn == endIn:
        #     return TreeNode(inorder[startIn])
        root = TreeNode(postorder[endPost])
        middle = self.dicInorder[postorder[endPost]]
        
        post = [self.dicPostorder[elem] for elem in inorder[startIn:middle]]
        if post:
            start, end = min(post), max(post)
            root.left = self.build(inorder, startIn, middle - 1, postorder, start, end)
        
        post = [self.dicPostorder[elem] for elem in inorder[middle + 1:endIn + 1]]
        if post:
            start, end = min(post), max(post)
            root.right = self.build(inorder, middle + 1, endIn, postorder, start, end)
        return root
        

inorder = [9,3,15,20,7]
postorder = [9,15,7,20,3]
sol = Solution()
result = sol.buildTree(inorder, postorder)
print(result)
