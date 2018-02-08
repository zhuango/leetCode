# Definition for a binary tree node.
class TreeNode(object):
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


class Solution:
    def widthOfBinaryTree(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        if root == None:
            return 0
        level = 0
        result = 1
        queue = [(root, level)]
        levelStart = 0
        levelEnd = 1
        index = 0
        
        while index < len(queue):
            curTuple = queue[index]
            if curTuple[1] > level:
                level = curTuple[1]
            if curTuple[0].left:
                queue.append((curTuple[0].left, curTuple[1] + 1))
            if curTuple[0].right:
                queue.append((curTuple[0].right, curTuple[1] + 1))
            index += 1

        index = 0
        maxLevel = level
        level = 0
        queue = [(root, level)]
        count = 1
        while index < count:
            curTuple = queue[index]
            if curTuple[0] == None:
                levelEnd += 1
                if curTuple[1] < maxLevel:
                    queue.append((None, curTuple[1] + 1))
                    queue.append((None, curTuple[1] + 1))
                    count += 2
                index += 1
                continue
            if curTuple[1] != level:
                print(levelEnd - levelStart)
                dis = levelEnd - levelStart
                if dis > result:
                    result = diss
                levelEnd += 1
                levelStart = levelEnd
                level += 1
            queue.append((curTuple[0].left, curTuple[1] + 1))
            queue.append((curTuple[0].right, curTuple[1] + 1))
            count += 2
            index += 1
        return result

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

tree = stringToTreeNode("[1,3,2,5,3,null,9]")

sol = Solution()
result = sol.widthOfBinaryTree(tree)
print(result)