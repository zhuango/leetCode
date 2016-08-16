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
def findNode(root, val):
    if root == None:
        return None
    if root.val == val:
        return root
    else:
        result = findNode(root.left , val)
        if result != None:
            return result
        result = findNode(root.right, val)
        return result

class Solution(object):
    def lowestCommonAncestor(self, root, p, q):
        """
        :type root: TreeNode
        :type p: TreeNode
        :type q: TreeNode
        :rtype: TreeNode
        """
        pathP = self.getPathEntrance(root, p)
        pathQ = self.getPathEntrance(root, q)
        commonAncestor = None
        i = 0
        while i < len(pathP) and i < len(pathQ):
            if pathP[i] == pathQ[i]:
                commonAncestor = pathP[i]
            else:
                break
            i+=1
        return commonAncestor.val
    def getPathEntrance(self, root, node):
        path = []
        self.getPath(root, node, path)
        return path

    def getPath(self, root, node, path):
        if root == None:
            return False
        if root == node:
            path.append(root)
            return True
        else:
            path.append(root)
            getResult = self.getPath(root.left , node, path)
            if getResult:
                return True
            getResult = self.getPath(root.right, node, path)
            if getResult:
                return True
            del path[-1]
            return False
root = generateTree([1,None,2,3])
sol = Solution()
val = sol.lowestCommonAncestor(root, findNode(root, 1), findNode(root, 3))
print(val)
