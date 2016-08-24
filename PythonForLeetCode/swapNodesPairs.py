#!/usr/bin/python3
# Definition for singly-linked list.
class ListNode(object):
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution(object):
    def swapPairs(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        newHead = ListNode(0)
        tail = newHead
        while not (head == None or head.next == None):
            node1 = head
            node2 = head.next
            head = head.next.next 

            node2.next = node1
            tail.next = node2
            tail = node1
            tail.next = None
        tail.next = head
        return newHead.next

head = None
for i in range(2):
    curNode = ListNode(i)
    curNode.next = head
    head = curNode
sol = Solution()
head = sol.swapPairs(head)

while not head == None:
    print(head.val)
    head = head.next