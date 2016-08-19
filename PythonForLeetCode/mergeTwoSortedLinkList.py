#!/usr/bin/python3 
# Definition for singly-linked list.
class ListNode(object):
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution(object):
    def mergeTwoLists(self, l1, l2):
        """
        :type l1: ListNode
        :type l2: ListNode
        :rtype: ListNode
        """
        head = ListNode(0)
        tail = head
        index1 = l1
        index2 = l2
        while (not index1 == None) and (not index2 == None):
            curIndex = None
            if index1.val > index2.val:
                curIndex = index2
                index2 = index2.next
            else:
                curIndex = index1
                index1 = index1.next

            temp = curIndex
            temp.next = None
            tail.next = temp
            tail = temp
        if not index1 == None:
            tail.next = index1
        if not index2 == None:
            tail.next = index2
        return head.next

l1 = [1, 2, 3, 56, 56, 78, 98, 99]
l2 = [4, 5, 6, 7, 8, 9, 10]
head1 = None
head2 = None
i = 1
while i <= len(l1):
    newNode = ListNode(l1[-i])
    newNode.next = head1
    head1 = newNode
    i += 1
i = 1
while i <= len(l2):
    newNode = ListNode(l2[-i])
    newNode.next = head2
    head2 = newNode
    i += 1

sol = Solution()
newHead = sol.mergeTwoLists(head1, head2)
while not newHead == None:
    print(newHead.val)
    newHead = newHead.next

newHead = sol.mergeTwoLists(None, None)
while not newHead == None:
    print(newHead.val)
    newHead = newHead.next