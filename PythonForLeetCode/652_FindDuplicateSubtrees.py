
# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

from collections import defaultdict
class Solution:
    def findDuplicateSubtrees(self, root):
        """
        :type root: TreeNode
        :rtype: List[TreeNode]
        """
        result = []
        self.levelSet = defaultdict(lambda:[])
        self.postorder(root)
        for key in self.levelSet:
            if len(self.levelSet[key]) > 1:
                result.append(self.levelSet[key][0])
        return result

    def postorder(self, root):
        if root == None:
            return ""
        leftStr = self.postorder(root.left)
        rightStr= self.postorder(root.right)
        curStr = "(" + leftStr + str(root.val) + rightStr + ")"
        self.levelSet[curStr].append(root)
        return curStr
        
# [1, 2, 3,4, null, 2, 4, null, null, 4]