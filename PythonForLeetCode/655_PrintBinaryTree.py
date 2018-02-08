class Solution:
    def printTree(self, root):
        """
        :type root: TreeNode
        :rtype: List[List[str]]
        """
        lllleft = root
        rrright = root
        lCount = 1
        rCount = 1
        while lllleft != None:
            lllleft = lllleft.left
            lCount *= 2
        while rrright != None:
            rrright = rrright.right
            rCount *= 2
        count = max([rCount, lCount])
        count = count * 2 + 1

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

tree = stringToTreeNode("[1,5,8,9,7,7,8,1]")

sol = Solution()
result = sol.widthOfBinaryTree(tree)
print(result)