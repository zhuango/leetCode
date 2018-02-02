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
class Codec:

    def serialize(self, root):
        """Encodes a tree to a single string.
        
        :type root: TreeNode
        :rtype: str
        """
        

    def deserialize(self, data):
        """Decodes your encoded data to tree.
        
        :type data: str
        :rtype: TreeNode
        """
        nodes = data.split(",")
        if len(nodes) == 0:
            return None
        root = TreeNode(nodes[0])
        queue = []
        queue.append(root)
        del nodes[0]
        while len(nodes) != 0:
            curVal  = nodes[0]
            curNode = queue[0]
            if curVal == "None":
                curNode.left = None
            else:
                curNode.left = TreeNode(int(curVal))
                queue.append(curNode.left)
            del nodes[0]
            
            if len(nodes) == 0:
                break
            else:
                curVal = nodes[0]
            if curVal == "None":
                curNode.right = None
            else:
                curNode.right = TreeNode(int(curVal))
                queue.append(curNode.right)
            del nodes[0]
            del queue[0]
        return root
        

# Your Codec object will be instantiated and called as such:
# codec = Codec()
# codec.deserialize(codec.serialize(root))