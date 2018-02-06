# Definition for singly-linked list.
class ListNode(object):
    def __init__(self, x):
        self.val = x
        self.next = None

# Definition for a binary tree node.
class TreeNode(object):
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution(object):
    def sortedListToBST(self, head):
        """
        :type head: ListNode
        :rtype: TreeNode
        """
        if head == None:
            return None
        if head.next == None:
            return TreeNode(head.val)
        prev = None
        mid = head
        end = head
        while end != None and end.next != None:
            prev = mid
            mid = mid.next
            end = end.next.next
        prev.next = None

        root = TreeNode(mid.val)
        root.left = self.sortedListToBST(head)
        root.right = self.sortedListToBST(mid.next)
        return root

l = None
for i in reversed([-10,-3,0,5,9]):
    tempNode = ListNode(i)
    tempNode.next = l
    l = tempNode

sol = Solution()
result = sol.sortedListToBST(l)
print(result)