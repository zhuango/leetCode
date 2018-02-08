# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    def longestUnivaluePath(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        self.result = 0
        self.dfs(root, 0)
        return self.result
    def dfs(self, root, length):
        if root == None:
            return 0
        leftL = 0
        if root.left != None:
            if root.left.val == root.val:
                if length + 1 > self.result:
                    self.result = length + 1
                leftL = 1 + self.dfs(root.left, length + 1)
            else:
                self.dfs(root.left, 0)
        rightL = 0
        if root.right != None:
            if root.right.val == root.val:
                if length + 1 > self.result:
                    self.result = length + 1
                rightL = 1 + self.dfs(root.right, length + 1)
            else:
                self.dfs(root.right, 0)
        if root.left != None and root.right != None:
            if leftL + rightL > self.result:
                self.result = leftL + rightL
        return max([leftL, rightL])

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

tree = stringToTreeNode("[4, 1, 1, 1, 1, 1, 1, 1, 1]")
print(tree)

sol = Solution()
result = sol.longestUnivaluePath(tree)
print(result)