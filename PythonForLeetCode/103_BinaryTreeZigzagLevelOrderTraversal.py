# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def zigzagLevelOrder(self, root):
        """
        :type root: TreeNode
        :rtype: List[List[int]]
        """
        if root == None:
            return []
        result = []
        queue = [(root, 0)]
        index = 0
        level = 0
        curLevel = 0
        levelStart = 0
        while index < len(queue):
            cur, level = queue[index]
            if cur.left != None:
                queue.append((cur.left, level + 1))
            if cur.right != None:
                queue.append((cur.right, level + 1))
            if curLevel == level:
                index += 1
                continue
            curLevel = level
            result.append([])
            if level % 2 == 1:
                for i in range(levelStart, index):
                    result[-1].append(queue[i][0].val)
            else:
                for i in range(index - 1, levelStart -1, -1):
                    result[-1].append(queue[i][0].val)
            levelStart = index
            index += 1
            
        result.append([])
        if level % 2 == 0:
            for i in range(levelStart, index):
                result[-1].append(queue[i][0].val)
        else:
            for i in range(index - 1, levelStart -1, -1):
                result[-1].append(queue[i][0].val)

        return result
