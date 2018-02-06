# Definition for singly-linked list with a random pointer.
class RandomListNode(object):
    def __init__(self, x):
        self.label = x
        self.next = None
        self.random = None

class Solution(object):
    def copyRandomList(self, head):
        """
        :type head: RandomListNode
        :rtype: RandomListNode
        """
        newList = RandomListNode(-1)
        tail = newList
        dic = {}
        temp = head
        while temp != None:
            newNode = RandomListNode(temp.label)
            dic[id(temp)] = newNode
            
            temp = temp.next
            tail.next = newNode
            tail = newNode
        temp = head
        tail = newList.next
        while temp != None:
            if temp.random != None:
                tail.random = dic[id(temp.random)]
            temp = temp.next
            tail = tail.next
        return newList.next