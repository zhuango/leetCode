#!/usr/bin/python3
# Definition for a binary tree node.
class TreeNode(object):
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None
def generateTree(nodes):
    if len(nodes) == 0:
        return None
    root = TreeNode(nodes[0])
    queue = []
    queue.append(root)
    del nodes[0]
    while len(nodes) != 0:
        curVal  = nodes[0]
        curNode = queue[0]
        if curVal == None:
            curNode.left = None
        else:
            curNode.left = TreeNode(int(curVal))
            queue.append(curNode.left)
        del nodes[0]
        
        if len(nodes) == 0:
            break
        else:
            curVal = nodes[0]
        if curVal == None:
            curNode.right = None
        else:
            curNode.right = TreeNode(int(curVal))
            queue.append(curNode.right)
        del nodes[0]
        del queue[0]
    return root
class Solution(object):
    def recur(self, root, depth):
        if root == None:
            return 
        else:
            depth += 1
            if root.left == None and root.right == None:
                if depth < self.depth:
                    self.depth = depth
            self.recur(root.left , depth)
            self.recur(root.right, depth)
            depth -= 1
            return
    def minDepth(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        if root == None:
            return 0
        self.depth = 10000
        self.recur(root, 0)
        return self.depth

null = None
root = generateTree([1, 2])
pro = Solution()
print(pro.minDepth(root))