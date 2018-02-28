class Solution:
    def findTarget(self, root, k):
        """
        :type root: TreeNode
        :type k: int
        :rtype: bool
        """
        self.sortedNum = []
        self.sorted(root)
        for i in range(len(self.sortedNum)):
            for j in range(i + 1, len(self.sortedNum)):
                vali = self.sortedNum[i]
                valj = self.sortedNum[j]
                if vali + valj == k:
                    return True
                if vali + valj > k:
                    break
        return False
    def sorted(self, root):
        if root == None:
            return
        self.sorted(root.left)
        self.sortedNum.append(root.val)
        self.sorted(root.right)