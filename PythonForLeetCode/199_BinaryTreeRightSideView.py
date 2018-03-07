# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def rightSideView(self, root):
        """
        :type root: TreeNode
        :rtype: List[int]
        """
        if root == None:
            return []
        queue = [(root, 0)]
        result = []
        index = 0
        level = 0
        lastLevel = 0
        while index < len(queue):
            curNode, level = queue[index]
            if curNode.left != None:
                queue.append((curNode.left, level + 1))
            if curNode.right != None:
                queue.append((curNode.right, level + 1))
            if lastLevel != level:
                result.append(queue[index - 1][0].val)
                lastLevel = level
            index += 1
        result.append(queue[-1][0].val)
        return result 