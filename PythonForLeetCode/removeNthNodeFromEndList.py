#!/usr/bin/python3
# Definition for singly-linked list.
class ListNode(object):
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution(object):
    def removeNthFromEnd(self, head, n):
        """
        :type head: ListNode
        :type n: int
        :rtype: ListNode
        """
        objNode = None
        counter = -1
        index = head
        while not index == None:
            counter += 1
            if counter == n:
                objNode = head
            elif counter > n:
                objNode = objNode.next
            index = index.next
        if counter == -1:
            return head
        if counter == n - 1:
            temp = head
            head = head.next
            del temp
            return head
        else:
            temp = objNode.next
            objNode.next = objNode.next.next
            del temp
            return head

head = None
for i in range(10):
    temp = ListNode(i)
    temp.next = head
    head = temp

pro = Solution()
head = pro.removeNthFromEnd(head, 9)
head = pro.removeNthFromEnd(head, 9)
head = pro.removeNthFromEnd(head, 1)
head = pro.removeNthFromEnd(head, 2)
head = pro.removeNthFromEnd(head, 3)