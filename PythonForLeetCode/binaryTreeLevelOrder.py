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
    def levelOrderBottom(self, root):
        """
        :type root: TreeNode
        :rtype: List[List[int]]
        """
        if root == None:
            return []
        result = []
        singleLevel = []
        queue = []
        queue.append(root)
        pos = 1
        while not len(queue) == 0:
            curRoot = queue[0]
            singleLevel.append(curRoot.val)
            
            if not curRoot.left == None:
                queue.append(curRoot.left)
            if not curRoot.right== None:
                queue.append(curRoot.right)
            
            del queue[0]
            pos -= 1
            if pos == 0:
                result.append(singleLevel)
                singleLevel = []
                pos = len(queue)
        result.reverse()
        return result

root = generateTree([3,9,20,None,None,15,7])
sol = Solution()
val = sol.levelOrderBottom(root)
print(val)
