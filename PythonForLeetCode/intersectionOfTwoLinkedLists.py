# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def getIntersectionNode(self, headA, headB):
        """
        :type head1, head1: ListNode
        :rtype: ListNode
        """
        n = 0
        index = headA
        while index != None:
            n += 1
            index = index.next

        m = 0
        index = headB
        while index != None:
            m += 1
            index = index.next

        counter = abs(m - n)
        if m > n:
            index1 = headB
            index2 = headA
        else:
            index1 = headA
            index2 = headB
        while counter > 0:
            index1 = index1.next
            counter -= 1
        while not index1 == index2:
            index1 = index1.next
            index2 = index2.next
        return index1



pro = Solution()
print(pro.getIntersectionNode(None, None))
