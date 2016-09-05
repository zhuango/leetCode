#!/usr/bin/python3
# Definition for singly-linked list.
class ListNode(object):
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution(object):
    def removeElements(self, head, val):
        """
        :type head: ListNode
        :type val: int
        :rtype: ListNode
        """
        newhead = ListNode(0)
        newhead.next = head
        prev = newhead
        while not head == None:
            if head.val == val:
                prev.next = head.next
                del head
                head = prev.next
            else:
                prev = prev.next
                head = head.next
        return newhead.next

l = [3, 3, 4]
head = None
for item in l:
    temp = ListNode(item)
    temp.next = head
    head = temp
pro = Solution()
head = pro.removeElements(head,3)
while not head == None:
    print(head.val)
    head = head.next


