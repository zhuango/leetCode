# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    def generateTrees(self, n):
        """
        :type n: int
        :rtype: List[TreeNode]
        """
        if n == 0:
            return []
        trees = [TreeNode(1)]
        for i in range(2, n + 1):
            self.newtrees = []
            for tree in trees:
                newTree = self.cloneTree(tree)
                root = TreeNode(i)
                root.left = newTree
                self.newtrees.append(root)
                self.insert(tree, tree, tree.right, i)

            trees = self.newtrees
        return trees
    def cloneTree(self, tree):
        if tree == None:
            return None
        root = TreeNode(tree.val)
        root.left = self.cloneTree(tree.left)
        root.right = self.cloneTree(tree.right)
        return root
    def insert(self, root, father, tree, n):
        if tree == None:
            father.right = TreeNode(n)
            self.newtrees.append(self.cloneTree(root))
            father.right = None
            return 
        self.insert(root, tree, tree.right, n)
        newRoot = TreeNode(n)
        father.right = newRoot
        newRoot.left = tree
        self.newtrees.append(self.cloneTree(root))
        father.right = tree

sol = Solution()
results = sol.generateTrees(3)
print(results)
