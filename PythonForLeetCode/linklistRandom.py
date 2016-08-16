class Solution(object):

    def __init__(self, head):
        """
        @param head The linked list's head. Note that the head is guanranteed to be not null, so it contains at least one node.
        :type head: ListNode
        """
        self.head = head
    
    def getRandom(self):
        """
        Returns a random node's value.
        :rtype: int
        """
        import random
        res = -1
        len = 0
        head = self.head
        while head:
            if random.randint(0,len) == 0:
                res = head.val
            head = head.next
            len += 1
        return res



# Your Solution object will be instantiated and called as such:
class LinkList:
    def __init__(self, val = 0):
        self.next = None
        self.val = val
head = LinkList(1)
head.next = LinkList(2)
head.next.next = LinkList(3)

obj = Solution(head)
param_1 = obj.getRandom()
print(param_1)