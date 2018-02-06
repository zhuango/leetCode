# Definition for singly-linked list.
class ListNode(object):
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution(object):
    def reorderList(self, head):
        """
        :type head: ListNode
        :rtype: void Do not return anything, modify head in-place instead.
        """
        if head == None or head.next == None:
            return
        prev = None
        mid = head
        end = head
        while end != None and end.next != None:
            prev = mid
            mid = mid.next
            end = end.next.next
        
        if end == None:
            pass
        elif end.next == None:
            prev = mid
            mid = mid.next

        prev.next = None

        l1 = head
        l2 = None
        while mid != None:
            temp = mid
            mid = mid.next
            temp.next = l2
            l2 = temp

        while l1 != None and l2 != None:
            temp1 = l1.next
            temp2 = l2.next

            l1.next = l2
            l2.next = temp1

            l2 = temp2
            l1 = temp1

# 1 2 3 -> 1 3 2
# 1 2 3 4 -> 1 4 2 3
def printList(result):
    s = ""
    while result != None:
        s += str(result.val) + " "
        result = result.next
    print(s)

l = None
for i in range(5, 0, -1):
    tempNode = ListNode(i)
    tempNode.next = l
    l = tempNode
printList(l)
sol = Solution()
sol.reorderList(l)
printList(l)
