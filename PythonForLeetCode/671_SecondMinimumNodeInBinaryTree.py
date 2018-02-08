# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    def findSecondMinimumValue(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        if root.left == None:
            return -1
        self.result = -1
        self.min = root.val
        self.dfs(root)
        if self.result == self.min:
            return -1
        else:
            return self.result
    
    def dfs(self, root):
        if root == None:
            return
        if root.val > self.min:
            if self.result == -1:
                self.result = root.val
            elif root.val < self.result:
                self.result = root.val
            return
        self.dfs(root.left)
        self.dfs(root.right)

def stringToTreeNode(input):
    input = input.strip()
    input = input[1:-1]
    if not input:
        return None

    inputValues = [s.strip() for s in input.split(',')]
    root = TreeNode(int(inputValues[0]))
    nodeQueue = [root]
    front = 0
    index = 1
    while index < len(inputValues):
        node = nodeQueue[front]
        front = front + 1

        item = inputValues[index]
        index = index + 1
        if item != "null":
            leftNumber = int(item)
            node.left = TreeNode(leftNumber)
            nodeQueue.append(node.left)

        if index >= len(inputValues):
            break

        item = inputValues[index]
        index = index + 1
        if item != "null":
            rightNumber = int(item)
            node.right = TreeNode(rightNumber)
            nodeQueue.append(node.right)
    return root

tree = stringToTreeNode("[1,1,3,1,1,3,4,3,1,1,1,3,8,4,8,3,3,1,6,2,1]")

sol = Solution()
result = sol.findSecondMinimumValue(tree)
print(result)