#!usr/bin/python3
# Definition for singly-linked list.
class ListNode(object):
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution(object):
    def deleteDuplicates(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        if head == None:
            return None
        pre = head
        index = head.next
        while not index == None:
            if index.val == pre.val:
                pre.next = index.next
                del index
                index = pre.next
            else:
                pre = index
                index = index.next
        return head
head = ListNode(0)
numbers = [1, 1, 2, 3, 4, 4, 5, 5, 5, 6, 7, 8, 8, 8, 9, 9, 9]
for i in numbers:
    newNode = ListNode(i)
    newNode.next = head
    head = newNode

    newNode = ListNode(i)
    newNode.next = head
    head = newNode
sol = Solution()
head = sol.deleteDuplicates(head)
while not head == None:
    print(head.val)
    head = head.next

