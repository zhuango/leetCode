# Definition for binary tree with next pointer.
class TreeLinkNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None
        self.next = None

class Solution:
    # @param root, a tree link node
    # @return nothing
    def connect(self, root):
        leftNode = root
        prevNode = None
        currNode = None

        while leftNode != None:
            currNode = leftNode
            prevNode = None
            leftNode = None

            while currNode != None:
                if currNode.left != None:
                    if prevNode != None:
                        prevNode.next = currNode.left
                    else:
                        leftNode = currNode.left
                    prevNode = currNode.left
                if currNode.right != None:
                    if prevNode != None:
                        prevNode.next = currNode.right
                    else:
                        leftNode = currNode.right
                    prevNode = currNode.right
                currNode = currNode.next
            
