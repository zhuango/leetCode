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
class Solution:
    def recur(self, root):
        if root == None:
            return 
        else:
            self.realTimeStack.append(root.val)
            if root.left == None and root.right == None:
                pat = ""
                for item in self.realTimeStack:
                    pat += str(item) + "->"
                self.result.append(pat[:-2])
                del self.realTimeStack[-1]
                return 
            self.recur(root.left)
            self.recur(root.right)
            del self.realTimeStack[-1]
    # @param {TreeNode} root
    # @return {string[]}
    def binaryTreepaths(self, root):
        self.result = []
        self.realTimeStack = []
        self.recur(root)
        return self.result

null = None
root = generateTree([1, 2])
pro = Solution()
for string in pro.binaryTreepaths(root):
    print(string)