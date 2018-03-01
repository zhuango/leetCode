# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

from collections import defaultdict
class Solution:
    def averageOfLevels(self, root):
        """
        :type root: TreeNode
        :rtype: List[float]
        """
        if root == None:
            return []
        result = []
        levelDict = defaultdict(lambda:[])
        level = 0
        queue = [(root, level)]
        index = 0
        while index < len(queue):
            node, level = queue[index]
            levelDict[level].append(node.val)
            if node.left != None:
                queue.append((node.left, level + 1))
            if node.right != None:
                queue.append((node.right, level + 1))
            index += 1
        index = 0
        while index in levelDict:
            result.append(sum(levelDict[index]) / len(levelDict[index]))
            index += 1
        return result