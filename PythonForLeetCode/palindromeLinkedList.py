#!/usr/bin/python3
# Definition for singly-linked list.
class ListNode(object):
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution(object):
    def isPalindrome(self, head):
        """
        :type head: ListNode
        :rtype: bool
        """
        len1 = 0
        len2 = 1
        partlist = None
        list1 = head
        list2 = head
        while (not list2 == None) and (not list2.next == None):
            list2 = list2.next.next
            len2 += 2

            temp = list1
            list1 = list1.next
            temp.next = partlist
            partlist = temp
            len1 += 1
        if list2 == None: len2 -= 1
        len2 = len2 - len1
        if len1 < len2:
            list1 = list1.next
        while (not partlist == None) and (not list1 == None):
            if partlist.val != list1.val:
                return False
            partlist = partlist.next
            list1 = list1.next
        return True
l = [1, 1]
head = None
for item in l:
    temp = ListNode(item)
    temp.next = head
    head = temp
pro = Solution()
print(pro.isPalindrome(head))