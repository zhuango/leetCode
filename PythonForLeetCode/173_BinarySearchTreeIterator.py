# Definition for a  binary tree node
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class BSTIterator(object):
    def __init__(self, root):
        """
        :type root: TreeNode
        """
        self.queue = []
        self.dfs(root)
        
    def dfs(self, root):
        if root == None:
            return
        self.dfs(root.right)
        self.queue.append(root.val)
        self.dfs(root.left)

    def hasNext(self):
        """
        :rtype: bool
        """
        if len(self.queue) == 0:
            return False
        else:
            return True

    def next(self):
        """
        :rtype: int
        """
        return self.queue.pop()

# Your BSTIterator will be called like this:
# i, v = BSTIterator(root), []
# while i.hasNext(): v.append(i.next())