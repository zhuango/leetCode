class TreeNode(object):
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    def printTree(self, root):
        """
        :type root: TreeNode
        :rtype: List[List[str]]
        """
        count, level = self.getLevelAndCount(root)
        strList = [["" for i in range(count)] for j in range(level)]
        self.writeStr(root, strList, 0, 0, count)
        return strList
    def getLevelAndCount(self, root):
        if root == None:
            return 0, 0
        lCount, lLevel = self.getLevelAndCount(root.left)
        rCount, rLevel = self.getLevelAndCount(root.right)
        return max([lCount, rCount]) * 2 + 1, max([lLevel, rLevel]) + 1
    def writeStr(self, root, strList, level, start, end):
        mid = (start + end) // 2
        if root != None:
            strList[level][mid] = str(root.val)
            self.writeStr(root.left, strList, level + 1, start, mid)
            self.writeStr(root.right, strList, level + 1, mid, end)
        

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

tree = stringToTreeNode("[1,2,3,null,4]")

sol = Solution()
result = sol.printTree(tree)
print(result)